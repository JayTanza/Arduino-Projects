#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int coin = 0;
int cash = 0;
int value = 0;
int waterlvl = 0;
void Display_Main()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" IOT VENDO MACHINE");
  lcd.setCursor(0,1);
  lcd.print("  THESIS PROJECT");
  lcd.setCursor(0,2);
  lcd.print("Balance: ");
  lcd.println(coin);
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

void DisplayLoading(int aWaterLevel){
  waterlvl = aWaterLevel;
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" WATER LEVEL: ");
  lcd.println(waterlvl);
  lcd.setCursor(0, 1);
  lcd.print(" CHANGE: ");
  lcd.print(coin);  
}
void coinInserted(){
  coin++;
}

void coinDispensed(){
  coin--;
}
