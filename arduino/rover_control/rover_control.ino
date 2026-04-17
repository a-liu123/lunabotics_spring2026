#include <Servo.h>

const int spark1_pin = 9;  //switched these for our current setup
const int spark2_pin  = 10;
const int spark3_pin = 11;
const int spark4_pin = 12;

int reverseSpeed = 1400;
const int off = 1500;
int forwardSpeed = 1600;
int wait = 2000;

Servo spark1; 
Servo spark2;
Servo spark3;
Servo spark4;

int flip(int speed) { return off + (off - speed); }

void setup() {
  Serial.begin(9600);
  spark1.attach(spark1_pin, reverseSpeed, forwardSpeed);
  spark2.attach(spark2_pin, reverseSpeed, forwardSpeed);
  spark3.attach(spark3_pin, reverseSpeed, forwardSpeed);
  spark4.attach(spark4_pin, reverseSpeed, forwardSpeed);
}

void leftSide(int speed) {
  spark1.writeMicroseconds(flip(speed));  // pin 9 reversed
  spark3.writeMicroseconds(speed);
}

void rightSide(int speed) {
  spark2.writeMicroseconds(flip(speed));  // pin 10 reversed
  spark4.writeMicroseconds(speed);
}

void stop() {
  leftSide(off);
  rightSide(off);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'w') { 
      leftSide(forwardSpeed);
      rightSide(forwardSpeed);
    }
    else if (command == 's') { 
      leftSide(reverseSpeed);
      rightSide(reverseSpeed);
    }
    else if (command == 'a') { 
      leftSide(reverseSpeed);
      rightSide(forwardSpeed);
    }
    else if (command == 'd') { 
      leftSide(forwardSpeed);
      spark2.writeMicroseconds(flip(reverseSpeed));  // front right reverse
      spark4.writeMicroseconds(forwardSpeed);         // back right forward
    }
    else if (command == 'x') { 
      stop();
    }
  }
}