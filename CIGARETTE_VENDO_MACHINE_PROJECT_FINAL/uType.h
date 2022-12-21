#include <Servo.h> 
#include <Wire.h> 

class TType
{
  private:
    int PIN_BTN_CANCEL = A1;
     
    int PIN_BTN_1 = 7;

    int PIN_LED_1 = 10;
    
    int PIN_SERVO = 9;

    int PIN_SENSOR = A0;
    
    byte ID = 0;

    int val = 0;
    
    unsigned int Price = 0;
    unsigned int Money = 0; 
    unsigned int Change = 0; 

    Servo myservo;
    
    public:
    void init(int aPin, int aServo, int aLed, int aSensor, byte aID, unsigned int aPrice);
    void run(void onClick(byte aID, unsigned aPrice));
    //void onDispense(unsigned aChange);
    void LED(void onLight(byte aID, unsigned aPrice));
    void Servomove(); 
    void Sensor(); 
    void ledon();
    void ledoff();
};

void TType::init(int aPin, int aServo, int aLed, int aSensor, byte aID, unsigned int aPrice)//Parameters
{
   PIN_LED_1 = aLed;
   PIN_SERVO = aServo;
   PIN_BTN_1 = aPin; 
   PIN_SENSOR = aSensor;
   ID = aID;
   Price = aPrice;
   
   //Assigning Function of each pins
   myservo.attach(PIN_SERVO);
   pinMode(PIN_BTN_1, INPUT_PULLUP);
   pinMode(PIN_LED_1, OUTPUT);
   pinMode(PIN_SENSOR, INPUT);
}

void TType::run(void onClick(byte aID, unsigned aPrice))
{ 
   if(digitalRead(PIN_BTN_1) == LOW)
   {   
      onClick(ID,Price);
      delay(1000); 
   }        
}

/*void TType::onDispense(unsigned aChange)
{
  if (Serial.available()>0)
  {
    String cmd= Serial.readString();
    cmd.trim();
    digitalWrite(PIN_LED_1, LOW);
    if (cmd.equals("done")){
      Serial.println("Yey!");
      digitalWrite(PIN_LED_1, HIGH);
    }
  }
    
  if(digitalRead(PIN_BTN_1) == LOW)
   {   
      digitalWrite(PIN_LED_1, LOW);
      Serial.println(aChange);
      delay(1000); 
   } 
}*/

void TType::Servomove()
{
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    //myservo.write(0);
}

void TType::Sensor()
{
  if(digitalRead(PIN_SENSOR) == HIGH)
  {
    digitalWrite(PIN_LED_1,HIGH);     
  }
  else
  {
    digitalWrite(PIN_LED_1,LOW);  
  }
  val = analogRead(PIN_SENSOR);
  //Serial.println(val);
  delay(100);
}

void TType::LED(void onLight(byte aID, unsigned aPrice))
{
    onLight(ID,Price);
}

void TType::ledon()
{
  digitalWrite(PIN_LED_1,HIGH);
}

void TType::ledoff()
{
  digitalWrite(PIN_LED_1,LOW);
}
