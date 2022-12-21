#include <Servo.h>
#include <Wire.h>

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
  myservo.write(0);
}

void TServo::move()
{
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
}
