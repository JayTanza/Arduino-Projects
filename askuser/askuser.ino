int ledPin = 10;
int numBlinks;
String LedonMessage = "LED is Turned on";
String LedoffMessage = "LED is Turned off";

void setup() 
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("How many times do you want the LED blink!");
  while(Serial.available()==0)
  {
    //user input
  }
  numBlinks = Serial.parseInt();
  for(int counter = 1; counter <= numBlinks; counter++)
  {
    Serial.println(LedonMessage);
    digitalWrite(ledPin,HIGH);
    delay(1000);
    Serial.println(LedoffMessage);
    digitalWrite(ledPin,LOW);
    delay(1000);
  }
  Serial.println("The user has choosen the number of blinks: ");
  Serial.println(numBlinks);
  Serial.println(" ");
}
