#include "Servo.h"

Servo myservo; 

const int SW1 = 2;
const int PIN_SERVO = 12;
int rem_credit=0;
int price=10; 
int cash=13; 

void change(int aValue){
  for (int i = 0; i < aValue; i++){
    myservo.write(0);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(PIN_SERVO, INPUT_PULLUP);
  myservo.attach(PIN_SERVO);
  rem_credit = cash - price; 

}

void loop()
{ 
  if (Serial.available() > 0){
    String cmd = Serial.readString();
    cmd.trim();
    rem_credit = cmd.toInt(); 
  }
  if (digitalRead(SW1) == LOW) 
  { 
    if (rem_credit >= 5)
    {
      change(rem_credit);
      rem_credit = 0;
    }
  }
}
