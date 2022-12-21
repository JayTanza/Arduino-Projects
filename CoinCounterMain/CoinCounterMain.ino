//Libraries
#include "CoinCounter.h"
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 3

//Module TM1637 assigned display connection pins
TM1637Display display(CLK,DIO);

int newCoinInserted = 0;
int coinPulseCount;
int sum = 0;
//byte cmd = 0; // a place to put our serial data.
int PIN_COUNT = 2; //pin3 as optical count input.
uint32_t pulseTime; //this stores the time of the last pulse.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("input pin");
  Serial.println(PIN_COUNT);
  Serial.println();
  pinMode(PIN_COUNT,INPUT); //optical count is an input
  attachInterrupt(0, coinpulse, RISING); //attach a PinChange interrupt to universal coin slot
  //attachInterrupt(0, coinpulse, FALLING); //attach a PinChange interrupt to universal coin slot
  display.setBrightness(0x0f);
  display.showNumberDec(coinpulse);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(coinPulseCount > 0 && millis() - pulseTime > 200){
  newCoinInserted = coinPulseCount; //new variable to free up coinPulse
  coinPulseCount = 0; // clear pulse count ready for new count
}

  
  
  //Process the coin inserted
  switch(newCoinInserted) {
  case 1: 
    Serial.println("1 pesos inserted");
    newCoinInserted = 0;
    break;
  case 2: 
    Serial.println("5 pesos inserted");
    newCoinInserted = 0;
    break;
  case 3: 
    Serial.println("10 pesos inserted");
    newCoinInserted = 0;
    break;
  }
  
}

void coinpulse() {
  sum += coinPulseCount + newCoinInserted;
  pulseTime = millis(); //store current time in pulseTime
  Serial.println("Yey!");
  display.setBrightness(0x0f);
  display.showNumberDec(sum);
}
