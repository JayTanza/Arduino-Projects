#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int screenWidth = 16;
int screenHeight = 2;
String line1 = "**Cebu-DIYTech**";
String line2 = "Cigarette Stick Vendo Machine!";
int stringStart = 0;
int stringEnd = 0;
int scrollCursor = screenWidth;

void Display_Main()
{
  lcd.begin(screenWidth,screenHeight);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("CHANGE:");
  lcd.setCursor(2,1);
  lcd.print(coins);
}

void Display_InsertCoin()
{
  lcd.begin(screenWidth,screenHeight);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PLS INSERT COIN!");
  lcd.setCursor(2,1);
  lcd.print(coins);
}
