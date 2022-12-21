void setup() {
  // put your setup code here, to run once:
  for(int x = 8; x<=12; x++)
  {
    pinMode(x,OUTPUT);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int y = 8; y<=12; y++)
  {
    digitalWrite(y,HIGH);
    delay(50); 
    digitalWrite(y,LOW);
  }
    digitalWrite(12,HIGH);
    delay(50); 
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(11,HIGH);
    delay(50); 
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(50); 
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(10,HIGH);
    delay(50); 
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    delay(50); 
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(12,LOW);
    digitalWrite(8,LOW);
    digitalWrite(8,HIGH);
    delay(50); 
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
 /*  for(int y = 12; y>=8; y++)
  {
    digitalWrite(y,HIGH);
    delay(100); 
    digitalWrite(y,LOW);
  }*/
}
