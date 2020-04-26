const int ledPin = 2;
const int motorPinA = 9;
const int motorPinB = 10;
const int switchPin = 12;

bool ledState = HIGH;
int elapsedTime;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPinA, OUTPUT);
  pinMode(motorPinB, OUTPUT);
}

void loop() {
  static int startTime = millis();
  elapsedTime = millis() - startTime;
  if(elapsedTime >= 500)  // If 1000ms (1 sec) time elapses the check method will give TRUE
  {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    startTime = millis();
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
