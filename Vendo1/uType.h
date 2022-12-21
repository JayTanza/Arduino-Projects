#include <Servo.h> //Servo Library
#include <Wire.h> //Wire Library

class TType
{
  private:
    int PIN_BTN = 7; //Button pin# is 5
    int PIN_SERVO = 9; //Servo pin# is 9
    int PIN_LED = 10;
    
    byte ID = 0; //ID Variable is equal to 0
    unsigned int Price = 0; //Price for each modules
    unsigned int Money = 0; //Coin Variable
    unsigned int Change = 0; //change||sukli
   
    Servo myservo;
    
    public:
    void init(int aPin, int aServo, byte aID, unsigned int aPrice);
    void run(void onClick(byte aID, unsigned aPrice));
    void move(); 
};

void TType::init(int aPin, int aServo, byte aID, unsigned int aPrice)//Parameters
{
   PIN_SERVO = aServo; //Servo pin is assign to variable aServo
   PIN_BTN = aPin; //Button pin is assign to variable Button
   ID = aID; //ID is for the identification of cigarette stick
   Price = aPrice; //Price is for the value of each cigarette stick
   //Money = aMoney; //Value of coin will be inserted
   
   //Assigning Function of each pins
   myservo.attach(PIN_SERVO);// Function for Servo pin
   pinMode(PIN_BTN,INPUT_PULLUP); // Function for Button pin
   //attachInterrupt(0,coininserted,FALLING); //
}

void TType::run(void onClick(byte aID, unsigned aPrice))//Get the onClick Function from the Main class and assign its parameters to get values
{
   if(digitalRead(PIN_BTN) == LOW)
   {
      onClick(ID,Price);
      delay(600); 
   }    
}

void TType::move()
{
    myservo.write(0);
    delay(300);
    myservo.write(90);  
}
