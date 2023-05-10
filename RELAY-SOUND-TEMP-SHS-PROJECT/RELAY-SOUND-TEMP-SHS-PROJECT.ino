#include <DHT.h>

#define DHTTYPE DHT11   
#define PIN_TYPE_DHT 2  
#define PIN_TYPE_SOUND A0 
#define PIN_TYPE_RELAY 4 
#define TEMP_THRESHOLD 50   
#define SOUND_THRESHOLD 500 

unsigned long lastTempTriggered = 0;  
unsigned long lastSoundTriggered = 0; 

bool isTempTriggered = false;  
bool isSoundTriggered = false; 

DHT dht(PIN_TYPE_DHT, DHTTYPE);

void setup() {
  pinMode(PIN_TYPE_RELAY, OUTPUT);
  pinMode(PIN_TYPE_SOUND, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  soundFunction();
  displayFunction(temperature);
  tempFunction(temperature);
  delay(2000);
}

void displayFunction(int aTemp){
  int bTemp = aTemp;
  Serial.print("Temperature: ");
  Serial.println(bTemp);
  delay(1000);
}

void tempFunction(int aTemp){
  int Temp = aTemp;
  if (Temp >= TEMP_THRESHOLD && !isTempTriggered){
    isTempTriggered = true;
    lastTempTriggered = millis();  
    digitalWrite(PIN_TYPE_RELAY, HIGH);  
    Serial.println("The Relay is On");
  }else if(isTempTriggered && (millis() - lastTempTriggered >= 300000)) {
    isTempTriggered = false;
    digitalWrite(PIN_TYPE_RELAY, LOW); 
    Serial.println("The Relay is Off");
  } 
}

void soundFunction(){
  int soundValue = digitalRead(PIN_TYPE_SOUND);
  if (soundValue == LOW){
    digitalWrite(PIN_TYPE_RELAY, HIGH);  
    if (!isSoundTriggered) {
      Serial.println("The Relay is On");
    }
    isSoundTriggered = true;
    lastSoundTriggered = millis();  
  }
  if (isSoundTriggered && (millis() - lastSoundTriggered >= 5000)){
    isSoundTriggered = false;
    digitalWrite(PIN_TYPE_RELAY, LOW); 
    Serial.println("The Relay is Off");
  }
}
