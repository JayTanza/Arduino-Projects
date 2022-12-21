#include "Servo.h"

Servo servo1, servo2, servo3, servo4;

//credit counter
int c20=0;
int c10=0;
int c5=0;
int c1=0;
//inputted cash 
int cash = 20; 

//servo pins             
const int PIN_SERVO1 = 8;   //20
const int PIN_SERVO2 = 9;   //10
const int PIN_SERVO3 = 10;  //5
const int PIN_SERVO4 = 11;  //1
int PIN_SENSOR = A0;
void servoMotion1(int aValue)
{ //ang parameter ani kay ang cash
  for(int i=0; i < aValue; i++){
    servo1.write(0);
    delay(1000);
    servo1.write(180);
    delay(1000);
    servo1.write(0);
  }
}
void servoMotion2(int aValue){ //ang parameter ani kay ang cash
  for(int i=0; i < aValue; i++){
    servo2.write(0);
    delay(1000);
    servo2.write(180);
    delay(1000);
    servo2.write(0);
  }
}
void servoMotion3(int aValue){ //ang parameter ani kay ang cash
  for(int i=0; i < aValue; i++){
    servo3.write(0);
    delay(1000);
    servo3.write(180);
    delay(1000);
    servo3.write(0);
  }
}
void servoMotion4(int aValue){ //ang parameter ani kay ang cash
  for(int i=0; i < aValue; i++){
    servo4.write(0);
    delay(1000);
    servo4.write(180);
    delay(1000);
    servo4.write(0);
  }
}

void setup() {
  Serial.begin(9600);
  servo1.attach(PIN_SERVO1);  //20
  servo2.attach(PIN_SERVO2);  //10
  servo3.attach(PIN_SERVO3);  //5
  servo4.attach(PIN_SERVO4);  //1
  pinMode(PIN_SENSOR, INPUT);
}

void loop() {
  if(cash >= 20)
  {
    cash = cash - 20;
    c20++;
    servoMotion1(c20);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter20=");
    Serial.println(c20);
  }
  
  else if(cash  >= 10){
    cash = cash - 10;
    c10++;
    servoMotion2(c10);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter10=");
    Serial.println(c10);
  }
  else if(cash >= 5){
    cash = cash - 5;
    c5++;
    servoMotion3(c5);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter5=");
    Serial.println(c5);
  }
  else if(cash > 1){
    cash = cash - 1;
    c1++;
    servoMotion4(c1);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter1=");
    Serial.println(c1);
  }
}
