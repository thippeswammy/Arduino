const int trigPin1 = 0+2;
const int echoPin1 = 1+2;
const int trigPin2 = 2+2;
const int echoPin2 = 3+2;
const int light = 4+2;
bool onB=false;
int distance=100;
int numberOfAnimal=0;
// defines variables
long duration;
int distance1;
int distance2;
void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

  pinMode(light,OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  if(!onB){
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin1, HIGH);
    // Calculating the distance
    distance1 = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance1: ");
    Serial.print(distance1);
    distance2=300;
    if(distance1<=distance){
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin2, HIGH);
      // Calculating the distance
      distance2 = duration * 0.034 / 2;
      Serial.print("     Distance2: ");
      Serial.println(distance2);
      if(distance2<=distance){
        onB=true;
        //Serial.println("INSIDE");
      }
    }
  }
  else
  {
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin2, HIGH);
    // Calculating the distance
    distance1 = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance11: ");
    Serial.println(distance1);
    distance2=300;
    if(!(distance1<=distance)){
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin1, HIGH);
      // Calculating the distance
      distance2 = duration * 0.034 / 2;
      if(distance2<=distance){
        onB=false;
        //Serial.println("OUTSIDE");
      }
    }
  }
  if(onB==true||distance1<=distance||distance2<=distance){
    digitalWrite(light, HIGH);
    Serial.print("   ON");
  }else{
    digitalWrite(light, LOW);
    Serial.print("   OFF");
  }
  if(onB){
   Serial.println("   INSIDE"); 
  }else{
   Serial.println("   OUTSIDE");
  }
  
}