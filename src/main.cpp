#include <Arduino.h>

void setup() {
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}