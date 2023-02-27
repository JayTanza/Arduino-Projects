#include <Wire.h>

//uType Module use only to initialize sensors ex. LED, Servo, Buttons
class TType{
  private://Private Variables
    int PIN_BTN_1 = 8;
    int PIN_LED_1 = 7;
    int buttonValue = 0;
    byte ID = 0;

  public: //Public methods
    void init(int aBtn, int aLed, byte aID);
    void ledon();
    void ledoff();
    void LIGHT();
    void LED(void onLight(byte aID));
};
//initializing methods
void TType::init(int aBtn, int aLed, byte aID){
   PIN_BTN_1 = aBtn;
   PIN_LED_1 = aLed;
   ID = aID;
   
   pinMode(PIN_BTN_1, INPUT);
   pinMode(PIN_LED_1, OUTPUT);
}

void TType::LED(void onLight(byte aID)){
    onLight(ID);
}

void TType::LIGHT(){
  buttonValue = digitalRead(PIN_BTN_1);
  if(buttonValue != 0){
    digitalWrite(PIN_LED_1, HIGH); 
  }else{
    digitalWrite(PIN_LED_1, LOW); 
  }  
}
