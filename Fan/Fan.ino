#include <IRremote.h>

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
  analogWrite(ENABLE,255);
  digitalWrite(DIRA,HIGH);
  digitalWrite(DIRB,LOW);

  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
      switch(results.value){
        case 16738455: analogWrite(ENABLE,1); 
        break;
        case 16724175: analogWrite(ENABLE,128);
        break;
        case 16718055: analogWrite(ENABLE,191);
        break;
        case 16743045: analogWrite(ENABLE,255); 
        break;
        case 16753245: analogWrite(ENABLE,HIGH); 
        break;
        case 16736925: analogWrite(ENABLE,LOW); 
        break;
    }
    delay(50);
    irrecv.resume();
  }
}
   
