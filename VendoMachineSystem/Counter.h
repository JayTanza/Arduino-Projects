#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

class TCounters{
  private:
  int coinpin = 2;
  int change = 0;

  public:
  int coins = 0;
  void init();
  void run();
  void coinInserted();
};

void TCounters::init(){
  lcd.begin(16,2);
  pinMode(coinpin,INPUT_PULLUP);  
}

void TCounters::run(){
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" COIN:  CHANGE:");
  lcd.setCursor(2,1);
  lcd.print(coins);
}

void TCounters::coinInserted(){
  coins++;  
}
