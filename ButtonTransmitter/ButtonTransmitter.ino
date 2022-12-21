//Transmitter
int Button = 13;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Button,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button)==0)
  {
    Serial.write('1');
  }
  delay(20);
}
