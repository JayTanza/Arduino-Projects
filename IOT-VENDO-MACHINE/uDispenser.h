#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd2(0x27,16,2);

class TType{
  private:
    //Assign Pins
    int PIN_COIN = 2;
    int PIN_BUTTON = 7;
    int PIN_RELAY = 3;
    //Declaring assign value
    byte ID = 0;
    unsigned int Price = 0;
    unsigned int InsertedCoin = 0;
    bool isRelayOn = false;
         
  public:
    void init(int aBtn, int aCoin, int aRelay, byte aID, unsigned int aPrice, unsigned int aInsertedCoin);
    void run(void onDispense(byte aID, unsigned aPrice));
    void Relay(int a, int b);
};

void TType::init(int aBtn, int aCoin, int aRelay, byte aID, unsigned int aPrice, unsigned int aInsertedCoin){
  //Fetching assign variable to parameters
  PIN_BUTTON = aBtn;
  PIN_COIN = aCoin;
  PIN_RELAY = aRelay;
  ID = aID;
  Price = aPrice;
  InsertedCoin = aInsertedCoin;
   
  //Assign function of each pins
  pinMode(PIN_COIN, INPUT_PULLUP);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_RELAY, OUTPUT);
  attachInterrupt(0, InsertedCoin, FALLING);
  digitalWrite(PIN_RELAY, HIGH);
}

void TType::run(void onDispense(byte aID, unsigned aPrice)){
  if(digitalRead(PIN_BUTTON) == LOW && !isRelayOn){
    onDispense(ID,Price);
  }
}

void TType::Relay(int a, int b){
  int TotalIncome = a;
  Serial.println("Dispensing...");
  digitalWrite(PIN_RELAY, LOW);
  delay(4000);
  digitalWrite(PIN_RELAY, HIGH);
  Serial.print("TotalIncome: ");
  Serial.println(a);
  Serial.print("Water Level: ");
  Serial.println(b);
}
