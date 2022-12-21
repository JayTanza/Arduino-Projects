class TType
{
  private:
  int pos = 0;
  int count = 0;
  int runTimes = 0;

  int PIN_STATE_S1 = HIGH;
  int PIN_STATE_S2 = HIGH;
  int PIN_STATE_S3 = HIGH;

  int PIN_SERVO = 9;
  
  public:
  void init(int astate, int bstate, int cstate, int aServo);
  void run();
  void SERVO_ROTATE_5();
  void SERVO_ROTATE_10();
  void SERVO_ROTATE_20();
};

void TType::init(int astate, int bstate, int cstate, int aServo)
{
  myservo.attach(PIN_SERVO);
  PIN_STATE_S1 = astate;
  PIN_STATE_S2 = bstate;
  PIN_STATE_S3 = cstate; 
  PIN_SERVO = aServo;

  pinMode(PIN_STATE_S1, INPUT_PULLUP);
  pinMode(PIN_STATE_S2, INPUT_PULLUP);
  pinMode(PIN_STATE_S3, INPUT_PULLUP);
  pinMode(PIN_SERVO, INPUT_PULLUP);
}

void TType::run()
{
  
}

void TType::SERVO_ROTATE_5()
{
  for(int runTimes = 0; runTimes < 5; runTimes++)
  {
    for(pos = 90; pos <= 0; pos++)
    {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 0; pos>= 90; pos--)     // goes from 80 degrees to 0 degrees
    {                               
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(5);
    }
  }
}

void TType::SERVO_ROTATE_10()
{
  for(int runTimes = 0; runTimes < 7; runTimes++)
  {
    for(pos = 90; pos <= 0; pos++)
    {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 0; pos>= 90; pos--)     // goes from 80 degrees to 0 degrees
    {                               
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(5);
    }
  }
}

void TType::SERVO_ROTATE_20()
{
  for(int runTimes = 0; runTimes < 10; runTimes++)
  {
    for(pos = 90; pos <= 0; pos++)
    {
      myservo.write(pos);
      delay(5);
    }
    for(pos = 0; pos>= 90; pos--)     // goes from 80 degrees to 0 degrees
    {                               
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(5);
    }
  }
}

}
