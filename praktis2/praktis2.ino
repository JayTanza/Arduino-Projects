#include <Servo.h>

Servo myservo;

int value = 0;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  onServo();
}

void loop() 
{
}

void onServo()
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    String cmd = Serial.readString();
    cmd.trim();
    value = cmd.toInt(); 
  }
  if(value > 0)
  {
    servoMove(value);
  }
}
void servoMove(int aValue)
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
