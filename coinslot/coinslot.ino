#include "counter.h"
Counters pin1;

void onGetCoin(){
  pin1.Insertedcoin();  
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pin1.init();
  attachInterrupt(0,onGetCoin,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  pin1.run();
}
