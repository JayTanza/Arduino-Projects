#include "Common.h"

unsigned int SelectedPrice = 0;
byte SelectedID = 0;

//credit counter
int c20=0;
int c10=0;
int c5=0;
int c1=0;
//inputted cash 
int cash = 10; 

//Receiver
int LED = 13;
char message;

void setup() 
{
  Serial.begin(9600);
  initAll();
  //pinMode(LED,OUTPUT);
  //pinMode(coinpin,INPUT_PULLUP);
  //attachInterrupt(0,coinInserted,FALLING);
}

void loop() 
{
  module1.run(onClick);
  module2.run(onClick);
  module3.run(onClick);
  if(Serial.available())
  {
    message = Serial.read();
    if(message == '1')
    {
      digitalWrite(LED,1);
    }
  }
  delay(20); // waiting message receiver
  digitalWrite(LED,0);
}

void onClick(byte aID, unsigned aPrice)
{
  SelectedPrice = aPrice;
  SelectedID = aID;

  switch(SelectedID)
  {
    case 1: modulex = module1;
    break;
    case 2: modulex = module2;
    break;     
    case 3: modulex = module3;
    break;  
  }

  if(cash >= aPrice)
  {
    cash = cash - aPrice;
    c10++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter20=");
    Serial.println(c10);
  }
  else if(cash >= aPrice)
  {
    cash = cash - aPrice;
    c5++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter10=");
    Serial.println(c5);
  }
  else if(cash >= aPrice)
  {
    cash = cash - aPrice;
    c1++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(cash);
    Serial.print(", counter10=");
    Serial.println(c1);
  }
  
  /*if(coins < aPrice)
  {
    Display_InsertCoin();
  }*/
}
