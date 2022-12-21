#include<Servo.h>
Servo Myservo;
int pos=0;
void setup()
{
  Serial.begin(9600);
  pinMode(A1,INPUT_PULLUP);
  Myservo.attach(11);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

void loop()
{ 
  if(digitalRead(A1)==LOW)
  {  
    Myservo.write(0);
    delay(1000);
    Myservo.write(45);
    delay(1000);
    Myservo.write(0);
    Serial.print("Yey!");

  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  delay(1000); 
  }
}
