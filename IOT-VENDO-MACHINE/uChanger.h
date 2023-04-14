#include <Servo.h>
#include <Wire.h>

class TChanger{
    private:
    int PIN_SERVO = 9;
    int PIN_SENSOR = 8;  
    byte ID = 0;
    unsigned int Price = 0;
    Servo myservo;

    public:
    void init(int aServo, int aSensor, byte aID, unsigned int aPrice);
    void run(void onChange(byte aID, unsigned aPrice));
    void Servomove();
};

void TChanger::init(int aServo, int aSensor, byte aID, unsigned int aPrice){
  PIN_SERVO = aServo;
  PIN_SENSOR = aSensor;
  ID = aID;
  Price = aPrice;

  myservo.attach(PIN_SERVO);
  pinMode(PIN_SENSOR, INPUT_PULLUP);
}

void TChanger::run(void onChange(byte aID, unsigned aPrice)){
  if(digitalRead(PIN_SENSOR) == LOW)
    {
      onChange(ID,Price);
      delay(10); 
    }
}

void TChanger::Servomove(){
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
}
