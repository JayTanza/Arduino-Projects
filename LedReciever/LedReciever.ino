//Reciever
int LED = 13;
char message;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    message = Serial.read();
    if(message == '1')
    {
      digitalWrite(LED,HIGH);
    }  
    delay(20);
    digitalWrite(LED,LOW);
  }
}
