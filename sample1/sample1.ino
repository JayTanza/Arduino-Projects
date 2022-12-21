#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int coinpin = 2;
const int ledpin = 7;
int coins = 0;

volatile int pulse = 0;

boolean bInserted = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0,coinInserted,FALLING);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bInserted)
  {
    bInserted = false;
    digitalWrite(ledpin,HIGH);  
  }
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" COIN:  CHANGE:");
  lcd.setCursor(2,1);
  lcd.print(coins);
}

void coinInserted()
{
  coins += 1;
  bInserted = true;
}
