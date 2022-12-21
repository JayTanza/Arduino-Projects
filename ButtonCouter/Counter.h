#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//#include "ServoRotate.h"

LiquidCrystal_I2C lcd(0x27,16,2); 
//set the LCD address to 0x27 for a 16 chars and 2 line display

class Counters{
  private:
  int BUTTON_ADDpin = 2;
  int BUTTON_SUBTRACTpin = 3;
  int BUTTON_DIVIDEpin = 4;

  int buttonPushCounter = 0; //mo count siya ug ika pila ni push
  
  int add_buttonState = 0; //current state of the add button
  int add_lastButtonState = 0;//previous state of the add button

  int sub_buttonState = 0;//current state sub
  int sub_lastButtonState = 0;//previous state sub

  int div_buttonState = 0;//current state sub
  int div_lastButtonState = 0;//previous state sub
  
  bool ButtonPress = false;

  
  
  public:  
  void init();
  void run();
  
  void checkAdd();
  //void checkSubtract();
  //void checkDivide();
};

void Counters::init(){
  Serial.begin(9600);
  pinMode(BUTTON_ADDpin, INPUT_PULLUP);
  pinMode(BUTTON_SUBTRACTpin, INPUT_PULLUP);
  pinMode(BUTTON_DIVIDEpin, INPUT_PULLUP);
  
  lcd.init(); //initialized the lcd

  //print a message to the lcd
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("COIN:");
  
  /*lcd.setCursor(0,1);
  lcd.print("CHANGE:");*/
  
  lcd.setCursor(2,1);
  lcd.print(buttonPushCounter);
}

void Counters::run(){
  checkAdd();
  //checkSubtract();
  //checkDivide();
  
    if(ButtonPress){
      ButtonPress = false;
      lcd.setCursor(2,1);
      lcd.print("            ");
      lcd.setCursor(2,1);
      lcd.print(buttonPushCounter);
    }
}

void Counters::checkAdd(){
  //BUTTON_ADDpin = aPin;
  add_buttonState = digitalRead(BUTTON_ADDpin);

  //compare the buttonState to its previous state
  if(add_buttonState != add_lastButtonState){
    //if the state has changed, increment the counter  
    if(add_buttonState == LOW)
    {
      ButtonPress =true;
      //if the current state is HIGH then the button went from sub to add:
      buttonPushCounter += 1;
      Serial.println("Coins Inserted: ");
      Serial.println(buttonPushCounter);
    }
      delay(50);
  }
    add_lastButtonState = add_buttonState;
}

/*
void Counters::checkSubtract(){
  //BUTTON_SUBTRACTpin = aPin;
  sub_buttonState = digitalRead(BUTTON_SUBTRACTpin);

  //compare the buttonState to its previous state
  if(sub_buttonState != sub_lastButtonState){
    //if the state has changed, increment the counter  
    if(sub_buttonState == LOW)
    {
      ButtonPress =true;
      //if the current state is HIGH then the button went from sub to add:
      buttonPushCounter += 5;
      Serial.println("Coins Inserted: ");
      Serial.println(buttonPushCounter);
    }
      delay(50);
  }
    sub_lastButtonState = sub_buttonState;
}


void Counters::checkDivide(){
  //BUTTON_SUBTRACTpin = aPin;
  div_buttonState = digitalRead(BUTTON_DIVIDEpin);

  //compare the buttonState to its previous state
  if(div_buttonState != div_lastButtonState){
    //if the state has changed, increment the counter  
    if(div_buttonState == LOW)
    {
      ButtonPress =true;
      //if the current state is HIGH then the button went from sub to add:
      buttonPushCounter += 10;
      Serial.println("Coins Inserted: ");
      Serial.println(buttonPushCounter);
    }
      delay(50);
  }
    div_lastButtonState = div_buttonState;
}*/
