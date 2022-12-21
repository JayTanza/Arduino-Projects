String num1= "";
String num2= "";
void setup() {
Serial.begin(9600);//to display value on serial monitor
Serial.println(" SIMPLE CALACULATOR ");
Serial.println("---------\n");
}
void loop() {
  //input first number
  Serial.print("Enter the first number: ");
  while(Serial.available()==0)
  {
    //wait for input
    }
   num1= Serial.readString();
   Serial.println(num1);
// input 2nd number
Serial.print("Enter the second number: ");
   while(Serial.available()==0)
   {
   }
   num2= Serial.readString();
   Serial.println(num2);
   
    //operation menu
    Serial.println("\nOperation Menu:");
    Serial.println("'''''''''''''''");
    Serial.println("1) Addition");
    Serial.println("2)Subtraction");
    Serial.println("3)Multiplication");
    Serial.println("4)Division");
    Serial.println("5)Modulo");
Serial.print("Choose your operation: ");
    while(Serial.available()==0){
      
    }
    int choice = Serial.readString().toInt();
switch(choice){
      case 1:
      Serial.println("Addition");
      Serial.println(num1+"+"+num2+"="+ (num1.toInt()+num2.toInt())+"\n");
      break;
case 2:
      Serial.println("Subtraction");
      Serial.println(num1+"-"+num2+"="+(num1.toInt()- num2.toInt())+"\n");
      break;
case3:
      Serial.println("Multiplication");
      Serial.println(num1+"X"+num2+"="+ (num1.toInt()*num2.toInt())+"\n");
      break;
case 4:
      Serial.println("Division");
      Serial.println(num1+"/"+ num2+"="+(num1.toFloat() / num2.toFloat())+"\n");
      break;
      case 5:
Serial.println("Modulo");
      Serial.println(num1+"%"+num2+"="+(num1.toInt() % num2.toInt())+"\n");
break;
      default:
      Serial.println("INVALID OPERATION");
      break;
    }
    delay(1000);
    
}
