#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  delay(1000);
  lcd.print("Engr. Jay Michael Tanza");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int positionCounter = 0; positionCounter < 13; positionCounter++)
  {
    //Scroll one position left:
    lcd.scrollDisplayLeft();
    delay(500);  
  }
  for(int positionCounter = 0; positionCounter < 29; positionCounter++)
  {
    //scroll one position to right
    lcd.scrollDisplayRight();
    delay(150);  
  }
  for(int positionCounter = 0; positionCounter < 18; positionCounter++)
  {
     lcd.scrollDisplayRight();
    delay(150);   
  }

  //delay at the end of the full loop
  delay(1000);
}
