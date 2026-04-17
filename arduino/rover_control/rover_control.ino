#include <Servo.h>

const int spark1_pin = 10;
const int spark2_pin  = 11;
const int spark3_pin = 12;
const int spark4_pin = 13;


int reverseSpeed = 1400;
const int off = 1500;
int forwardSpeed = 1600;
int wait = 2000;


Servo spark1;
Servo spark2;
Servo spark3;
Servo spark4;

void setup() {
  Serial.begin(9600);
  spark1.attach(spark1_pin, reverseSpeed, forwardSpeed);
  spark2.attach(spark2_pin, reverseSpeed, forwardSpeed);
  spark3.attach(spark3_pin, reverseSpeed, forwardSpeed);
  spark4.attach(spark4_pin, reverseSpeed, forwardSpeed);
}

void leftSide(int speed) {
  spark1.writeMicroseconds(speed);
  spark3.writeMicroseconds(speed);
}

void rightSide(int speed) {
  spark2.writeMicroseconds(speed);
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
      rightSide(reverseSpeed);
    }
    else if (command == 'x') { 
      stop();
    }
  }
}