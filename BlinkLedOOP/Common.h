#include "uType.h"

//instead of declaring variable we can also use defining method
#define PIN_TYPE_LED_1 7 
#define PIN_TYPE_LED_2 6
#define PIN_TYPE_LED_3 5

#define PIN_TYPE_BTN_1 8

//declaration of function 
TType module_1, module_2, module_3; 
TType modulex;

void initAll(){
  module_1.init(PIN_TYPE_BTN_1, PIN_TYPE_LED_1, 1);
  module_2.init(PIN_TYPE_BTN_1, PIN_TYPE_LED_2, 2);
  module_3.init(PIN_TYPE_BTN_1, PIN_TYPE_LED_3, 3);
}
