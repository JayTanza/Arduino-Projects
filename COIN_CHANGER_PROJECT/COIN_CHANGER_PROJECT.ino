#include <Servo.h>
#include "Common.h"

byte SelectedID = 0;

unsigned int SelectedPrice = 0;
//credit counter
int c20=0;
int c10=0;
int c5=0;
int c1=0;
//inputted cash 
int cash = 25; 

void setup() 
{
  Serial.begin(9600);
  initAll();
}

void onClick(byte aID)
{
  SelectedID = aID;
  
  switch(SelectedID)
  {
    case 1: modulex = module1;
    break;  
    case 2: modulex = module2;
    break;
    case 3: modulex = module3;
    break;
    case 4: modulex = module4;
    break;
  }
   
  if(cash >= 20)
  {
    cash = cash - 20;
    c20++;
    modulex.onSwitch(c20);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter20=");
    Serial.println(c20);
  }
  else if(cash >= 10)
  {
    cash = cash - 10;
    c10++;
    modulex.onSwitch2(c10);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter10=");
    Serial.println(c10);
  }
  else if(cash >= 5)
  {
    cash = cash - 5;
    c5++;
    modulex.onSwitch3(c5);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter5=");
    Serial.println(c5);
  }
  else if(cash >= 1)
  {
    cash = cash - 1;
    c1++;
    modulex.onSwitch4(c1);
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter1=");
    Serial.println(c1);
  }
}

void loop() 
{
  module1.run(onClick);
  module2.run(onClick);
  module3.run(onClick);
  module4.run(onClick);
}
