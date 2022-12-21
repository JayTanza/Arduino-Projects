#include <Servo.h>
Servo myservo;
#include "Buttons.h"
TButtons b1;

class TServo{
  private:
  int servopin = 9;
  int buttonpin = 5;
  int angle = 90;

  public:
  void init();
  void run(void onPushBtn());
  void push();
  void Notpush();
  bool enable = false;
};

class TServo::run(void onPushBtn()){
  b1.init();
  if(!enable)
  return;
  if (digitalRead(b1.buttonpin1) == LOW ||digitalRead(b1.buttonpin2) == LOW || digitalRead(b3.buttonpin1) == LOW ||){
     delay(600);
     push();
     onPushBtn();     
  } 
    else
  {    
     Notpush();
     return false;
  }  
}
void TServo::push(){
  myservo.write(0);
  delay(300);
  myservo.write(90);
}

void TServo::Notpush(){
   myservo.write(90);
}
