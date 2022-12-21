#include "uDisplay.h"
#include "uType.h"

#define PIN_TYPE_LED_1 10
#define PIN_TYPE_LED_2 9 
#define PIN_TYPE_LED_3 8
#define PIN_TYPE_LED_4 4

#define PIN_TYPE_BTN_1 7
#define PIN_TYPE_BTN_2 6
#define PIN_TYPE_BTN_3 5
#define PIN_TYPE_BTN_4 A1

#define PIN_TYPE_SERVO_1 11
#define PIN_TYPE_SERVO_2 12
#define PIN_TYPE_SERVO_3 13

#define PIN_TYPE_SENSOR_1 A0

TType module_1, module_2, module_3, module_4;
TType modulex, moduley, modulez;


void initAll()
{
  module_1.init(PIN_TYPE_BTN_1, PIN_TYPE_SERVO_1, PIN_TYPE_LED_1, PIN_TYPE_SENSOR_1, 1, 5);
  module_2.init(PIN_TYPE_BTN_2, PIN_TYPE_SERVO_2, PIN_TYPE_LED_2, PIN_TYPE_SENSOR_1, 2, 10);
  module_3.init(PIN_TYPE_BTN_3, PIN_TYPE_SERVO_3, PIN_TYPE_LED_3, PIN_TYPE_SENSOR_1, 3, 20);
  module_4.init(PIN_TYPE_BTN_4, PIN_TYPE_SERVO_2, PIN_TYPE_LED_4, PIN_TYPE_SENSOR_1, 4, 0);
}
