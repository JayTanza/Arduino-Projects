class Button
{
  private:
  int Button_1 = 8;
  
  public:
  void onButton(void onPushLED());
  void offButton(void offPushLED());
  void init(int Button1);  
};

void Button::init(int Button1)
{
  Button_1 = Button1;
  
  pinMode(Button_1,INPUT_PULLUP);
}

void Button::onButton(void onPushLED())
{
  if(digitalRead(Button_1) == LOW)
  {
    onPushLED();
  }
  delay(100);
}
void Button::offButton(void offPushLED())
{
  if(digitalRead(Button_1) == HIGH)
  {
    offPushLED();
  }
  delay(100);
}
