#include <Wire.h>
#include <Servo.h>

Servo myservo;

int Position;
char stateChange;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(11);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    Position = Serial.read();
    Position = map(Position, 0,180,180,0);
    myservo.write(Position);
  }
}
