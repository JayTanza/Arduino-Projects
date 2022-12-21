const int aSensor = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(aSensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(aSensor) == HIGH)
  {
    digitalWrite(4,LOW);  
  }
  else
  {
    digitalWrite(4,HIGH);  
  }
  val = analogRead(aSensor);
  Serial.println(val);
  delay(1000);
}
