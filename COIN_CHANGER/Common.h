#include "uType.h"

#define PIN_TYPE_SWITCH_1 2
#define PIN_TYPE_SWITCH_2 3
#define PIN_TYPE_SWITCH_3 4

#define PIN_TYPE_SERVO_1 9

TType module1;
TType modulex;

void initAll()
{
  module1.init(PIN_TYPE_SWITCH_1, PIN_TYPE_SWITCH_2, PIN_TYPE_SWITCH_3, PIN_TYPE_SERVO_1);
}
