void setup() 
{
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    if(data == 'a')
    {
      digitalWrite(12,HIGH);  
    }  
    else if(data == 'b')
    {
      digitalWrite(12,HIGH); 
    }
  }
}
