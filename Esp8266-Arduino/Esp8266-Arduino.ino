//#if defined(ESP32)
//#include <WiFi.h>
//#include <FirebaseESP32.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define ssid "TanzaClan"
#define password "Tanza042001*"
#define firebaseHost "jayvis-iot-app-default-rtdb.firebaseio.com"
#define firebaseAuth "cSSdpXd88OdLUtCX9YowQvkMabxcT0KVO9t67FkV"

// initialize the value
int value = 0;

const int LED_PIN = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  Firebase.begin(firebaseHost, firebaseAuth);
}

// function to Increment the value
void increment() {
  value = value + 1;
  Serial.print("Value: ");
  Serial.println(value);
  Firebase.setInt("Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/counts", value);
}

// function to decrement the value
void decrement() {
  value = value - 1;
  Serial.print("Value: ");
  Serial.println(value);
  Firebase.setInt("Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/counts", value);
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();
    if (signal == '1') {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("Hello from arduino");
      increment();
    } else {
      digitalWrite(LED_PIN, LOW);
      Serial.println("Hi from arduino");
    }
  }
}
