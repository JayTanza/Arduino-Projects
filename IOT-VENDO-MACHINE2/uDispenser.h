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
    static bool isRelayOn;
         
  public:
    void init(int aBtn, int aCoin, int aRelay, byte aID, unsigned int aPrice, unsigned int aInsertedCoin);
    void run(void onDispense(byte aID, unsigned aPrice));
//    void Relay(int a, int b);
    void Relay();
    static void countCoin();
};

bool TType::isRelayOn = false; // Definition of static member variable

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
  attachInterrupt(0, countCoin, FALLING);
  digitalWrite(PIN_RELAY, HIGH);
  Display_Main();
}

void TType::run(void onDispense(byte aID, unsigned aPrice)){
  digitalWrite(PIN_RELAY, HIGH);
  Display_Main();
  if(!isRelayOn){
    int buttonState = digitalRead(PIN_BUTTON);
    if(buttonState == LOW){
      if(coin > 0){
        coinDispensed();
        isRelayOn = true;
        Relay();
        DisplayLoading();
        delay(4000);
        isRelayOn = false;
        Display_Main();
      }else{
        Display_InsertCoin();
        delay(2000);
        Display_Main();
      }
    }
  }
}

static void TType::countCoin(){
  if(!TType::isRelayOn){
    coinInserted();
  }
}

void TType::Relay(){
//  int TotalIncome = a;
  Serial.println("Dispensing...");
  digitalWrite(PIN_RELAY, LOW);
  delay(4000);
  digitalWrite(PIN_RELAY, HIGH);
//  Serial.print("TotalIncome: ");
//  Serial.println(a);
//  Serial.print("Water Level: ");
//  Serial.println(b);
}
