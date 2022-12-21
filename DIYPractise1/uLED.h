//u - unit library

class TLED{
  private:
    //unaccessable property
    int PIN_LED = 11; // int - starts from -4,-3,-2,-1,0,1,2,3,4,
    uint32_t timer = 0; //unint32 - starts from 0,1,2,3,4,5,6,7,8
    int interval = 100;
    bool blink = false;
    //millis - count the duration or timer
  
  public: 
    //accessable property
    void init(int aPin); //initialized the class with Declaration 
    void run(); //run the class   
    void setInterval(int aValue); //sets the interval of LED's
};

void TLED::init(int aPin){
  PIN_LED=aPin;
  pinMode(PIN_LED,OUTPUT);
}

void TLED::run(){
  if(timer != round(millis()/interval)){
    timer = round(millis()/interval);
    blink = !blink;//Turn on and off continously
    digitalWrite(PIN_LED,blink);
  }
}

void TLED::setInterval(int aValue){
  interval = aValue;
}
