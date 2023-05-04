#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

// Set the time zone to GMT+8 (28800 seconds offset)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 28800, 60000); 
SoftwareSerial btSerial(D2, D3); // Rx,Tx

#define ssid "TanzaClan"
#define password "Tanza042001*"
#define firebaseHost "jayvis-iot-app-default-rtdb.firebaseio.com"
#define firebaseAuth "cSSdpXd88OdLUtCX9YowQvkMabxcT0KVO9t67FkV"
#define BTN D1
#define decrement_pin 4
#define Relay D4
#define Relay2 D5

#define EEPROM_SIZE 512

//Day/Weeks/Months
int Day = 1;
int Week = 1;
int Month = 1;
int INCOME_DAILY = 0;

// Define the address in EEPROM to store the Day/Weeks/Months
int DAY_COUNT_ADDRESS = 0;
int WEEK_COUNT_ADDRESS = 1;
int MONTH_COUNT_ADDRESS = 2;
int DAILY_COUNT_ADDRESS = 3;

//URL
String Url_TotalIncome = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/TotalIncome";
String Url_DailyIncome = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/DailyIncome/DayIncome";
String Url_DayIncome = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/DailyIncome/Day";
String Url_WeeklyIncome = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/WeeklyIncome/Week";
String Url_WaterLevel = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/WaterLevel";
String Machine_Status = "Registered Users/Xt8ZZFMRtwMG2iUerLpYicwxtjI3/Machine Status";
String data;

// Define the address in EEPROM to store the button count
const int countAddress = 0;
const unsigned long TIMER_INTERVAL = 120000;
unsigned long timer = 0;
unsigned long Daily_Income = 0;
unsigned long Total_Income = 0;
unsigned long count2 = 0;
unsigned int xDailyIncome = 0;
unsigned int xTotalIncome = 0;
unsigned int xDecrement = 0;
int value = 0;
int counter = 0; 
int x = 0;
bool i = 0;
bool buttonState = 0;         // current state of the button
bool lastButtonState = 0;     // previous state of the button
void setup() {
  Serial.begin(9600);     
  btSerial.begin(9600);
  EEPROM.begin(EEPROM_SIZE);
  pinMode(Relay, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(decrement_pin, INPUT_PULLUP);
  digitalWrite(Relay,HIGH);
  digitalWrite(Relay2,HIGH);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Firebase.begin(firebaseHost, firebaseAuth);
  Firebase.setBool(Machine_Status, false);
  timeClient.begin();
  timeClient.update();
  //Serial.println(timeClient.getFormattedTime());
  
  Day = EEPROM.read(DAY_COUNT_ADDRESS);
  Week = EEPROM.read(WEEK_COUNT_ADDRESS);
  Month = EEPROM.read(MONTH_COUNT_ADDRESS);
  INCOME_DAILY = EEPROM.read(DAILY_COUNT_ADDRESS);
  Day = 1;
}

void loop() {
  bool isOnline = WiFi.status() == WL_CONNECTED;
  Firebase.setBool(Machine_Status, isOnline);
  ConnectBT();
  Timer();
  Updater();
}

void Updater(){
  if (Serial.available() > 0){
    String data = Serial.readStringUntil('\n'); // Read a line of data
    if (data.startsWith("TotalIncome: ")) { // Check if data is a count value
      Total_Income = data.substring(13).toInt(); // Extract count value from data
      Serial.print("TotalIncome: ");
      Serial.println(Total_Income);
      TotalIncome(Total_Income);
    }else if(data.startsWith("DailyIncome: ")){
      Daily_Income = data.substring(13).toInt(); // Extract count value from data
      Serial.print("DailyIncome: ");
      Serial.println(Daily_Income);
      DailyIncome(Daily_Income);
      INCOME_DAILY = Daily_Income;
      EEPROM.write(DAILY_COUNT_ADDRESS, INCOME_DAILY);
      Serial.println(INCOME_DAILY);
    }else if (data.startsWith("WaterLevel: ")) { // Check if data is a count value
      count2 = data.substring(12).toInt(); // Extract count value from data
      Serial.print("Water Level: ");
      Serial.println(count2);
      WaterLevel(count2);
    }
  }
}

void TotalIncome(int aIncrement){
  xTotalIncome = aIncrement;
  Serial.println(xTotalIncome);
  Firebase.setInt(Url_TotalIncome,xTotalIncome);
  Serial.println(timeClient.getFormattedTime());
}

void DailyIncome(int aIncrement){
  xDailyIncome = aIncrement;
  Serial.println(xDailyIncome);
  Firebase.setInt(Url_DailyIncome,xDailyIncome);
  Serial.println(timeClient.getFormattedTime());
}

// function to decrement the value
void WaterLevel(unsigned int bDecrement) {
  xDecrement = bDecrement;
  Serial.println(xDecrement);
  Firebase.setInt(Url_WaterLevel,xDecrement);
  Serial.println(timeClient.getFormattedTime());
}

void Timer(){
  timeClient.update();
  //Every 3pm will update the dailyincome to 0 and daysincome is get updated
  if(timeClient.getHours() == 15 && timeClient.getMinutes() == 0 && timeClient.getSeconds() == 0) {
      Day = Day+1;
      EEPROM.write(DAY_COUNT_ADDRESS,Day);
      Firebase.setInt(Url_DayIncome+String(Day),INCOME_DAILY);
      Serial.println(timeClient.getFormattedTime());
      delay(1000);
      Serial.println("ResetDailyIncome");
      Serial.print("The Day counter: ");
      Serial.println(Day);
  }
  delay(1000);
}

void ConnectBT(){   
 while(btSerial.available()>0)
  {
    delay(10);
    char c=btSerial.read();
    if(c=='#')//end char
    {
      break;
    }
    data+=c;
  }
 Serial.println(data);// read the data from HC-05
 if(data=="1"){
   digitalWrite(Relay,LOW);
   digitalWrite(Relay2, HIGH);
   Serial.write("The machine is on");
 }
 else if(data=="0"){
   digitalWrite(Relay,HIGH);
   digitalWrite(Relay2, HIGH);
   Serial.write("The machine is off");
 }
 data="";//empty data
 delay(500); 
 buttonState = digitalRead(BTN);
  if (buttonState != lastButtonState)
  {
     if (buttonState == LOW)
     {
        digitalWrite(Relay2, !digitalRead(Relay2)); 
        digitalWrite(Relay,HIGH);
        Serial.println("Button1 Turn on");
     }
  }
  lastButtonState = buttonState;
}
