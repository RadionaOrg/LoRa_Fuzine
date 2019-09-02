//KY017 Mercury open optical module
int Led = 2 ;// define LED Interface
int buttonpin = 4; // define the mercury tilt switch sensor interface
int val ;// define numeric variables val
int count = 0;
bool state, prevState;

void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the mercury tilt switch sensor output interface
  Serial.begin(115200);
}
void loop ()
{
  val = digitalRead (buttonpin) ;// read the values assigned to the digital interface 3 val
  
  if (val == LOW){
    state = true;
    if( state != prevState ){
      count ++;
      Serial.println(count);
      digitalWrite (Led, HIGH);  
      prevState = state;
      delay(1000);
    }
  }
  else{
    digitalWrite (Led, LOW);
    state = false;
    prevState = false;
  }
}
