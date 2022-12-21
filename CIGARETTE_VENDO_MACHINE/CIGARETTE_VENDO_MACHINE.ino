#include "Common.h"

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  initAll();
  pinMode(coinpin,INPUT_PULLUP);
  attachInterrupt(0,coinInserted,FALLING);  
  Display_Home();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  b1.pushRED(onPushRED,offPush);
  b1.pushGREEN(onPushGREEN,offPush);
  b1.pushYELLOW(onPushYELLOW,offPush);

  //Display_Home();
  Display_Main();
}

void onPushRED()
{  
  if(coins >= 5)
  {
    module.red();
    s1.move();
    coins = coins - 5;
  }
}

void onPushGREEN()
{
  if(coins >= 10)
  {
    module.green();
    s2.move();
    coins = coins - 10;
  }
  
}
void onPushYELLOW()
{ 
  if(coins >= 15)
  {
    module.yellow();
    s1.move();
    coins = coins - 15;
  }
}

void offPush()
{
  module.off();
}
