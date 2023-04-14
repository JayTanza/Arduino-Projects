#include <EEPROM.h>

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
    unsigned long buttonPressStartTime;
    unsigned int value = 0;
    unsigned int countAddress = 0;
       
  public:
    void init(int aBtn, int aCoin, int aRelay, byte aID, unsigned int aPrice, unsigned int aInsertedCoin);
    void run(void onClick(byte aID, unsigned aPrice, unsigned aCoin));
    void Relay();
    void increment(unsigned int aCoins);
    //void decrement(unsigned int aCoins);
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
  value = EEPROM.read(countAddress);
}

void TType::run(void onClick(byte aID, unsigned aPrice, unsigned aCoin)){
  if(digitalRead(PIN_BUTTON) == LOW && !isRelayOn){
    onClick(ID,Price,coin);
    if(coin >= Price || coin == 1){
      increment(Price); 
    }
    delay(10);
    buttonPressStartTime = millis();  // record the start time of the button press
    digitalWrite(PIN_RELAY, HIGH);  // turn on the relay
    isRelayOn = true;  // update the flag to indicate that the relay is on
  }
  if (isRelayOn && millis() - buttonPressStartTime >= 3000) {  // check if the relay is on for more than 3 seconds
      digitalWrite(PIN_RELAY, LOW);  // turn off the relay
      isRelayOn = false;  // update the flag to indicate that the relay is off
  }
}

void TType::Relay(){
    buttonPressStartTime = millis();  // record the start time of the button press
    digitalWrite(PIN_RELAY, HIGH);  // turn on the relay
    isRelayOn = true;  // update the flag to indicate that the relay is on
    if (isRelayOn && millis() - buttonPressStartTime >= 3000) {  // check if the relay is on for more than 3 seconds
      digitalWrite(PIN_RELAY, LOW);  // turn off the relay
      isRelayOn = false;  // update the flag to indicate that the relay is off
    }
}

void TType::increment(unsigned int aCoins) {
  value = value+aCoins;
  Serial.print("Count: ");
  Serial.println(value);
  delay(100);
  EEPROM.write(countAddress, value);
}
