#include <SPI.h>

//Libraries
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 3

//Module TM1637 assigned display connection pins
TM1637Display display(CLK,DIO);

int Red=9;
int coinpin=2;

//Variables 
volatile int pulse = 0;
volatile unsigned long timelastPulse = 0;
boolean coinInsert = false;
int buttonState = 0;
int credits = 0;
int credits_ = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(coinpin, INPUT_PULLUP);
  pinMode(Red,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(coinpin), coinInterrupt, FALLING);
}

void loop() {

  
  
  unsigned long lastTime = millis() - timelastPulse;

  if((pulse > 0) && (lastTime > 24)){
    coinInsert = false;
    credits += pulse;
    pulse = 0;
    //Serial.println(lastTime);
  }
    
  if (credits_ != credits){
    credits_ = credits;
    displayCredit();  
    switch(credits){
      case 1:
      digitalWrite(Red, HIGH);
      break;
  
      case 5:
      digitalWrite(Red, HIGH);
      break;
  
      case 10:
      digitalWrite(Red, HIGH);
      break;
  
      default:
      digitalWrite(Red, LOW);
    }
  }
}

void coinInterrupt(){
    pulse++;
    timelastPulse = millis();

    digitalWrite(Red, HIGH);  
}

void displayCredit(){
  if(credits==0){
      Serial.print("");
      display.setBrightness(0x0f);
      Serial.println("Coin Counter");
      Serial.println("Insert Coins:");
      delay(1000);
      Serial.print("");

      Serial.print("");
      Serial.println("Coin Counter");
      Serial.println("P1 P5 P10");
      delay(1000);
      Serial.print("");
  } 
  else
  {
    Serial.println("Coin Counter");  
    Serial.println("Php: P");
    Serial.println(credits);
    display.showNumberDec(credits);
  }
}
