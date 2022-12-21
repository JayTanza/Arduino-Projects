#include "uDisplay.h"
void setup() 
{
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(A1, INPUT_PULLUP);
  //initAll();
  pinMode(coinpin,INPUT_PULLUP);
  attachInterrupt(0,coinInserted,FALLING);
}

void loop() 
{
  Serial.begin(9600);
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
