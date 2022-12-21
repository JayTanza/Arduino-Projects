class LED
{
  private:
  int LED_1 = 9;
  int LED_2 = 2;
  int LED_3 = 3;
  int LED_4 = 4;
  int LED_5 = 5;
  int LED_6 = 6;
  int LED_7 = 7;
  int BUTTON_1 = 7;
  
  public:
  void onLED();
  void offLED();
  void onButton();
  void init(int LED1,int LED2,int LED3,int LED4,int LED5,int LED6,int LED7,int Button1);  
};

void LED::init(int LED1,int LED2,int LED3,int LED4,int LED5,int LED6,int LED7,int Button1)
{
  LED_1 = LED1;
  LED_2 = LED2;
  LED_3 = LED3;
  LED_4 = LED4;
  LED_5 = LED5;
  LED_6 = LED6;
  LED_7 = LED7;
  BUTTON_1 = Button1;
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
  pinMode(LED_6, OUTPUT);
  pinMode(LED_7, OUTPUT);
  pinMode(BUTTON_1,INPUT_PULLUP);
}

void LED::onButton()
{
  if(digitalRead(BUTTON_1) == HIGH)
  {
    onLED();
  }
  else
  {
    offLED();
  }
}

void LED::onLED()
{
    digitalWrite(LED_1,HIGH);
    digitalWrite(LED_2,HIGH);
    digitalWrite(LED_3,HIGH);
    digitalWrite(LED_4,HIGH);
    digitalWrite(LED_5,HIGH);
    digitalWrite(LED_6,HIGH);
    digitalWrite(LED_7,HIGH);
}

void LED::offLED()
{
    digitalWrite(LED_1,LOW);
    digitalWrite(LED_2,LOW);
    digitalWrite(LED_3,LOW);
    digitalWrite(LED_4,LOW);
    digitalWrite(LED_5,LOW);
    digitalWrite(LED_6,LOW);
    digitalWrite(LED_7,LOW);
}
