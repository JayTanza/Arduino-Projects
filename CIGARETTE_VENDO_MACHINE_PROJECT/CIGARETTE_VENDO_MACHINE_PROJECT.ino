#include "Common.h"

unsigned int SelectedPrice = 0;
byte SelectedID = 0;
bool isEmpty = true;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  initAll();
  pinMode(coinpin,INPUT_PULLUP);
  attachInterrupt(0,coinInserted,FALLING);
}

void loop() 
{ 
  Display_Main();
  
  module_1.run(onClick);
  module_2.run(onClick);
  module_3.run(onClick);

  module_1.LED(onLight);
  module_2.LED(onLight);
  module_3.LED(onLight);
  module_4.Sensor();
}

void onClick(byte aID, unsigned aPrice)
{
  SelectedPrice = aPrice;
  SelectedID = aID;
  
  switch(SelectedID)
  {
    case 1: modulex = module_1;
    break;  
    case 2: modulex = module_2;
    break; 
    case 3: modulex = module_3;
    break; 
  }
  
  if(coins >= aPrice)
  {   
    modulex.Servomove();
    coins = coins - aPrice;
  }

  if(coins < aPrice)
  {
    Display_InsertCoin();
  }
  
  Serial.println(aPrice); 
}

void onLight(byte aID, unsigned aPrice)
{  
  SelectedPrice = aPrice;
  SelectedID = aID;

  switch(SelectedID)
  {
    case 1: modulez = module_1;
    break;  
    case 2: modulez = module_2;
    break; 
    case 3: modulez = module_3;
    break; 
  }
  if(coins >= aPrice)
  {
    modulez.ledon();
  }
  else
  {
    modulez.ledoff();
  }
  Serial.println(aPrice);
}
