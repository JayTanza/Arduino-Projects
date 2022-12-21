#include "uButton.h"
#include "uServo.h"
#include "uSwitch.h"

#define PIN_TYPE_SERVO_1 13
#define PIN_TYPE_SWITCH_1 2
#define PIN_TYPE_BUTTON_1 A1 

TButton b1;
TSwitch w1;
TServo s1,s2;

void initAll()
{
  w1.init(PIN_TYPE_SWITCH_1);
  b1.init(PIN_TYPE_BUTTON_1);
  s1.init(PIN_TYPE_SERVO_1);
}
