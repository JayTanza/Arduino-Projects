#include "uType.h" //inheretance for uType class Library
#include "uDisplay.h"

#define PIN_TYPE_BTN_1 5 //Define function Constant declaration for variable BUTTON 5
#define PIN_TYPE_SERVO_1 9 //Define function Constant declaration for variable SERVO 9 
#define PIN_TYPE_COINPIN_1 2 //Define function Constant declaration for variable COINPIN 2 


TType module1, module2, module3; //assign each modules
TType module;
void initAll()
{
  module1.init(PIN_TYPE_BTN_1, PIN_TYPE_SERVO_1, 1, 5);
}
