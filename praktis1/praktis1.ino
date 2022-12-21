int rem_credit = 69;
int change = 0;
void setup() 
{  
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    String cmd = Serial.readString();
    cmd.trim();
    rem_credit = cmd.toInt(); 
  }  
  if(rem_credit>=5)
  {
    rem_credit = rem_credit - 5;
    change++; 
    Serial.println(change);
  }
  else if(rem_credit>=10)
  {
    rem_credit = rem_credit - 10; 
    change++; 
    Serial.println(change);
  }
  else if(rem_credit>=20)
  {
    rem_credit = rem_credit - 20; 
    change++; 
    Serial.println(change);
  } 
  
}

/*void CoinCal(int price, int cash)
{
  if (Serial.available() > 0)
  {
    String cmd = Serial.readString();
    cmd.trim();
    rem_credit = cmd.toInt(); 
  } 
  
  if(cash / price >= 5)
  {
    int coin;
    coin = total / price;
    Serial.println(coin);
    cash = cash - (coin * price);
    return(cash);  
  }
}*/
