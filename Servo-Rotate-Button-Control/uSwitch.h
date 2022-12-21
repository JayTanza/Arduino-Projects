class TSwitch
{
  private:
  int PIN_SWITCH_1 = 2;
  
  public:
  void init(int aSwitch);
  void push(void onPush());
};

void TSwitch::init(int aSwitch)
{
  PIN_SWITCH_1 = aSwitch;
  pinMode(PIN_SWITCH_1,INPUT_PULLUP);
}

void TSwitch::push(void onPush())
{
  if(digitalRead(PIN_SWITCH_1) == LOW)
  {
    onPush();
  }
}
