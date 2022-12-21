#include "Common.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initAll();
}

void loop() {
  // put your main code here, to run repeatedly:
  //btn.onButton(onPushLED,offPushLED);
  led.onButton();
}

/*
void onPushLED()
{  
    led.onLED();
}

void offPushLED()
{  
    led.offLED();
}*/
