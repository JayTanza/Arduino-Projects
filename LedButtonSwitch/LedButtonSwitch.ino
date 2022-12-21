int PinButton1 =2;
 int val=0;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(PinButton1, INPUT);
  //initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  val = digitalRead(PinButton1);
  Serial.println(val);
  delay(100);
}
