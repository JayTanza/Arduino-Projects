#include "uLED.h" //inheretance of library
TLED led1,led2,led3; //class TLED assign to led1,led2 and led3 is built-in led

void setup(){
  Serial.begin(9600);//Primary connections between devices - 9600 baudrates from bootloader 
  led1.init(11);
  led2.init(12);
  led2.setInterval(1000);
  led3.init(13);
  led3.setInterval(500);
}

void loop(){
  Serial.println("Hello World");
  led1.run();
  led2.run();
  led3.run();
  //LEDBLINKING();
}

/*void LEDBLINKING(){
  digitalWrite(PIN_LED,HIGH);
  delay(1000);
  digitalWrite(PIN_LED,LOW);
  delay(1000);
}*/
