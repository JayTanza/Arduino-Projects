#include <Servo.h>
class TType{
  private:
    int PIN_BTN = 5;
    int PIN_SERVO = 9;
    byte ID = 0;
    unsigned int Price = 0;
    Servo myservo;
  public:
    void init(int aPin, int aServo, byte aID, unsigned int aPrice);
    void run(void onClick(byte aID, unsigned aPrice));  
    void move();
};

void TType::init(int aPin, int aServo, byte aID, unsigned int aPrice){
  PIN_SERVO = aServo;
  PIN_BTN = aPin;
  ID = aID;
  Price = aPrice;
  myservo.attach(PIN_SERVO);
  pinMode(PIN_BTN, INPUT_PULLUP);
}

void TType::move(){
  myservo.write(0);
  delay(300);
  myservo.write(90);
}

void TType::run(void onClick(byte aID, unsigned aPrice)){
  if (digitalRead(PIN_BTN) == LOW){
    onClick(ID, Price);
    delay(600);
  }
}
