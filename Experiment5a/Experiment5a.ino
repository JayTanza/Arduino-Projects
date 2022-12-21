int ledPins[] = {2,3,4,5,6,7,8,9};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++)
  {
    pinMode(ledPins[i],OUTPUT);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<256; i++)
  {
    showBinNumber(i);
    delay(256-i); 
  }
}

void showBinNumber(int num)
{
  for(int i=0; i<8; i++)
  {
    if(num%2)
    digitalWrite(ledPins[i],HIGH);
    else
    digitalWrite(ledPins[i],LOW);
    num/=2;
  }
}
