/*
Based on the standard Aduino SoftareSerial example
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  
  // Set baud rate of ESP8266 to 9600 regardless of original setting
  set_esp8266_baud_rate(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

void set_esp8266_baud_rate(long int baud_rate){
  long int baud_rate_array[] = {1200,2400,4800,9600,19200,38400,57600, 74880,115200};
  String response;
  
  for (int i = 0; i<9;i++){
    mySerial.begin(baud_rate_array[i]);
    delay(50);
    mySerial.print("AT\r\n");
    delay(50);
    if (mySerial.available()) {
      response=mySerial.readString();
      if (response.length() > 7 && response.substring(7,9) == "OK") {
        mySerial.print("AT+UART_CUR=");
        mySerial.print(baud_rate);
        mySerial.print(",8,1,0,0\r\n");
        break;
      }
    }
  }
}
