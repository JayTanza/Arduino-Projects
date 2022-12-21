
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  /*if(digitalRead(7) == 1)
  {
    digitalWrite(6, HIGH);   
    Serial.println("LED IS ON!");
  }
  else
  {
    Serial.println("LED IS OFF!");
    digitalWrite(6, LOW);    
  }*/

  if(Serial.available() > 0)
  {
    char letter = Serial.read();

    if(letter == '1' || digitalRead(7) == 1)
    {
      digitalWrite(6, HIGH);   
      Serial.println("LED IS ON!");
    }
    else if(letter == '0')
    {
      Serial.println("LED IS OFF!");
      digitalWrite(6, LOW);  
    }
    else
    {
      Serial.println("INVALID INPUT!");
    }
  }
}
