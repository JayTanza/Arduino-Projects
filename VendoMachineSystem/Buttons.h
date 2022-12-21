
class TButtons{
  public:
  int buttonpin1 = 5;
  int buttonpin2 = 6;
  int buttonpin3 = 7;
  
  void init();
  void run();

  private:
  
};

void TButtons::init(){
  pinMode(buttonpin1, INPUT_PULLUP);
  pinMode(buttonpin2, INPUT_PULLUP);
  pinMode(buttonpin3, INPUT_PULLUP);
}
void TButtons::run(){
  
}
