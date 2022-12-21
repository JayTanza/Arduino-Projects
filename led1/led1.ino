int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 9;

int button1 = 8;
int button2 = 11;
int status = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);

  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
}
void loop() 
{
  if(digitalRead(button1) == true)
  {
    status = !status;
    digitalWrite(LED1,status);
    digitalWrite(LED2,status);
    digitalWrite(LED3,status);
    digitalWrite(LED4,status);
    digitalWrite(LED5,status);
    digitalWrite(LED6,status);
    digitalWrite(LED7,status);
  }while(digitalRead(button1) == true);
  delay(50);
}
