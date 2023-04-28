#include <Servo.h>
#include <Wire.h>

class TChanger{
    private:
    int PIN_BUZZER = 5;
    int PIN_BTN_CHANGER = 6;
    int PIN_SERVO = 9;
    int PIN_SENSOR = 8;  
    bool isDone = true;
    byte ID = 0;
    unsigned int Price = 0;
    unsigned int Button_State = 0;
    unsigned int PrevButton_State = 0;
    Servo myservo;

    public:
    void init(int aChangerBtn, int aServo, int aSensor, int aBuzzer, byte aID, unsigned int aPrice);
    void run(void onChange(byte aID, unsigned aPrice));
    void Servomove();
    void finishBuzzerIndicator();
};

void TChanger::init(int aChangerBtn, int aServo, int aSensor, int aBuzzer, byte aID, unsigned int aPrice){
  PIN_BUZZER = aBuzzer;
  PIN_BTN_CHANGER = aChangerBtn;
  PIN_SERVO = aServo;
  PIN_SENSOR = aSensor;
  ID = aID;
  Price = aPrice;

  myservo.attach(PIN_SERVO);
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_BTN_CHANGER, INPUT_PULLUP);
  pinMode(PIN_BUZZER, OUTPUT);
}

void TChanger::run(void onChange(byte aID, unsigned aPrice)){
    if(digitalRead(PIN_SENSOR) == LOW)
    {
      onChange(ID,Price); 
      delay(5); 
    }
}

void TChanger::Servomove(){
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
}

void TChanger::finishBuzzerIndicator(){
  int buzzerRepeat = 3;
  // play tone on buzzer to indicate uv sensor is finished
  for (int i = 0; i <= buzzerRepeat; i++){
    tone(PIN_BUZZER, 1000, 500); 
    delay(500); 
    tone(PIN_BUZZER, 2000, 500); 
    delay(500); 
  }
  noTone(PIN_BUZZER); 
}
