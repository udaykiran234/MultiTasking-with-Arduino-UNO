
#include<Metro.h>

const int ledPin = 10;
const int motorPinA = 11;
const int motorPinB = 12;
const int switchPin = 13;

boolean ledState = false;

Metro ledMetro = Metro(1000);  // Creating an object for Metro Class to use the methods in it

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop() {
  if(ledMetro.check())  // If 1000ms (1 sec) time elapses the check method will give TRUE
  {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
  if(digitalRead(switchPin) == HIGH)
  {
    digitalWrite(motorPinA, HIGH);
    digitalWrite(motorPinB, LOW);
  }
  else
  {
    digitalWrite(motorPinA, LOW);
    digitalWrite(motorPinB, HIGH);
  }
}
