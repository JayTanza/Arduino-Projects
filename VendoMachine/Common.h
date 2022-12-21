#include "uType.h"

#define PIN_TYPE_BTN_1 5 
#define PIN_TYPE_SVR_1 9 

#define PIN_TYPE_BTN_2 6
#define PIN_TYPE_SVR_2 10
  
#define PIN_TYPE_BTN_3 7 

TType module1, module2;
TType module;

void initAll(){
  module1.init(PIN_TYPE_BTN_1, PIN_TYPE_SVR_1, 1, 5);
  module2.init(PIN_TYPE_BTN_2, PIN_TYPE_SVR_2, 2, 10);
}
