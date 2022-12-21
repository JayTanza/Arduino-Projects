#include "Common.h"

int coins = 0;
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
char mystr[10];
bool isDone = true;

void setup(){
  Serial.begin(9600);
  Serial.setTimeout(100);
  initAll();
}

void loop(){
  if (Serial.available()>0){
    String cmd= Serial.readString();
    cmd.trim();
    coins = cmd.toInt();
    isDone = false;
  }
  module1.run(onClick);
  module2.run(onClick);
  module3.run(onClick);
  module4.run(onClick);
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
    case 4: modulex = module4;
    break;   
  }

  if(coins >= aPrice)
  {
    coins = coins - aPrice;
    c20++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(coins);
    Serial.print(", counter20=");
    Serial.println(c20);
  }
  else if(coins >= aPrice)
  {
    coins = coins - aPrice;
    c10++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(coins);
    Serial.print(", counter10=");
    Serial.println(c10);
  }
  else if(coins >= aPrice)
  {
    coins = coins - aPrice;
    c5++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial .print(coins);
    Serial.print(", counter5=");
    Serial.println(c5);
  }
  else if(coins >= aPrice)
  {
    coins = coins - aPrice;
    c1++;
    modulex.Servomove1();
    Serial.print("cash=");
    Serial.print(coins);
    Serial.print(", counter1=");
    Serial.println(c1);
  }
  /*if(coins < aPrice)
  {
    Display_InsertCoin();
  }*/
  if(coins == 0 && !isDone){
    delay(1000);
    Serial.println("done");
    isDone = true;
  }
}
