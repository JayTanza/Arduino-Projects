//Transmitter

int Button = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(Button, INPUT_PULLUP);
}

void loop() 
{
  if(digitalRead(Button)==0)
  {
    Serial.write('1');
  }
  delay(20); //waiting message
}
