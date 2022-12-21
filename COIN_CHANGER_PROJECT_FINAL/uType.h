#include <Servo.h>
#include <Wire.h>

class TType
{
  private:
  int PIN_SERVO = 8;
  
  int PIN_SENSOR = A0;

  byte ID = 0;

  unsigned int Price = 0;
  
  Servo myservo;
  
  public:
  void init(int aServo, int aSensor, byte aID, unsigned int aPrice);
  void run(void onClick(byte aID, unsigned aPrice));
  void Servomove1();
};

void TType::init(int aServo, int aSensor, byte aID, unsigned int aPrice)
{
  PIN_SERVO = aServo;
  PIN_SENSOR = aSensor;
  ID = aID;
  Price = aPrice;

  myservo.attach(PIN_SERVO);
  pinMode(PIN_SENSOR, INPUT);
}

void TType::run(void onClick(byte aID, unsigned aPrice))
{
    if(digitalRead(PIN_SENSOR) == LOW)
    {
      onClick(ID,Price);
      delay(10); 
    }
}

void TType::Servomove1()
{
    myservo.write(0);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
}
