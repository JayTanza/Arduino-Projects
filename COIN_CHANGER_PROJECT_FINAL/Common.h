//#include "uDisplay.h"
#include "uType.h"

#define PIN_TYPE_SERVO_1 8
#define PIN_TYPE_SERVO_2 9
#define PIN_TYPE_SERVO_3 10
#define PIN_TYPE_SERVO_4 11

#define PIN_TYPE_SENSOR_1 A0
#define PIN_TYPE_SENSOR_2 3
#define PIN_TYPE_SENSOR_3 2
#define PIN_TYPE_SENSOR_4 5

TType module1, module2, module3, module4;
TType modulex, moduley;


void initAll()
{
  module1.init(PIN_TYPE_SERVO_1,PIN_TYPE_SENSOR_1,1,20);
  module2.init(PIN_TYPE_SERVO_2,PIN_TYPE_SENSOR_2,2,10);
  module3.init(PIN_TYPE_SERVO_3,PIN_TYPE_SENSOR_3,3,5);
  module4.init(PIN_TYPE_SERVO_4,PIN_TYPE_SENSOR_4,4,1);
}
