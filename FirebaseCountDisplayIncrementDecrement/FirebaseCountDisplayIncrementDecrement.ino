//#if defined(ESP32)
//#include <WiFi.h>
//#include <FirebaseESP32.h>
#include <ESP8266WiFi.h>
//#include <FirebaseESP32.h>
#include <FirebaseArduino.h>

#define ssid "TanzaClan"
#define password "Tanza042001*"
#define firebaseHost "jayvis-iot-app-default-rtdb.firebaseio.com"
#define firebaseAuth "cSSdpXd88OdLUtCX9YowQvkMabxcT0KVO9t67FkV"

// initialize the value
int value = 0;

// set up the pins for the buttons
#define increment_pin 5
#define decrement_pin 4

void setup() {
  Serial.begin(9600);
  pinMode(increment_pin, INPUT_PULLUP);
  pinMode(decrement_pin, INPUT_PULLUP);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  Firebase.begin(firebaseHost, firebaseAuth);
}

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
  // check if the increment button is pressed
  if (digitalRead(increment_pin) == LOW) {
    increment();
    //Serial.print("Value: ",increment());
    delay(250); // add a delay to debounce the button
  }
  // check if the decrement button is pressed
  if (digitalRead(decrement_pin) == LOW) {
    decrement();
    //Serial.print("Value: ",decrement());
    delay(250); // add a delay to debounce the button
  }
}
