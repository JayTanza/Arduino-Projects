#include <LiquidCrystal_I2C.h> //LCD library
LiquidCrystal_I2C lcd(0x27,16,2);

unsigned int Coin = 0;

void dspInit(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print(" COIN:  CHANGE:");
   lcd.setCursor(2,1);
   lcd.print(Coin);
   Serial.println(Coin);
}

void dspWelcome(){
  lcd.print("Hi, Welcome!");
}

void dspHome(){
  lcd.print("JAY TECH-VENDO");
}

void dspSelectedType(){
  
}

void dspDispense(){
  
}

void dspThanx(){
  
}

void dspUpdate(){
  Coin++;
}
