#include <Servo.h>
Servo myservo;
//#include "Counter.h"
//#include "Button.h"

class ServoR{
  private:
  //Button pins
  int BUTTON_PIN = 5;
  int SERVO_PIN = 9;
  //Variables
  int angle = 90;
  int lastButtonState = 0;
  int buttonPushCounter = 0;
  
  public:
  void init();
  void run();
  void push();
};

void ServoR::init(){
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myservo.attach(SERVO_PIN);
  myservo.write(angle);
}

void ServoR::run(){
  // put your main code here, to run repeatedly:
  angle = digitalRead(BUTTON_PIN);
  if(angle != lastButtonState)
  {
      if(angle == HIGH)
      {
        //buttonPushCounter++;
        Serial.println("on");  
      }
      else
      {
        Serial.println("off"); 
      }
      delay(100);
  }
  lastButtonState = angle;
  if(buttonPushCounter %2 == 0)
  {
    push();  
  }
}

void ServoR::push(){
  myservo.write(90);
  delay(300);
  myservo.write(0);
}
