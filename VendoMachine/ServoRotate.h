#include <Servo.h>
Servo myservo;
//#include "Buttons.h"
//TButton b1;

class TServo{
  private:
  int servopin = 9;
  int buttonpin = 5;
  int buttonpin2 = 6;
  int buttonpin3 = 7;
  int angle = 90;
  
  public:
  bool enable = false;
  void init();
  void run(void onPushBtn());
  void push();
  void push2();
  void push3();
  //void Notpush();
};

void TServo::init(){
    pinMode(buttonpin, INPUT_PULLUP);
    myservo.attach(servopin);
    myservo.write(angle);
}

void TServo::run(void onPushBtn()){ 
  if (!enable)
  return;
  if (digitalRead(buttonpin) == LOW){
     delay(600);
     push();
     onPushBtn();     
  }  
  else if (digitalRead(buttonpin2) == LOW){
     delay(600);
     push2();
     onPushBtn();     
  }  
  else if (digitalRead(buttonpin3) == LOW){
     delay(600);
     push3();
     onPushBtn();     
  } 
}
void TServo::push(){
  myservo.write(0);
  delay(300);
  myservo.write(90);
}

void TServo::push2(){
   myservo.write(0);
   delay(300);
   myservo.write(90);
}

void TServo::push3(){
   myservo.write(0);
   delay(300);
   myservo.write(90);
}
