char mystr[10] = "Hello";

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.write(mystr,5);
  delay(1000);
}
