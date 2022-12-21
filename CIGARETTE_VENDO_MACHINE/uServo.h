#include <Servo.h> //Servo Library
#include <Wire.h> //Wire Library

class TServo
{
  private:
  int _servopin = 11;
  
  
  Servo myservo;
  
  public:
  void init(int servopin);
  void move();
};

void TServo::init(int servopin)
{
  _servopin = servopin;

  myservo.attach(_servopin);
  pinMode(_servopin,INPUT_PULLUP);
}

void TServo::move()
{
  myservo.write(0);
  delay(300);
  myservo.write(90);
}
