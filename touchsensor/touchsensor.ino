
#define ctsPin 7 // Pin for capactitive touch sensor
int ledPin = 13; // pin for the LED
int buzzer = 12;
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);  
  pinMode(ctsPin, INPUT);
}
 
void loop() {
  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH){
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzer, HIGH); 
    Serial.println("TOUCHED");
  }
  else{
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzer, LOW); 
    Serial.println("not touched");
  } 
  delay(500); 
}
