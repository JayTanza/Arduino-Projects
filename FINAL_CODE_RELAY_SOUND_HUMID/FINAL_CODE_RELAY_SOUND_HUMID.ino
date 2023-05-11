#include <DHT.h>

#define DHTTYPE DHT11
#define PIN_TYPE_DHT 7
#define PIN_TYPE_SOUND A0
#define PIN_TYPE_RELAY 4
#define TEMP_THRESHOLD 80
#define SOUND_THRESHOLD 500

int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
unsigned long lastTempTriggered = 0;
unsigned long lastSoundTriggered = 0;
bool isTempTriggered = false;
bool isSoundTriggered = false;
bool isRelayOn = false;
boolean status_relay = false;

DHT dht(PIN_TYPE_DHT, DHTTYPE);

enum Task{
  READ_TEMPERATURE,
  CHECK_TEMPERATURE,
  CHECK_SOUND,
};

Task currentTask = READ_TEMPERATURE;

void setup(){
  pinMode(PIN_TYPE_RELAY, OUTPUT);
  pinMode(PIN_TYPE_SOUND, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  switch (currentTask) {
    case READ_TEMPERATURE:
      readHumidityFunction();
      break;
    case CHECK_TEMPERATURE:
      checkTemperature();
      break;
    case CHECK_SOUND:
      checkSoundFunction();
      break;
  }
}

void readHumidityFunction(){
  float humidity = dht.readHumidity();
  displayTemperature(humidity);
  currentTask = CHECK_TEMPERATURE;
}

void displayTemperature(float ahumid){
  int humidity = ahumid;
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(1000);
} 

void checkTemperature(){
  float humidity = dht.readHumidity();
  if (humidity >= TEMP_THRESHOLD && !isTempTriggered){
    isTempTriggered = true;
    lastTempTriggered = millis();
    turnRelayOn();
  }else if (humidity <= TEMP_THRESHOLD && isTempTriggered){
    isTempTriggered = false;
    lastTempTriggered = millis();
    turnRelayOff();
  }
  currentTask = CHECK_SOUND;
}

void checkSoundFunction(){
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
        turnRelayOn();
        Serial.println("Relay is on1");
      }
      else if (status_relay)
      {
        status_relay = false;
        turnRelayOff();
        Serial.println("Relay is off1");
      }
    }
    clap = 0;
  }
  currentTask = READ_TEMPERATURE;
}

void turnRelayOn() {
  if (!isRelayOn) {
    isRelayOn = true;
    Serial.println("The Relay is On");
    digitalWrite(PIN_TYPE_RELAY, HIGH);
  }
}

void turnRelayOff() {
  if (isRelayOn) {
    isRelayOn = false;
    Serial.println("The Relay is Off");
    digitalWrite(PIN_TYPE_RELAY, LOW);
  }
}
