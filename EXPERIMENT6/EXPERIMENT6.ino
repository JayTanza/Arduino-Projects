//int arr[] = {2,3,4,5,6,7,8,9};
const int led = A0;
void setup() {
  // put your setup code here, to run once:

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  pinMode(led,OUTPUT);
  pinMode(led,INPUT);
/*
  for(int i=0; i < 8; i++)
  {
    pinMode(arr[i], OUTPUT);
  }*/
}

void loop() 
{
  // put your main code here, to run repeatedly:

  int arr[5]={0,1,2,3,4};
  int leds = analogRead(led);

  digitalWrite(arr[2],HIGH); 
  delay(500); 
  digitalWrite(arr[2],LOW); 
  delay(500); 
  digitalWrite(arr[3],HIGH); 
  delay(500);
  digitalWrite(arr[3],LOW); 
  delay(500);
    
  if(leds<=200)
  {
     digitalWrite(arr[4],HIGH);
  }
  else
  {
     digitalWrite(arr[4],LOW);
  }

  digitalWrite(arr[4],HIGH); 
  delay(500);
  digitalWrite(arr[4],LOW); 
  delay(500);
  /*
  for(int i=0; i< 8; i++)
  {
    digitalWrite(arr[i],HIGH); 
    delay(500);   
    digitalWrite(arr[i],LOW); 
  }

  for(int i=7; i>0; i--)
  {
    digitalWrite(arr[i],HIGH); 
    delay(500);   
    digitalWrite(arr[i],LOW); 
  }
  */
}
  
  
