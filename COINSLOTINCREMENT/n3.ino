#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int coinPin = 2;
int buttonPin = 7;
int relayPin = 3;
int coinCount = 0;
bool relayOn = false;

void setup() {
  pinMode(coinPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);
  attachInterrupt(0, countCoin, FALLING);
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" COIN:  CHANGE:");
  lcd.setCursor(2, 1);
  lcd.print(coinCount);
  lcd.setCursor(10, 1);
  lcd.print(coinCount);
}

void loop() {
  DisplayMain();
  digitalWrite(relayPin, HIGH);
  if (!relayOn) {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      if (coinCount > 0){
        dispenseCoin();
        relayOn = true;
        Relay();
        DisplayLoading();
        delay(2000);
        DisplayMain();
      } else {
        DisplayInsertCoin();
        delay(2000);
        DisplayMain();
      }
    }
  } else {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      relayOn = false;
    }
  }
}

void countCoin() {
  if(!relayOn){
    coinCount = coinCount + 1;
    Serial.print("Coins inserted: ");
    Serial.println(coinCount);
  }else if(coinCount == 0){
    coinCount = coinCount + 1;
    Serial.print("Coins inserted: ");
    Serial.println(coinCount);
  }
}

void dispenseCoin() {
    coinCount--;
}

void Relay(){
  digitalWrite(relayPin, LOW);
  delay(2000);
  digitalWrite(relayPin, HIGH);
}

void DisplayLoading(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" COIN DISPENSED");
  lcd.setCursor(0, 1);
  lcd.print("CHANGE: ");
  lcd.print(coinCount);  
}

void DisplayMain(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" COIN:  CHANGE:");
  lcd.setCursor(2, 1);
  lcd.print(coinCount);
  lcd.setCursor(10, 1);
  lcd.print(coinCount);  
}

void DisplayInsertCoin(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PLS INSERT COIN!");
  lcd.setCursor(2, 1);
  lcd.print(coinCount);
}
