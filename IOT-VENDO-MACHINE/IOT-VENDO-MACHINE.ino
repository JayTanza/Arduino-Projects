#include "Common.h"
#include <EEPROM.h>

unsigned int SelectedPrice = 0;
byte SelectedID = 0;
unsigned int aChange = 0;
bool isEmpty = true;
bool isRelayOn = false;
int PIN_BTN_CHANGER = 6;
bool isDone = true;
unsigned int Button_State = HIGH;
unsigned int PrevButton_State = HIGH;

//credit counter
int c10=0;
int c5=0;
int c1=0;

// initialize the value
int INCOME_TOTAL = 0;
int INCOME_DAILY = 0;
int INCOME_WEEKLY = 0;
int INCOME_MONTHLY = 0;
int INCOME_RESETER = 0;
int WATER_LEVEL = 100;

// Define the address in EEPROM to store the button count
int TOTAL_COUNT_ADDRESS = 0;
int DAILY_COUNT_ADDRESS = 1;
int WEEKLY_COUNT_ADDRESS = 2;
int MONTHLY_COUNT_ADDRESS = 3;
int WATER_LEVEL_ADDRESS = 4;

void setup(){
  Serial.begin(9600);
  EEPROM.begin();
  INCOME_TOTAL = EEPROM.read(TOTAL_COUNT_ADDRESS);
  INCOME_DAILY = EEPROM.read(DAILY_COUNT_ADDRESS);
  INCOME_WEEKLY = EEPROM.read(WEEKLY_COUNT_ADDRESS);
  INCOME_MONTHLY = EEPROM.read(MONTHLY_COUNT_ADDRESS);
  WATER_LEVEL = EEPROM.read(WATER_LEVEL_ADDRESS);
  Serial.setTimeout(100);
  initAll();
  Display_Main();
}

void loop() {
  Display_Main();
  module_4.OnNoiseDetector(onNoiseDetected);
  if(coin>0){
    isDone = false;
  }
  //Display_Main();
  module_1.run(onDispense);
  module_2.run(onChange);
  module_3.run(onChange);
}

void onNoiseDetected(byte aID){
  SelectedID = aID;
  switch(SelectedID){
    case 1: modulez = module_4;
  }
}

void onDispense(byte aID, unsigned aPrice){
  SelectedID = aID;
  SelectedPrice = aPrice;
  switch(SelectedID){
    case 1: modulex = module_1;
  }  
  if(coin >= aPrice){
    coinDispense();
    TOTAL_INCOME();
    DAILY_INCOME();
    WATERLEVEL();
    Display_Main();
    modulex.Relay(INCOME_TOTAL, WATER_LEVEL);
//    Serial.println(coin);
  }
  
  if(coin < aPrice){
    Display_InsertCoin();
    //RESETER_INCOME();
    Serial.println("Insert Coin!");
    Serial.print("Total Income: ");
    Serial.println(INCOME_TOTAL);
    Serial.print("Daily Income: ");
    Serial.println(INCOME_DAILY);
    Serial.print("WATER LEVEL: ");
    Serial.println(WATER_LEVEL);
  }
}

void onChange(byte aID, unsigned aPrice){
  SelectedPrice = aPrice;
  SelectedID = aID;
  switch(SelectedID)
  {
    case 1: moduley = module_2;
    break;
    case 2: moduley = module_3;
    break;   
  }
  Button_State = (digitalRead(PIN_BTN_CHANGER));
  if(Button_State == LOW){
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
    }
    if(coin == 0 && !isDone){
      delay(1000);
      Serial.println("No Credit Change!");
      Display_NoChange();
      Serial.println("done");
      isDone = true;
    } 
  } 
}

void TOTAL_INCOME(){
  INCOME_TOTAL = INCOME_TOTAL + 1;
  Serial.print("Total Income: ");
  Serial.println(INCOME_TOTAL);
  EEPROM.write(TOTAL_COUNT_ADDRESS,INCOME_TOTAL);
  delay(100);
}

void DAILY_INCOME(){
  INCOME_DAILY = INCOME_DAILY + 1;
  Serial.print("Daily Income: ");
  Serial.println(INCOME_DAILY);
  EEPROM.write(DAILY_COUNT_ADDRESS,INCOME_DAILY);
  delay(100);
}

void WATERLEVEL(){
  WATER_LEVEL = WATER_LEVEL - 1;
  Serial.print("WaterLevel: ");
  Serial.println(WATER_LEVEL);
  EEPROM.write(WATER_LEVEL_ADDRESS,WATER_LEVEL);
  delay(100);
}

void RESETER_INCOME(){
  INCOME_TOTAL = 0;
  INCOME_DAILY = 0;
  WATER_LEVEL = 100;
  Serial.print("Total Income: ");
  Serial.println(INCOME_TOTAL);
  Serial.print("Daily Income: ");
  Serial.println(INCOME_DAILY);
  Serial.print("Water Level: ");
  Serial.println(WATER_LEVEL);
  EEPROM.write(TOTAL_COUNT_ADDRESS,INCOME_TOTAL);
  EEPROM.write(DAILY_COUNT_ADDRESS,INCOME_DAILY);
  EEPROM.write(WATER_LEVEL_ADDRESS,WATER_LEVEL);
  delay(100);
}
