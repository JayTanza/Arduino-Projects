#include "uDisplay.h"
#include "uDispense.h"
#include "uChanger.h"

//defining coincounter to pin 2
#define PIN_TYPE_COIN_1 2

//defining relay to pin 3
#define PIN_TYPE_RELAY_1 3

//defining button to pin 7
#define PIN_TYPE_BTN_1 7

//defining button to pin 8 for changer
#define PIN_TYPE_BTN_2 8
#define PIN_TYPE_BTN_3 11

//defining button to pin 9 for servo
#define PIN_TYPE_SERVO_1 9
#define PIN_TYPE_SERVO_2 10

TType module_1;
TType modulex;
TChanger module_2, module_3;
TChanger moduley;

void initAll(){
  module_1.init(PIN_TYPE_BTN_1,PIN_TYPE_COIN_1, PIN_TYPE_RELAY_1, 1, 1, coinInserted);  
  module_2.init(PIN_TYPE_SERVO_1,PIN_TYPE_BTN_2, 1, 1);  
  module_3.init(PIN_TYPE_SERVO_2,PIN_TYPE_BTN_3, 2, 5);  
}
