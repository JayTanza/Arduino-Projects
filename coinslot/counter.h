#include <Servo.h>


Servo myservo;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

#define servopin 9
#define coinpin 2

class Counters{
  private:
    //int servopin = 9;
    //int coinpin = 12;

    int coinSlotSignal;
    int coinCount = 0;
    int requiredCoins = 5;
    boolean coinInserted = false;
    volatile byte state = LOW;
    volatile int coins = 0;
    
  public:  
    void init();
    void run();
    void blink();
    void Insertedcoin();
};

void Counters::init(){
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(coinpin, INPUT_PULLUP);
  myservo.attach(servopin);
  delay(1000);
  myservo.write(90);  
}

void Counters::run(){
  // put your main code here, to run repeatedly:
  Serial.println(coinCount);
}

void Counters::Insertedcoin(){
    while(!coinInserted){
      //attachInterrupt(0,FALLING);
      coinCount += 1;
      Serial.println(coinCount);
      lcd.setCursor(0,0);
      lcd.print(coinCount);
      coinInserted = true;
     
  }
  
  while(coinInserted){
//      attachInterrupt(0,FALLING);
      coinInserted = false;  
  }
  
  if(coinInserted >= 1){
    delay(1500);
    myservo.write(0);
    delay(500);
    coinCount = 0;
    delay(2000);  
    myservo.write(180);
  } 
}
