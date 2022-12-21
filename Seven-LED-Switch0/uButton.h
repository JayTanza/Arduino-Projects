class Button
{
  private:
  int Button_1 = 8;
  
  public:
  void onButton(void onPushLED(),void offPushLED());
  void init(int Button1);  
};

void Button::init(int Button1)
{
  Button_1 = Button1;

  pinMode(Button_1,INPUT_PULLUP);
}

void Button::onButton(void onPushLED(),void offPushLED())
{
  if(digitalRead(Button_1) == HIGH)
  {
    onPushLED();
  }
  else
  {
    offPushLED();
  }
}
