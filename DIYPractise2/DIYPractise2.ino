#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4 
#define DIO 3

TM1637Display display(CLK,DIO);

int incomingImpuls = 0;

void setup() {
  // put your setup code here, to run once:
  /*attachInterrupt(0,incomingImpuls, FALLING);
  display.clear();
  EEPROM.get(0, total_amount);*/
  Serial.begin(9600);
  attachInterrupt(0,coinpulse, RISING);
  display.setBrightness(0x0f);
  //sum = incomingImpuls + incomingImpuls;
  display.showNumberDec(incomingImpuls);
  Serial.println("Yey!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //incomingImpuls++;
 // Serial.println("Yey!");
}
void coinpulse() {
//  sum += coinPulseCount + newCoinInserted;
//  pulseTime = millis(); //store current time in pulseTime
  Serial.println("Yey!");
//  display.setBrightness(0x0f);
//  display.showNumberDec(sum);
}
