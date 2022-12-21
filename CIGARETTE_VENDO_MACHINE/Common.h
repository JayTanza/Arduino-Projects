#include "uLight.h"
#include "uBotton.h"
#include "uServo.h"
#include "uDisplay.h"

#define PIN_TYPE_LED_1 10
#define PIN_TYPE_LED_2 9
#define PIN_TYPE_LED_3 8


#define PIN_TYPE_BUTTON_1 8
#define PIN_TYPE_BUTTON_2 6
#define PIN_TYPE_BUTTON_3 5

#define PIN_TYPE_SERVO_1 11
#define PIN_TYPE_SERVO_2 12

Light module, module1;
Button b1;
TServo s1, s2;

void initAll()
{
  module.init(PIN_TYPE_LED_1, PIN_TYPE_LED_2, PIN_TYPE_LED_3);  
  b1.init(PIN_TYPE_BUTTON_1, PIN_TYPE_BUTTON_2, PIN_TYPE_BUTTON_3);
  s1.init(PIN_TYPE_SERVO_1);
  s2.init(PIN_TYPE_SERVO_2);
}
