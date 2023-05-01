#include "Common.h"
#include <EEPROM.h>

unsigned int SelectedPrice = 0;
byte SelectedID = 0;
unsigned int aChange = 0;
bool isEmpty = true;
bool isRelayOn = false;
bool isDone = true;

//credit counter
int c5 = 0;
int c1 = 0;

void setup() {
  Serial.begin(9600);
  EEPROM.begin();
  Serial.setTimeout(100);
  initAll();
  Display_Main();
}

void loop() {
  if(coin > 0){
    isDone = false;  
  }
  if(Serial.available() > 0){
    String data = Serial.readStringUntil('\n'); // Read a line of data
    if (data.startsWith("ResetDailyIncome")) { // Check if data is a count value
      modulex.DailyIncomeReseter();
    }
  }
  Display_Main();
  module_1.run(onDispense);
  module_2.run(onChange);
  module_3.run(onChange);
  module_4.OnNoiseDetector(onNoiseDetected);
}

void onNoiseDetected(byte aID) {
  SelectedID = aID;
  switch (SelectedID) {
    case 1: modulez = module_4;
  }
}

void onDispense(byte aID, unsigned aPrice) {
  SelectedID = aID;
  SelectedPrice = aPrice;
  switch (SelectedID) {
    case 1: modulex = module_1;
  }
}

void onChange(byte aID, unsigned aPrice) {
  SelectedPrice = aPrice;
  SelectedID = aID;
  switch (SelectedID)
  {
    case 1: moduley = module_2;
      break;
    case 2: moduley = module_3;
      break;
  }
  if(coin >= aPrice) {
    coin = coin - aPrice;
    c5++;
    moduley.Servomove();
    Serial.print("cash=");
    Serial .print(coin);
    Serial.print(", counter5=");
    Serial.println(c5);
  }
  else if (coin >= aPrice) {
    coin = coin - aPrice;
    c1++;
    moduley.Servomove();
    Serial.print("cash=");
    Serial.print(coin);
    Serial.print(", counter1=");
    Serial.println(c1);
  }
  if (coin == 0 && !isDone){
    delay(1000);
    Serial.print("No Credit Change!");
    Display_NoChange();
    Serial.println("done");
    isDone = true;
  }
}
