#include <Arduino.h>

int pin = LED_BUILTIN;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}