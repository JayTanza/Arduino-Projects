class TNoiseDetector{
  private:
    int PIN_TYPE_SOUND = A0;
    int PIN_TYPE_BUZZER = 3;
    byte ID = 0;
    
  public:  
    void init(int aSound, int aBuzzer, byte aID);
    void OnNoiseDetector(void onNoiseDetected(byte aID));
    void finishBuzzerIndicator();
};

void TNoiseDetector::init(int aSound, int aBuzzer, byte aID){
  //Fetching assign variable to parameters
  PIN_TYPE_SOUND = aSound;
  PIN_TYPE_BUZZER = aBuzzer;
  ID = aID;
  //Assign function of each pins
  pinMode(PIN_TYPE_SOUND, INPUT);
  pinMode(PIN_TYPE_BUZZER, OUTPUT);    
}

void TNoiseDetector::OnNoiseDetector(void onNoiseDetected(byte aID)){
  int soundValue = digitalRead(PIN_TYPE_SOUND);
  if (soundValue == HIGH){
    onNoiseDetected(ID);
    Serial.println("Clap detected!");
    finishBuzzerIndicator();
  }
}

void TNoiseDetector::finishBuzzerIndicator(){
  int buzzerRepeat = 3;
  // play tone on buzzer to indicate uv sensor is finished
  for (int i = 0; i <= buzzerRepeat; i++){
    tone(PIN_TYPE_BUZZER, 1000, 500); 
    delay(500); 
    tone(PIN_TYPE_BUZZER, 2000, 500); 
    delay(500); 
  }
  noTone(PIN_TYPE_BUZZER); 
}
