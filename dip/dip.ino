#include <Servo.h>

Servo myservo;  

int pos = 0; 
int count = 0;   
int sweep = 0;
int price=10; 
int cash=17; 
int rem_credit = 0;

#define S1 2
#define S2 3
#define S3 4

int PIN1_SENSOR = HIGH;
int PIN2_SENSOR = HIGH;
int PIN3_SENSOR = HIGH;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  rem_credit = cash - price; 
}

void loop() 
{
  PIN1_SENSOR = digitalRead(S1);
  PIN2_SENSOR = digitalRead(S2);
  PIN3_SENSOR = digitalRead(S3);

  if (Serial.available() > 0)
  {
    String cmd = Serial.readString();
    cmd.trim();
    rem_credit = cmd.toInt(); 
  }
  
  if (PIN1_SENSOR == LOW) 
  { 
    if (rem_credit > 0)
    {
      onSensor1(rem_credit);
      rem_credit = 0;
    }
  }

  if (PIN2_SENSOR == LOW) 
  { 
    if (rem_credit >= 5)
    {
      onSensor2(rem_credit);
      rem_credit = 0;
    }
  }

  if (PIN3_SENSOR == LOW) 
  { 
    if (rem_credit >= 10)
    {
      onSensor3(rem_credit);
      rem_credit = 0;
    }
  }
}

void onSensor1(int aValue)
{    
  for (int sweep = 0; sweep < aValue; sweep++) 
  {   
      for (pos = 0; pos <= 90; pos++) 
      {                                   
        myservo.write(pos);             
        delay(5);
      }
      for(pos = 90; pos>=0; pos--)     
      {                               
        myservo.write(pos);              
        delay(5);
      }                
  }  
}

void onSensor2(int bValue)
{     
  for (int sweep = 0; sweep < bValue; sweep++) 
  {   
    myservo.write(90);
    delay(500);
    myservo.write(0);
    delay(500);              
  }
}

void onSensor3(int cValue)
{    
  for (int sweep = 0; sweep < cValue; sweep++) 
  {   
    myservo.write(90);
    delay(500);
    myservo.write(0);
    delay(500);               
  }
}
