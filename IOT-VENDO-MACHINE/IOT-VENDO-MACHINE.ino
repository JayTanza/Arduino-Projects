#include "Common.h"

unsigned int SelectedPrice = 0;
byte SelectedID = 0;
unsigned int aChange = 0;
bool isEmpty = true;
bool isRelayOn = false;
bool isDone = true;
int buzzerPin = 3; 
//defining button to pin 7
#define PIN_TYPE_BTN_1 12

//credit counter
int c10=0;
int c5=0;
int c1=0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(buzzerPin, OUTPUT);
  pinMode(PIN_TYPE_BTN_1, INPUT_PULLUP);
  initAll();
}

void loop() {
  //isDone = false;
  Display_Main();
  module_1.run(onClick);
  module_2.run(onChange);
  module_3.run(onChange);
}

void onClick(byte aID, unsigned aPrice, unsigned aCoin){
  SelectedID = aID;
  SelectedPrice = aPrice;
  coin = aCoin;
  
  switch(SelectedID){
    case 1: modulex = module_1;
    break;  
  }
  if(coin >= aPrice){
    coin = coin - aPrice;
    //modulex.increment(aPrice);
  }
  if(coin < aPrice){
    Display_InsertCoin();
    finishBuzzerIndicator();
  }
}

void onChange(byte aID, unsigned aPrice)
{
  SelectedPrice = aPrice;
  SelectedID = aID;
  switch(SelectedID)
  {
    case 1: moduley = module_2;
    break;
    case 2: moduley = module_3;
    break;   
  }
  if(digitalRead(PIN_TYPE_BTN_1) == LOW)
  {
    if(coin >= SelectedPrice)
    {
        coin = coin - aPrice;
        c5++;
        moduley.Servomove();
        Serial.print("cash=");
        Serial .print(coin);
        Serial.print(", counter5=");
        Serial.println(c5);
    }
    else if(coin >= SelectedPrice)
    {
        coin = coin - aPrice;
        c1++;
        moduley.Servomove();
        Serial.print("cash=");
        Serial.print(coin);
        Serial.print(", counter1=");
        Serial.println(c1);
    }else{
        Serial.println("No Credit Change!");
        Display_NoChange();
        finishBuzzerIndicator();
    }
    if(coin == 0 && !isDone){
      delay(1000);
      Serial.println("done");
      //isDone = true;
      Display_NoChange();
    }
  }
}

void finishBuzzerIndicator(){
  int buzzerRepeat = 3;
  // play tone on buzzer to indicate uv sensor is finished
  for (int i = 0; i <= buzzerRepeat; i++){
    tone(buzzerPin, 1000, 500); 
    delay(500); 
    tone(buzzerPin, 2000, 500); 
    delay(500); 
  }
  noTone(buzzerPin); 
}
