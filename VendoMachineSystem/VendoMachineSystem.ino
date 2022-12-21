#include "Counter.h"
#include "ServoRotate.h"
#include "Buttons.h"
TCounters c1;
TServo s1;
TButtons b1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  c1.init();
  s1.init();
  b1.init();
  attachInterrupt(0,onGetCoin,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  c1.run();
  s1.run(onPushBtn);
  b1.run();
}

void onPushBtn() {
  c1.coins = 0;  
}

void onGetCoin() {
  c1.coinInserted(); // call the coinInserted method from Counter Class
  s1.enable = c1.coins == 5 || c1.coins == 10 || c1.coins == 15; // from the class ServoRotate if the coins are 5,10,15 it will rotate  
}
