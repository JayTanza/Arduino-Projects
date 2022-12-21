#include<Servo.h>
Servo motor;
int p=0;
void setup() {
  // put your setup code here, to run once:
  motor.attach(9);
  motor.write(90); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(p=0; p<180; p++)
  {
   motor.write(p);
   delay(5);  
  }

  for(p=180; p>=1; p--)
  {
   motor.write(p);
   delay(5);  
  }
}
