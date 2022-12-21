class TButton
{
  private:
  int _button1 = 7;

  public:
  void init(int button1);
  void push(void onPush());
};

void TButton::init(int button1)
{
  _button1 = button1;  

  pinMode(_button1,INPUT_PULLUP);
}

void TButton::push(void onPush())
{
  if(digitalRead(_button1) == LOW)
  {
    onPush();
  }
}
