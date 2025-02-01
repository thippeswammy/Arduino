#include <Servo.h>

// Define the servo motor
Servo servoMotor;

// Define the pin to which the servo is connected
int servoPin = 9;

void setup() {
  // Attach the servo to the specified pin
  servoMotor.attach(servoPin);
}

void loop() {
  // Rotate the servo motor to 0 degrees (minimum position)
  servoMotor.write(0);
  delay(2); // Wait for 1 second

  // Rotate the servo motor to 180 degrees (maximum position)
  servoMotor.write(180);
  delay(2); // Wait for 1 second
}
