#include "Common.h"

unsigned int SelectedPrice = 0;//uint means start from 0 for selectedprice
byte SelectedID = 0;//variable for SelectedID
unsigned int Coininserted = 0; 
unsigned int CoinSum = 0;
int PIN_COIN = 2;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dspWelcome();
  pinMode(PIN_COIN,INPUT_PULLUP); // Function for Button pin 
  initAll();//call the initFunction in Common class 
  attachInterrupt(0,dspUpdate,FALLING);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  module1.run(onClick); 
  //onPushBtn(aCoinSum);
}

void onClick(byte aID, unsigned aPrice)
{
  //this method is to click with parameter ID and Price
  SelectedPrice = aPrice; // price with assign aPrice parameter
  SelectedID = aID; // price with assign aID parameter
  switch(SelectedID)
  {
    case 1: module = module1; //module is equal to module1
    break;  
  }
  /*if(Coins >= SelectedPrice){
    SelectedID = 0;
    SelectedPrice = 0;
    module.move();
  }*/
  module.move(); //module1 is assign to move method
  Serial.println(aPrice); //print and display the price every button clicks
}
