
unsigned long time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print("Time: ");
   time = millis();

   Serial.println(time); //prints time since program started
   delay(1000); //wait a second so as not to send massive amounts of data
}
