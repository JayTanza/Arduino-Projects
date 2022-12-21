#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTpin 4
#define DHTtype DHT11

DHT dht(DHTpin, DHTtype);

void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  int temperature = dht.readTemperature();
  Serial.write(temperature);
}
