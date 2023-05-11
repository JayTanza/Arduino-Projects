#include <Wire.h>
#include <DS3231.h>
#include <Servo.h>

DS3231 clock;
RTCDateTime dt;
Servo servo;

int buzzerPin = 3;  

void setup()
{
  Serial.begin(9600);
  Serial.println("Initialize DS3231");
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);
  servo.attach(9);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  mainFunction();
}

void rotateServo() {
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);
  servo.write(0);
}

void mainFunction(){
  dt = clock.getDateTime();

  // Convert to 12-hour format
  uint8_t hour = dt.hour;
  bool isPM = false;

  if (hour == 0) {
    hour = 12; // 12 midnight
  } else if (hour > 12) {
    hour -= 12;
    isPM = true;
  }

  // Display the time
  Serial.print("Real-Time-Data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(hour);      Serial.print(":");
  if (dt.minute < 10) {
    Serial.print("0");
  }
  Serial.print(dt.minute); Serial.print(":");
  if (dt.second < 10) {
    Serial.print("0");
  }
  Serial.print(dt.second); Serial.print(" ");
  if (isPM) {
    Serial.print("PM");
  } else {
    Serial.print("AM");
  }
  Serial.println("");

  // Check if it's 1:00 AM
  if(hour == 9 && dt.minute == 59 && dt.second == 50 && !isPM){
    finishBuzzerIndicator();
    rotateServo();
    Serial.println("Yehey!");
  }else if(hour == 5 && dt.minute == 59 && dt.second == 50 && isPM){
    finishBuzzerIndicator();
    rotateServo();
    Serial.println("Yehey!");
  }else if(hour == 8 && dt.minute == 25 && dt.second == 10 && !isPM){
    finishBuzzerIndicator();
    rotateServo();
    Serial.println("Yehey!");
  }
  delay(1000);
}

void finishBuzzerIndicator(){
  int buzzerRepeat = 3;
  // play tone on buzzer to indicate uv sensor is finished
  for (int i = 0; i <= buzzerRepeat; i++){
    tone(buzzerPin, 1000, 500); 
    delay(500); 
    tone(buzzerPin, 2000, 500); 
    delay(500); 
  }
  noTone(buzzerPin); 
}
