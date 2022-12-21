#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <Servo.h>
#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);

byte kart[5] = {208,74,76,37,243};
Servo myservo;
boolean card;

void setup()
{

  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  myservo.attach(3);
  myservo.write(100);

}

void loop()
{

  if (rfid.isCard())
  {


    if (rfid.readCardSerial())
    {
      Serial.print("Found ID: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(",");
      Serial.print(rfid.serNum[1]);
      Serial.print(",");
      Serial.print(rfid.serNum[2]);
      Serial.print(",");
      Serial.print(rfid.serNum[3]);
      Serial.print(",");
      Serial.println(rfid.serNum[4]);

    }
    for (int i = 1; i < 5; i++)
    {
      if (rfid.serNum[0] == kart[0] && rfid.serNum[1] == kart[1] && rfid.serNum[2] == kart[2] && rfid.serNum[3] == kart[3] && rfid.serNum[4] == kart[4])
      {
        card = true;
      }
      else {
        card = false;
      }
    }
    if (card == true)
    {
      Serial.println("Correct Card");
      myservo.write(20);
      delay(15000);
      myservo.write(100);
    }
    else
    {
      Serial.println("Wrong Card");

    }
    rfid.halt();
  }
}
