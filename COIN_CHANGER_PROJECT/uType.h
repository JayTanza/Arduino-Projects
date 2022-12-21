#include <Servo.h>
#include <Wire.h>

class TType
{
  private:
  int PIN_SWITCH_1 = 2;
  int PIN_SERVO_1 = 8;
  
  int PIN_BTN_1 = 8;
  int price= 0; 
  byte ID = 0;
  
  Servo myservo, myservo2, myservo3, myservo4;
  public:
  void init(int aServo, int aID, int aPrice);
  void run(void onClick(byte aID));
  void onSwitch(int aValue);
  void onSwitch2(int aValue);
  void onSwitch3(int aValue);
  void onSwitch4(int aValue);
};

void TType::init(int aServo, int aID, int aPrice)
{
  //PIN_SWITCH_1 = aPin;
  PIN_SERVO_1 = aServo;
  //PIN_BTN_1 = aBtn;
  ID = aID;
  price = aPrice;
  Serial.begin(9600);
  myservo.attach(PIN_SERVO_1);
  pinMode(PIN_SWITCH_1, INPUT_PULLUP);
}

void TType::run(void onClick(byte aID))
{   
   onClick(ID);
   delay(10);   
}

void TType::onSwitch(int aValue)
{
    for (int sweep = 0; sweep < aValue; sweep++) 
    {   
      myservo.write(0);
      delay(1000);
      myservo.write(180);
      delay(1000);
      myservo.write(0);            
    }  
}

void TType::onSwitch2(int aValue)
{
    for (int sweep = 0; sweep < 1; sweep++) 
    {   
      myservo2.write(0);
      delay(1000);
      myservo2.write(180);
      delay(1000);
      myservo2.write(0);            
    }  
}

void TType::onSwitch3(int aValue)
{
    for (int sweep = 0; sweep < 1; sweep++) 
    {   
      myservo3.write(0);
      delay(1000);
      myservo3.write(180);
      delay(1000);
      myservo3.write(0);            
    }  
}

void TType::onSwitch4(int aValue)
{
    for (int sweep = 0; sweep < 1; sweep++) 
    {   
      myservo4.write(0);
      delay(1000);
      myservo4.write(180);
      delay(1000);
      myservo4.write(0);            
    }  
}
