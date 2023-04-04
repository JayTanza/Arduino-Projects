#include <SoftwareSerial.h>
#include <Servo.h> 

int RX_pin = 4;
int TX_pin = 2;
int PIN_SERVO = 9;
int RELAY_PIN = 8;

SoftwareSerial BTSerial(D2, D3);
Servo myservo;

String BT_data;
String Arduino_data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  myservo.attach(PIN_SERVO);
  pinMode(RELAY_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available() > 0){
    BT_data = BTSerial.read();//Read the data from the bluetooth terminal
    Serial.println(BT_data);  
    if(BT_data == "1"){
//      myservo.write(0);
//      delay(1000);
//      myservo.write(90);
      Serial.write("The Machine is now Turning on.");
      digitalWrite(RELAY_PIN, HIGH);
      delay(500);
    }
    if(BT_data == "0"){
      Serial.write("The Machine is now Turning off.");
      digitalWrite(RELAY_PIN, LOW);
      delay(500);
    }
  }
  if(Serial.available()){
    Arduino_data = Serial.readString();//Read the data from the arduino
    BTSerial.println(Arduino_data);    
  }
}
