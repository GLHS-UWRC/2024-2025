#include <Arduino.h>

int pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin, 180);
  delay(1000);
  analogWrite(pin, 0);
}