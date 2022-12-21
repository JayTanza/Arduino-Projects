#include <Servo.h>

Servo myservo;

int BUTTON_PIN = 5;
int SERVO_PIN = 9;

int angle = 90;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  myservo.attach(SERVO_PIN);
  myservo.write(angle);
}

void loop() {
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

void push()
{
  myservo.write(90);
  delay(300);
  myservo.write(0);   
}
