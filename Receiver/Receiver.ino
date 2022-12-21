//Receiver
int LED = 13;
char message;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    message = Serial.read();
    if(message == '1')
    {
      digitalWrite(LED,1);
    }
  }
  delay(20); // waiting message receiver
  digitalWrite(LED,0);
}
