#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	/*lcd.backlight();
	lcd.print("Engr. Jay Tanza");*/
}

void loop()
{
  lcd.print("I was dancing in");
  lcd.setCursor(0,1);
  lcd.print("the dark with");
  delay(2000);
  lcd.clear();
  lcd.print("Strangers");
  delay(2000);
  lcd.clear();
  lcd.print("No love ");
  lcd.setCursor(0,1);
  lcd.print("around me");
  delay(2000);
  lcd.clear();
  
  lcd.print("When suddenly");
  lcd.setCursor(0,1);
  lcd.print("you found me oh");
  delay(5000);
  lcd.clear();
  lcd.print("girl, you're");
  lcd.setCursor(0,1);
  lcd.print("every woman");
  delay(2500);
  lcd.clear();
  
  lcd.print("in the world");
  lcd.setCursor(0,1);
  lcd.print("to me <3");
  delay(5000);
  lcd.clear();

  lcd.print("you're my");
  lcd.setCursor(0,1);
  lcd.print("fantasy");
  delay(2500);
  lcd.clear();

  lcd.print("you're my");
  lcd.setCursor(0,1);
  lcd.print("reality");
  delay(3000);
  lcd.clear();

   lcd.print("girl, you're");
  lcd.setCursor(0,1);
  lcd.print("every woman");
  delay(2500);
  lcd.clear();
  
  lcd.print("in the world");
  lcd.setCursor(0,1);
  lcd.print("to me <3");
  delay(4000);
  lcd.clear();

  lcd.print("you're every");
  lcd.setCursor(0,1);
  lcd.print("thing i need");
  delay(3000);
  lcd.clear();

  lcd.print("you're every");
  lcd.setCursor(0,1);
  lcd.print("thing to me");
  delay(3000);
  lcd.clear();

  lcd.print("  ohh girl...");
  delay(5000);
  lcd.clear();
  /*
	// Do nothing here...
  lcd.clear();
  lcd.print("Hi Welcome!");
  delay(1000);
  lcd.clear();

  lcd.print("I am Engr.");
  lcd.setCursor(0,1);
  lcd.print("Jay Gwapo Tanza");
  delay(1000);
  lcd.clear();

  lcd.print("I am Charming ");
  lcd.setCursor(0,1);
  lcd.print("and Gentleman!");
  delay(1000);
  lcd.clear();
  */
}
