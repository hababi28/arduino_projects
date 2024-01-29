#include <Servo.h>
#include <IRremote.h>

Servo plattform;
Servo first_arm;
Servo second_arm;
Servo grip;
Servo grip0;
Servo grip1;

// Initialize IRremote control 
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);

  plattform.attach(10);
  first_arm.attach(9);
  second_arm.attach(8);
  grip.attach(7);
  grip0.attach(6);
  grip1.attach(5);

  plattform.write(90);
  first_arm.write(100);
  second_arm.write(160);
  grip.write(120);
  grip0.write(180);
  grip1.write(0);

  irrecv.enableIRIn();

}

 
void loop(){
  // This part is for IR-remote control
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    /*
     * You may probably need to change the numbers in the switch method.
     * Just start the serial monitor and check which numbers you get and change it.
     * 
     * Here:
     * 
     * 7 and 9 are for plattform 
     * 2 and 5 are for the first arm
     * 1 and 4 are are for second arm
     * + and - are for the gripper
     */
    switch(results.value){
      case 16728765: plattform.write(plattform.read()+5); 
      break;
      case 16730805: plattform.write(plattform.read()-5);
      break;
      case 16724175: first_arm.write(first_arm.read()-5);
      break;
      case 16716015: first_arm.write(first_arm.read()+5); 
      break;
      case 16726215: second_arm.write(second_arm.read()+5);
      break;
      case 16718055: second_arm.write(second_arm.read()-5);
      break;
      case 16743045: grip.write(grip.read()-10); 
      break;
      case 16734885: grip.write(grip.read()+10); 
      break;
      case 16748655: grip0.write(grip0.read()+10), grip1.write(grip1.read()-10); 
      break;
      case 16769055: grip0.write(grip0.read()-10), grip1.write(grip1.read()+10); 
      break;
      case 16753245: reset(); 
      break;
    }
    delay(50);
    irrecv.resume();
  }
}

void reset() {
    plattform.write(90);
  first_arm.write(100);
  second_arm.write(160);
  grip.write(120);
  grip0.write(180);
  grip1.write(0);
}
