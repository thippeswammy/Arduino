#include <mcp_can.h>
#include <SPI.h>

MCP_CAN CAN0(10);     // Set CS to pin 10
unsigned char len = 0;
unsigned char rxBuf[8];  // Buffer to hold received CAN data
unsigned long rxId;      // Variable to store received CAN ID
int pin_num = 53;        // Pin number for LED

void setup()
{
  Serial.begin(115200);
  
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s
  if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) 
    Serial.println("MCP2515 Initialized Successfully!");
  else 
    Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
  pinMode(pin_num, OUTPUT);   // Set the LED pin as an output
}

byte data1[8] = {0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};  // Data: 00660000000000

void loop()
{
  // Send data to ID 12280797 (0xBA0005D)
  unsigned long canId = 0x12910109; // Message ID
  byte sndStat1 = CAN0.sendMsgBuf(canId, 0, 8, data1);  // ID: 12910109, Data: 00660000000000
  Serial.print("sndStat1=");
  Serial.println(sndStat1);
  if (sndStat1 == CAN_OK) {
    Serial.println("Message to ID 12910109 Sent Successfully!");
  } else {
    Serial.println("Error Sending Message to ID 12910109...");
    digitalWrite(pin_num, HIGH);  // Turn on LED for error
    delay(1000);
    digitalWrite(pin_num, LOW);   // Turn off LED after delay
  }

  Check if any CAN message is received
  if (CAN0.checkReceive() == CAN_MSGAVAIL)  // If a CAN message is available
  {
    // Update the function call to match the library's expected signature
    byte ext;
    CAN0.readMsgBuf(&rxId, &len, rxBuf);    // Read the message and ID
    
    Serial.print("Received message with ID: 0x");
    Serial.println(rxId, HEX);
    
    // Compare received message's data or ID to trigger LED
    if (rxId == 12910109) {                    // Trigger only for ID 12910109
      digitalWrite(pin_num, HIGH);           // Turn on LED if specific message is received
      delay(1000);                
      Serial.println("Received message triggered LED ON!");
    }
  }
  digitalWrite(pin_num, LOW);
  
  delay(100);   // Send and check messages every 100ms
}
