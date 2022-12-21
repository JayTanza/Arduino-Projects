#include "uType.h"

#define PIN_TYPE_SWITCH_1 2
#define PIN_TYPE_SWITCH_2 3
#define PIN_TYPE_SWITCH_3 4

#define PIN_TYPE_SERVO_1 8
#define PIN_TYPE_SERVO_2 9
#define PIN_TYPE_SERVO_3 10
#define PIN_TYPE_SERVO_4 11

#define PIN_TYPE_BTN_1 8

TType module1, module2, module3, module4;
TType modulex, moduley, modulez, modulew;

void initAll()
{
  module1.init(PIN_TYPE_SERVO_1, 1, 3);  
  module2.init(PIN_TYPE_SERVO_2, 2, 3);  
  module3.init(PIN_TYPE_SERVO_3, 3, 3);  
  module4.init(PIN_TYPE_SERVO_4, 4, 3);   
}
