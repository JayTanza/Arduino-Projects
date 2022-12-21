class Light 
{
  private:
  int _redLed = 10;
  int _greenLed = 9;
  int _yellowLed = 8;

  public:
  void init(int redLed, int greenLed, int yellowLed);
  void red();
  void green();
  void yellow(); 
  void off();
};

void Light::init(int redLed, int greenLed, int yellowLed)
{
  _redLed = redLed;
  _greenLed = greenLed;
  _yellowLed = yellowLed;

  pinMode(_redLed, OUTPUT);
  pinMode(_greenLed, OUTPUT);
  pinMode(_yellowLed, OUTPUT);
}

void Light::red()
{
  digitalWrite(_redLed,HIGH);
}

void Light::green()
{
  digitalWrite(_greenLed,HIGH);
}

void Light::yellow()
{
  digitalWrite(_yellowLed,HIGH);
}

void Light::off()
{
  digitalWrite(_redLed,LOW);
  digitalWrite(_greenLed,LOW);
  digitalWrite(_yellowLed,LOW);
}
