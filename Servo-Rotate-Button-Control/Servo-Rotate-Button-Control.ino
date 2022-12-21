#include "Common.h"
void setup() 
{
  initAll();
}

void loop() 
{
  b1.push(onPush);
}

void onPush()
{
  s1.move();  
}
