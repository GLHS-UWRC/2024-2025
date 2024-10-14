#include <Arduino.h>

#define ClawSholder 0
#define ClawElbow 1
#define ClawGrip 2

#define HorizontalLeft 3
#define HorizontalRight 4
#define VerticalLeft 5
#define VerticalRight 6

void setup() {
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("Blinking...");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}