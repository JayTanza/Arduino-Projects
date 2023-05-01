#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int coin = 10;
int cash = 0;
int value = 0;

void Display_Main()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" IOT VENDO MACHINE");
  lcd.setCursor(0,1);
  lcd.print("   COIN:  CHANGE:");
  lcd.setCursor(4,2);
  lcd.print(coin);
  lcd.setCursor(13,2);
  lcd.print(coin);
}

void Display_TotalIncome(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("TotalIncome:");
  lcd.setCursor(2,1);
  lcd.print(value);
}

void Display_InsertCoin(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PLS INSERT COIN!");
  lcd.setCursor(2,1);
  lcd.print(coin);
}

void Display_NoChange(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("NO CHANGE!");
}

void DisplayLoading(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" WATER DISPENSED");
  lcd.setCursor(0, 1);
  lcd.print("CHANGE: ");
  lcd.print(coin);  
}
void coinInserted(){
  coin++;
}

void coinDispensed(){
  coin--;
}
