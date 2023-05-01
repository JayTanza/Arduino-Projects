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
    static bool isRelayOn;
    
    // initialize the value of income
    int INCOME_TOTAL = 0;
    int INCOME_DAILY = 0;
    int INCOME_WEEKLY = 0;
    int INCOME_MONTHLY = 0;
    int INCOME_RESETER = 0;
    int WATER_LEVEL = 100;
    
    // Define the address in EEPROM to store the button count
    int TOTAL_COUNT_ADDRESS = 0;
    int DAILY_COUNT_ADDRESS = 1;
    int WEEKLY_COUNT_ADDRESS = 2;
    int MONTHLY_COUNT_ADDRESS = 3;
    int WATER_LEVEL_ADDRESS = 4;
         
  public:
    void init(int aBtn, int aCoin, int aRelay, byte aID, unsigned int aPrice, unsigned int aInsertedCoin);
    void run(void onDispense(byte aID, unsigned aPrice));
    void Relay();
    static void countCoin();
    void TOTAL_INCOME();
    void DAILY_INCOME();
    void WATERLEVEL();
    void RESETER_INCOME();
    void DailyIncomeReseter();
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

  //Assigning Addresses for EEPROM
  INCOME_TOTAL = EEPROM.read(TOTAL_COUNT_ADDRESS);
  INCOME_DAILY = EEPROM.read(DAILY_COUNT_ADDRESS);
  INCOME_WEEKLY = EEPROM.read(WEEKLY_COUNT_ADDRESS);
  INCOME_MONTHLY = EEPROM.read(MONTHLY_COUNT_ADDRESS);
  WATER_LEVEL = EEPROM.read(WATER_LEVEL_ADDRESS);
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
        Serial.print("Insert a Coin");
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
  Serial.println("Dispensing...");
  digitalWrite(PIN_RELAY, LOW);
  delay(4000);
  digitalWrite(PIN_RELAY, HIGH);
  TOTAL_INCOME();
  DAILY_INCOME();
  WATERLEVEL();
  Serial.print("Coin: ");
  Serial.println(coin);
  if(coin <= 0){
    RESETER_INCOME();
    Serial.print("Coin: ");
    Serial.println(coin);
  }
}

void TType::TOTAL_INCOME(){
  INCOME_TOTAL = INCOME_TOTAL + 1;
  Serial.print("TotalIncome: ");
  Serial.println(INCOME_TOTAL);
  EEPROM.write(TOTAL_COUNT_ADDRESS, INCOME_TOTAL);
  delay(100);
}

void TType::DAILY_INCOME(){
  INCOME_DAILY = INCOME_DAILY + 1;
  Serial.print("DailyIncome: ");
  Serial.println(INCOME_DAILY);
  EEPROM.write(DAILY_COUNT_ADDRESS, INCOME_DAILY);
  delay(100);
}

void TType::WATERLEVEL(){
  WATER_LEVEL = WATER_LEVEL - 1;
  Serial.print("WaterLevel: ");
  Serial.println(WATER_LEVEL);
  EEPROM.write(WATER_LEVEL_ADDRESS, WATER_LEVEL);
  delay(100);
}

void TType::RESETER_INCOME(){
  INCOME_TOTAL = 0;
  INCOME_DAILY = 0;
  WATER_LEVEL = 100;
  Serial.print("Total_Income: ");
  Serial.println(INCOME_TOTAL);
  Serial.print("Daily_Income: ");
  Serial.println(INCOME_DAILY);
  Serial.print("Water_Level: ");
  Serial.println(WATER_LEVEL);
  EEPROM.write(TOTAL_COUNT_ADDRESS, INCOME_TOTAL);
  EEPROM.write(DAILY_COUNT_ADDRESS, INCOME_DAILY);
  EEPROM.write(WATER_LEVEL_ADDRESS, WATER_LEVEL);
  delay(100);
}

void TType::DailyIncomeReseter(){
  INCOME_DAILY = 0;
}
