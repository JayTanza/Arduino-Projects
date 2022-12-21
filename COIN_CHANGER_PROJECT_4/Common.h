#include "uType.h"

#define PIN_TYPE_SERVO_1 9
#define PIN_TYPE_SERVO_2 10
#define PIN_TYPE_SERVO_3 11

#define PIN_TYPE_SENSOR_1 2
#define PIN_TYPE_SENSOR_2 3
#define PIN_TYPE_SENSOR_3 5

TType module1, module2, module3;
TType modulex, moduley;


void initAll()
{
  module1.init(PIN_TYPE_SERVO_1,PIN_TYPE_SENSOR_1,1,10);
  module2.init(PIN_TYPE_SERVO_2,PIN_TYPE_SENSOR_2,2,5);
  module3.init(PIN_TYPE_SERVO_3,PIN_TYPE_SENSOR_3,3,1);
}
