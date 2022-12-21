#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int coin = 0;
int coinpin = 2;
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
  lcd.print(" COIN:  CHANGE:");
  lcd.setCursor(2,1);
  lcd.print(coin);
}

void Display_InsertCoin()
{
  lcd.begin(screenWidth,screenHeight);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("PLS INSERT COIN!");
  lcd.setCursor(2,1);
  lcd.print(coin);
}

void coinInserted()
{
  coin += 1;
}

void coinDispense()
{
  coin = coin - coin;
}

void Display_Home()
{
  lcd.begin(screenWidth,screenHeight);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(line1);
  lcd.setCursor(scrollCursor,1);
  lcd.print(line2.substring(stringStart,stringEnd));
  delay(10);
  //lcd.clear();

  if(stringStart == 0 && scrollCursor > 0)
  {
    scrollCursor--;
    stringEnd++;
  }
  else if(stringStart == stringEnd)
  {
    stringStart = stringEnd = 0;
    scrollCursor = screenWidth;  
  }
  else if(stringEnd == line2.length() && scrollCursor == 0)
  {
    stringStart++;  
  }
  else
  {
    stringStart++;
    stringEnd++;  
  }
}

void DisplayEmpty()
{
  lcd.begin(screenWidth,screenHeight);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("CIGARETTE IS");
  lcd.setCursor(2,1);
  lcd.print("EMPTY!");
}
