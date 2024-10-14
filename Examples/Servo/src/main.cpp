#include <Arduino.h>

int pin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin, 180);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  analogWrite(pin, 0);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}