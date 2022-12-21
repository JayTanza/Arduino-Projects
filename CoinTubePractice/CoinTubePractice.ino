#include "Servo.h"

const int PIN_STATE_S1 = 2; //Switch sa DIP
const int PIN_STATE_S2 = 3; 
const int PIN_STATE_S3 = 4;
const int PIN_SERVO_1 = 9;

Servo myservo; 
int position=0; //position sa servo
int count=0; 
int runTimes=0; //kapila ang servo motion
bool isMove = true; //condition kung x5 na ni move ang servo, mo stop. 

void setup(){
  Serial.begin(9600);
  pinMode(PIN_STATE_S1, INPUT_PULLUP);
  pinMode(PIN_STATE_S2, INPUT_PULLUP);
  pinMode(PIN_STATE_S3, INPUT_PULLUP);
  pinMode(PIN_SERVO_1, OUTPUT);

  myservo.attach(PIN_SERVO_1);
}

void loop()
{
 for(runTimes = 0; runTimes < 5; runTimes++){    //
   for(position = 0; position <= 80; position++){ 
     myservo.write(position);
     Serial.println("up");
     delay(5);
   }

   for(position = 80; position >= 0; position--){                 //
     myservo.write(position);
     Serial.println("down");
     delay(5);
   }

   if(runTimes == 5){
      Serial.print("stop");
      break;
   }
 }
}
