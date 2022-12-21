#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //set the LCD address to 0x27 for a 16 chars and 2 line display

//VARIABLES FOR BUTTON/DIGITAL PINS
int BUTTON_ADD = 2;
int BUTTON_SUBTRACT = 3;

//Variables will change:
int buttonPushCounter = 0; //counter for the number of button presses
int up_buttonState = 0;//current state of the up button
int up_lastButtonState = 0;//previous state of the up button

int down_buttonState = 0; //current state of the up button
int down_lastButtonState = 0;//previous s tate of the up button
bool bPress = false;//button condition

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON_ADD, INPUT_PULLUP);
  pinMode(BUTTON_SUBTRACT, INPUT_PULLUP);

  lcd.init(); //initialized the lcd

  //print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("INSERT COIN:");
  lcd.setCursor(2,1);
  lcd.print(buttonPushCounter);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  checkUp();

  checkDown();

  if(bPress){
    bPress = false;

      lcd.setCursor(2,1);
      lcd.print("                ");
      lcd.setCursor(2,1);
      lcd.print(buttonPushCounter);
  }
}

void checkUp(){
  up_buttonState = digitalRead(BUTTON_ADD);

  // compare the buttonState to its previous state
  if(up_buttonState != up_lastButtonState){
    //if the state has changed, increment the counter
    if(up_buttonState == LOW){
      bPress = true;

      // if the current state is HIGH then the button went from from off to on:

      buttonPushCounter += 5;

      Serial.println("on");
      Serial.println("number of button pushes: ");
      Serial.println(buttonPushCounter);
    }else{
      Serial.println("off");  
    }
    delay(50);
  }
  up_lastButtonState = up_buttonState;
}

void checkDown(){
  down_buttonState = digitalRead(BUTTON_SUBTRACT);

    //compare the buttonState to its previous state
    if(down_buttonState != down_lastButtonState){
      //if the state has changed, increment the counter
      if(down_buttonState == LOW){
        bPress = true;

        buttonPushCounter -= 1;
      Serial.println("on");
      Serial.println("number of button pushes: ");
      Serial.println(buttonPushCounter);
      }else{
      Serial.println("off");  
    }
      delay(50);
    }
    down_lastButtonState = down_buttonState;
}
