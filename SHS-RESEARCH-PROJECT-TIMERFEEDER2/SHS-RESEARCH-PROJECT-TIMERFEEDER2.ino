#include <Wire.h>
#include <DS3231.h>
#include <Servo.h>
#include <EEPROM.h>
#include <TimeLib.h>

DS3231 clock;
RTCDateTime dt;
Servo servo;

int buzzerPin = 3;
int eepromAddress = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Initialize DS3231");

  clock.begin();

  // Check if the DS3231 module has a valid date and time
  dt = clock.getDateTime();
  if (dt.year < 2000 || dt.year > 2099)
  {
    Serial.println("DS3231 date and time are not valid. Setting current time...");
    setTimeFromDS3231(); // Set the system time from DS3231

    // Store the system time in EEPROM
    time_t currentTime = now();
    EEPROM.put(eepromAddress, currentTime);
  }
  else
  {
    // Retrieve the system time from EEPROM
    time_t storedTime;
    EEPROM.get(eepromAddress, storedTime);
    setTime(storedTime);
  }

  servo.attach(9);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  dt = clock.getDateTime();

  mainFunction();

  delay(1000);
}

void rotateServo()
{
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);
  servo.write(0);
}

void mainFunction()
{
  // Convert to 12-hour format
  uint8_t hour = dt.hour;
  bool isPM = false;

  if (hour == 0)
  {
    hour = 12; // 12 midnight
  }
  else if (hour > 12)
  {
    hour -= 12;
    isPM = true;
  }

  // Display the time
  Serial.print("Real-Time-Data: ");
  Serial.print(dt.year);
  Serial.print("-");
  Serial.print(dt.month);
  Serial.print("-");
  Serial.print(dt.day);
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  if (dt.minute < 10)
  {
    Serial.print("0");
  }
  Serial.print(dt.minute);
  Serial.print(":");
  if (dt.second < 10)
  {
    Serial.print("0");
  }
  Serial.print(dt.second);
  Serial.print(" ");
  if (isPM)
  {
    Serial.print("PM");
  }
  else
  {
    Serial.print("AM");
  }
  Serial.println("");

  // Check if it's 1:00 AM or 5:00 PM or 8:32 AM
  if ((hour == 1 && dt.minute == 0 && dt.second == 0 && !isPM) ||
      (hour == 5 && dt.minute == 0 && dt.second == 0 && isPM) ||
      (hour == 8 && dt.minute == 32 && dt.second == 0 && !isPM))
  {
    finishBuzzerIndicator();
    rotateServo();
    Serial.println("Yehey!");
  }
}

void finishBuzzerIndicator()
{
  int buzzerRepeat = 3;
  // play tone
  for (int i = 0; i <= buzzerRepeat; i++)
  {
    tone(buzzerPin, 1000, 500);
    delay(500);
    tone(buzzerPin, 2000, 500);
    delay(500);
  }
  noTone(buzzerPin);
}

void setTimeFromDS3231()
{
  // Get the current time from the DS3231 module
  dt = clock.getDateTime();

  // Set the system time
  setTime(dt.hour, dt.minute, dt.second, dt.day, dt.month, dt.year - 2000);
}
