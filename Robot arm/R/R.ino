#include <Servo.h>

Servo myservo;
Servo myservo1;

int x_pin = 0;
int SW_pin = 2;
int val;
int switch0 = 0;

void setup() {
  myservo.attach(11);
  myservo.attach(10);
}

void loop() {
  if (switch0 == 0) {
    val = analogRead(x_pin);
    val = map(val, 0, 1023, 0, 180);
    myservo.write(val);
    delay(15);
      if (analogRead(SW_pin) == 1) {
        switch0 = 1;
      }
    }
  if (switch0 == 1) {
    val = analogRead(x_pin);
    val = map(val, 0, 1023, 0, 180);
    myservo1.write(val);
    delay(15);
      if (analogRead(SW_pin) == 1) {
        switch0 = 2;
      }
    }
}
