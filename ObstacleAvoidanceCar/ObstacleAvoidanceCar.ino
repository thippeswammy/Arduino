#include <AFMotor.h> 
#define echoPin 9 
#define trigPin 10 
// Initialise the four motors
AF_DCMotor front_left(1, MOTOR12_64KHZ);
AF_DCMotor rear_left(2, MOTOR12_64KHZ);
AF_DCMotor front_right(3, MOTOR12_64KHZ);
AF_DCMotor rear_right(4, MOTOR12_64KHZ);
int count=1;
int Direction=1;
int distance=0;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("started=>");
  delay(3000);
}

void loop() {
  digitalWrite(trigPin, LOW);l̥
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  
  distance = (duration - 10 ) * 0.034 / 2;
  // distance=100;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  Serial.print("count: ");
  Serial.println(count);
  
  if(distance < 10 && Direction==1){
    Direction = -1;
    front_left.setSpeed(0);
    rear_left.setSpeed(0);
    front_right.setSpeed(0);
    rear_right.setSpeed(0);
    delay(2000);
  }
  if(count<=1 && Direction==-1){
    Direction=0;
  }
  if (Direction==1){
    front_left.setSpeed(255);
    rear_left.setSpeed(255);
    front_right.setSpeed(255);
    rear_right.setSpeed(255);
    front_left.run(FORWARD);       
    rear_left.run(FORWARD);  
    front_right.run(FORWARD);       
    rear_right.run(FORWARD);  
    count=count+1;
  }
  if (Direction==-1){
    front_left.setSpeed(255);
    rear_left.setSpeed(255);
    front_right.setSpeed(255);
    rear_right.setSpeed(255);
    front_left.run(BACKWARD);     
    rear_left.run(BACKWARD); 
    front_right.run(BACKWARD);  
    rear_right.run(BACKWARD);  
    count=count-1;
  } 
  if (Direction==0){
    front_left.run(RELEASE);     
    rear_left.run(RELEASE); 
    front_right.run(RELEASE);  
    rear_right.run(RELEASE);
    
    count=1;
    Direction=1;
    distance=0;
    delay(5000);
  }
  
}