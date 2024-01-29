#include <SR04.h>
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 11 
Servo arm;

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);//Initialization of Serial Port
   arm.attach(10);
   arm.write(180);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
   if (a > 30){
    arm.write(90);
   }
   if (a<30){
       arm.write(180);
  }
}
