#include "Common.h"
#define PIN_TYPE_LED_4 4
unsigned int SelectedPrice = 0;
byte SelectedID = 0;
unsigned int aChange = 0;
bool isEmpty = true;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(A1, INPUT_PULLUP);
  initAll();
  pinMode(coinpin,INPUT_PULLUP);
  attachInterrupt(0,coinInserted,FALLING);
}

void loop() 
{   
  Display_Main();
  onDispense();
  
  module_1.run(onClick);
  module_2.run(onClick);
  module_3.run(onClick);
  onDispense();
  //module_4.onDispense(coin);
  
  module_1.LED(onLight);
  module_2.LED(onLight);
  module_3.LED(onLight);
  module_4.Sensor(); 
}

void onDispense()
{
  Display_Main();
  if (Serial.available()>0){
    String cmd= Serial.readString();
    cmd.trim();
    digitalWrite(4, LOW);
    if (cmd.equals("done")){
      Serial.println("Yey!");
      digitalWrite(4, HIGH);
    }
  }

  if (digitalRead(A1) == LOW){
    digitalWrite(4, LOW);
    Serial.println(coin);
    delay(1000);
    coinDispense();
  } 
}

void onClick(byte aID, unsigned aPrice)
{  
  SelectedPrice = aPrice;
  SelectedID = aID;
  coin = aChange;
  
  switch(SelectedID)
  {
    case 1: modulex = module_1;
    break;  
    case 2: modulex = module_2;
    break; 
    case 3: modulex = module_3;
    break;
  }
  
  if(coin >= aPrice)
  {   
    modulex.Servomove();
    coin = coin - aPrice;
  }
  
  if(coin < aPrice)
  {
    Display_InsertCoin();
  }
}

void onLight(byte aID, unsigned aPrice)
{  
  SelectedPrice = aPrice;
  SelectedID = aID;

  switch(SelectedID)
  {
    case 1: modulez = module_1;
    break;  
    case 2: modulez = module_2;
    break; 
    case 3: modulez = module_3;
    break; 
  }
  if(coin >= aPrice)
  {
    modulez.ledon();
  }
  else
  {
    modulez.ledoff();
  }
  //Serial.println(aPrice);
}
