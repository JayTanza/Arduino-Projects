#include <Arduino.h>
#include <TM1637Display.h>
#include <EEPROM.h>
#include <Counter.h>

// Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

TM1637Display display(CLK,DIO);

  int i=0;
  int impulsCount = 0;
  float total_amount = 0;

TH1637Display display(CLK,DIO);


class TMain{
  private:
  int i=0;
  int impulsCount = 0;
  float total_amount = 0;

  public:
  void init();
  void run();
  void incomingImpuls();
};

void TCounter::init(int aPin)
{
  attachInterrupt(0,incomingImpuls, FALLING);
  display.clear();
  EEPROM.get(0, total_amount);
}

void incomingImpuls(){
  impulsCount=impulsCount+1;
  i=0;  
}

void loop(){
  i=i+1;
  if(i>=30 and impulsCount==1)
  {
    total_amount=total_amount+5;
    impulsCount=0;
    EEPROM.put(0, total_amount);  
  }
  if(i>=30 and impulsCount==2){
    total_amount=total_amount+1;
    impulsCount=0;
    EEPROM.put(0, total_amount);  
  }
  if(total_amount<10)
  display.showNumberDec(total_amount*10,0b10000000, true, 2, 2);
  else
  display.showNumberDec(total_amount*10,0b10000000, false, 4, 4);
}
