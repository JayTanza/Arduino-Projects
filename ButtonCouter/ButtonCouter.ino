//inheritance for library Counter
#include "ServoRotate.h"
#include "Counter.h"

//Classes of each library
Counters pin1;
ServoR pin2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pin1.init();
  pin2.init();
  //pin2.push();
  lcd.setCursor(0,0);
  lcd.print(" COIN:  CHANGE:");
}

void loop()
{
  pin1.run();
  pin2.run();
}
