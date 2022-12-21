class Button
{
  private:
  int _button1 = 7;
  int _button2 = 6;
  int _button3 = 5;
  
  public:
  void init(int button1, int button2, int button3);
  void pushRED(void onPushRED(),void offPush());
  void pushGREEN(void onPushGREEN(),void offPush());
  void pushYELLOW(void onPushYELLOW(),void offPush());
};

void Button::init(int button1, int button2, int button3)
{
  _button1 = button1;
  _button2 = button2;
  _button3 = button3;

  pinMode(_button1,INPUT_PULLUP);
  pinMode(_button2,INPUT_PULLUP);
  pinMode(_button3,INPUT_PULLUP);
}

void Button::pushRED(void onPushRED(),void offPush())
{
  if(digitalRead(_button1) == LOW)
  {
    onPushRED();
  }
  else
  {
    offPush();
  }
}

void Button::pushGREEN(void onPushGREEN(),void offPush())
{
  if(digitalRead(_button2) == LOW)
  {
    onPushGREEN();
  }
  else
  {
    offPush();
  }
}

void Button::pushYELLOW(void onPushYELLOW(),void offPush())
{
  if(digitalRead(_button3) == LOW)
  {
    onPushYELLOW();
  }
  else
  {
    offPush();
  }
}
