#include "uLED.h"
#include "uButton.h"

#define PIN_TYPE_LED_1 9
#define PIN_TYPE_LED_2 2
#define PIN_TYPE_LED_3 3
#define PIN_TYPE_LED_4 4
#define PIN_TYPE_LED_5 5
#define PIN_TYPE_LED_6 6
#define PIN_TYPE_LED_7 7

#define PIN_TYPE_BUTTON_1 8
#define PIN_TYPE_BUTTON_2 10

LED led;
Button btn,btn2;

void initAll()
{
  led.init(PIN_TYPE_LED_1, PIN_TYPE_LED_2, PIN_TYPE_LED_3, PIN_TYPE_LED_4, PIN_TYPE_LED_5, PIN_TYPE_LED_6, PIN_TYPE_LED_7);
  btn.init(PIN_TYPE_BUTTON_1);
  btn2.init(PIN_TYPE_BUTTON_2);
}
