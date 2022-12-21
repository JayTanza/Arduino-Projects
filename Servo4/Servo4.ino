//sketch created by Akshay Joseph follow me on Instagra: five_volt_player

#include<Servo.h>
Servo Myservo;
int pos=0;
void setup()
{
  Serial.begin(9600);
  pinMode(A1,INPUT_PULLUP);
  Myservo.attach(11);
}

void loop()
{
  //if(digitalRead(A1)==LOW){
    Myservo.write(180);
    delay(1000);
    Myservo.write(0);
    delay(1000);
    Myservo.write(180);
    Serial.println("Yey!");
  //}
}
