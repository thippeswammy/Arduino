
void setup() {
  // put your setup code here, to run once:
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);

    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);

    digitalWrite(D5,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D7,HIGH);

    delay(5000);

    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);

    digitalWrite(D5,LOW);
    digitalWrite(D6,HIGH);
    digitalWrite(D7,LOW);

    delay(1000);

    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);

    digitalWrite(D5,HIGH);
    digitalWrite(D6,LOW);
    digitalWrite(D7,LOW);

    delay(5000);
}
