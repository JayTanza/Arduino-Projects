#include <DHT.h>

#define DHTTYPE DHT11   
#define PIN_TYPE_DHT 2  
#define PIN_TYPE_SOUND A0 
#define PIN_TYPE_RELAY 4 
#define TEMP_THRESHOLD 50   
#define SOUND_THRESHOLD 500 

unsigned long lastTempTriggered = 0;  
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;

bool isTempTriggered = false;  
bool isSoundTriggered = false; 
boolean status_relay = false;

DHT dht(PIN_TYPE_DHT, DHTTYPE);

void setup() {
  pinMode(PIN_TYPE_RELAY, OUTPUT);
  pinMode(PIN_TYPE_SOUND, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  //displayFunction(temperature);
  soundFunction();
  tempFunction(temperature);
//  delay(2000);
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

void soundFunction() {
  int soundValue = digitalRead(PIN_TYPE_SOUND);
  if(soundValue == 0){
    if(clap == 0){
      detection_range_start = detection_range = millis();
      clap++;
    }else if (clap > 0 && millis()-detection_range >= 50){
      detection_range = millis();
      clap++;
    }
  }
  if (millis()-detection_range_start >= 400)
  {
    if (clap == 2)
    {
      if (!status_relay)
      {
        status_relay = true;
        digitalWrite(10, HIGH);
        Serial.println("Relay is on");
      }
      else if (status_relay)
      {
        status_relay = false;
        digitalWrite(10, LOW);
        Serial.println("Relay is off");
      }
    }
    clap = 0;
  }
}
