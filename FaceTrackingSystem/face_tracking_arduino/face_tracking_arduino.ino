
#include <Servo.h>
Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo
int x;
int y;
int prevX;
int prevY;
void setup()
{
  Serial.begin(9600);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  servoVer.attach(9); //Attach Vertical Servo to Pin 5
  servoHor.attach(10); //Attach Horizontal Servo to Pin 6
  servoVer.write(90);
  servoHor.write(90);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
}

void Pos()
{
  
  
  //delay(50);
  //digitalWrite(2, LOW);
  //delay(50);
  if(prevX != x || prevY != y)
  {
    //digitalWrite(2, HIGH);

    int servoX = map(x, 600, 0, 70, 179);
    int servoY = map(y, 450, 0, 179, 95);
    servoX = min(servoX, 179);
    servoX = max(servoX, 70);
    servoY = min(servoY, 179);
    servoY = max(servoY, 95);

    if(x<300){
      //digitalWrite(0, HIGH);
    }else{
      digitalWrite(0, LOW);
    }

    if(y<225){
      //digitalWrite(1, HIGH);
    }else{
      digitalWrite(1, LOW);
    }
    
    //delay(1000);
    //digitalWrite(2, LOW);
    servoHor.write(servoX);
    delay(500);
    servoVer.write(servoY);
    delay(500);
    Serial.print("Thipp");
  }
}
void loop()
{
  //digitalWrite(3, HIGH);
  delay(500);
  //digitalWrite(3, LOW);
  delay(500);
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
       Pos();
      }
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
