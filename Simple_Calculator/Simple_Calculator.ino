String input1 = "";
String input2 = "";

void setup() 
{
  Serial.begin(9600);
  Serial.println("MY CALCULATOR");
  Serial.println("-------------------------");
}

void loop() 
{
  //First number
  Serial.println("Enter the First number: ");
  while(Serial.available()==0)
  {
      
  }
  input1 = Serial.readString();
  Serial.println(input1);

  //Second number
  Serial.println("Enter the Second number: ");
  while(Serial.available()==0)
  {
      
  }
  input2 = Serial.readString();
  Serial.println(input2);

  int result = input1.toInt()+input2.toInt();
  Serial.print("The result is: ");
  Serial.print(result);
  Serial.print("\n");
  Serial.println("-------------------------");
  Serial.print("\n \n");
}
