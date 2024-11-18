#include <Arduino.h>
// #include <Adafruit_PWMServoDriver.h>
#include "Joystick.cpp"

// Servo Control

#define ServoControl A15

// Claw

#define ClawSholder 0
#define ClawElbow 1
#define ClawGrip 2

// Drive

#define HorizontalLeftP 3
#define HorizontalLeftN 3
#define HorizontalRightP 4
#define HorizontalRightN 4
#define VerticalLeftP 5
#define VerticalRightN 6
#define VerticalLeftP 5
#define VerticalRightN 6

// Controls

#define DriverLH A1 // A7
#define DriverLV A0 // A8
#define DriverRH 9
#define DriverRV 10

#define ArmJoy 11
#define ElevJoy 12
#define ClawOpen 13
#define ClawClose 14

int readJoystick(int pin);

void setup() {
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);
}

  void loop() {
    Serial.println(readJoystick(A0));
    delay(100);

    int horizontalBF = readJoystick(DriverLV); // Horizontal Back and Forth

    if (horizontalBF > 0) {
      Serial.println("Forward");
      analogWrite(HorizontalLeftP, HIGH);
      analogWrite(HorizontalLeftN, LOW);
      analogWrite(HorizontalRightP, HIGH);
      analogWrite(HorizontalRightN, LOW);
    } else if (horizontalBF < 0) {
      Serial.println("Backward");
      analogWrite(HorizontalLeftP, LOW);
      analogWrite(HorizontalLeftN, HIGH);
      analogWrite(HorizontalRightP, LOW);
      analogWrite(HorizontalRightN, HIGH);
    } else {
      Serial.println("Stop");
      analogWrite(HorizontalLeftP, LOW);
      analogWrite(HorizontalLeftN, LOW);
      analogWrite(HorizontalRightP, LOW);
      analogWrite(HorizontalRightN, LOW);
    }

     int horizontalLR = readJoystick(DriverLH); // Horizontal Left and Right

    if (horizontalLR > 0) {
      Serial.println("Right");
      analogWrite(HorizontalLeftP, HIGH);
      analogWrite(HorizontalLeftN, LOW);
      analogWrite(HorizontalRightP, LOW);
      analogWrite(HorizontalRightN, HIGH);
    } else if (horizontalLR < 0) {
      Serial.println("Left");
      analogWrite(HorizontalLeftP, LOW);
      analogWrite(HorizontalLeftN, HIGH);
      analogWrite(HorizontalRightP, HIGH);
      analogWrite(HorizontalRightN, LOW);
    } else {
      Serial.println("Straight");
      analogWrite(HorizontalLeftP, LOW);
      analogWrite(HorizontalLeftN, LOW);
      analogWrite(HorizontalRightP, LOW);
      analogWrite(HorizontalRightN, LOW);
    }
  }

  int readJoystick(int pin) {
    int rawValue = analogRead(pin);
    int mappedValue = map(rawValue, 0, 1023, -255, 255);
    if (abs(mappedValue) < 10 && abs(mappedValue) > -10) {
      mappedValue = 0;
    }
    return mappedValue;
  }