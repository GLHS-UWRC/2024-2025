#include <Arduino.h>

// Claw

#define ClawSholder 0
#define ClawElbow 1
#define ClawGrip 2

// Drive

#define HorizontalLeft 3
#define HorizontalRight 4
#define VerticalLeft 5
#define VerticalRight 6

// Controls

#define DriverLH 7 // Pins 4-7 is for the driver joysticks
#define DriverLV 8
#define DriverRH 9
#define DriverRV 10

#define ArmJoy 11
#define ElevJoy 12
#define ClawOpen 13
#define ClawClose 14

int readJoystick();

void setup() {
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);
}

  void loop() {
    Serial.println(readJoystick());
    delay(100); // Add a small delay to make the output readable
  }

  int readJoystick() {
    int rawValue = analogRead(A0);
    int mappedValue = map(rawValue, 0, 1023, -255, 255);
    if (abs(mappedValue) < 10 && abs(mappedValue) > -10) {
      mappedValue = 0;
    }
    return mappedValue;
  }