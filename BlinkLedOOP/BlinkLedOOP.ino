#include "Common.h"

byte SelectedID = 0;

void setup() {
  //Serialcom
  Serial.begin(9600);
  
  //Calling the function initAll from Common class
  initAll(); 
}

// the loop function runs over and over again forever
void loop() {
  module_1.LED(onLight);
  module_2.LED(onLight);
  module_3.LED(onLight);

  //module_1.LIGHT();
}

void onLight(byte aID){
  SelectedID = aID;
  
  switch(SelectedID){
    case 1: modulex = module_1;
    break;  
    case 2: modulex = module_2;
    break; 
    case 3: modulex = module_3;
    break; 
  }
  modulex.LIGHT();
}
