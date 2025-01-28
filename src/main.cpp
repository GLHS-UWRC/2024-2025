#include <Arduino.h>
#include "Joystick.cpp"
#include "Pot.cpp"
#include <SPI.h>
#include <Servo.h>
#include <Wire.h>

// Servo Control

#define ServoControl A15

// Claw

#define ClawSholder 0
#define ClawElbow 1
#define ClawGrip 2

// Drive

#define HorizontalLeftP 6
#define HorizontalLeftN 7
#define HorizontalRightP 5
#define HorizontalRightN 4
#define VerticalLeftP 8
#define VerticalLeftN 9
#define VerticalRightP 10
#define VerticalRightN 11

// Test Motors

int TestArray[4][2] = {{HorizontalLeftN, HorizontalLeftP}, {HorizontalRightN, HorizontalRightP}, {VerticalLeftN, VerticalLeftP}, {VerticalRightN, VerticalRightP}};

// Controls

#define DriverLH A4
#define DriverLV A5
#define DriverRH A6
#define DriverRV A7

#define ArmJoy A0
#define EleJoy A1

Joystick armElbow(ArmJoy, EleJoy);

#define ClawPot A0

Pot claw(ClawPot);

int readJoystick(int pin);
int readPot(int pin);

Servo myservo;

void setup() {
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);

  myservo.attach(19);

  for (int i = 0; i < 4; i++) {
    int pin1 = TestArray[i][0];
    int pin2 = TestArray[i][1];

    Serial.print(pin1);
    Serial.print(" ");
    Serial.println(pin2);

    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);

    delay(1000);

    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);

    delay(1000);

    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
}

void loop() {
  // Serial.println(readPot(A0));
  delay(100);
  armElbow.update();
  claw.update();

  // int horizontalBF = armElbow.xValue; // Horizontal Back and Forth
  // int horizontalLR = armElbow.yValue; // Horizontal Left and Right

  // digitalWrite(VerticalLeftP, HIGH);
  // digitalWrite(VerticalLeftN, LOW);
  // digitalWrite(VerticalRightP, HIGH);
  // digitalWrite(VerticalRightN, LOW);

  // delay(1000);

  // digitalWrite(VerticalLeftP, LOW);
  // digitalWrite(VerticalLeftN, HIGH);
  // digitalWrite(VerticalRightP, LOW);
  // digitalWrite(VerticalRightN, HIGH);

  // delay(1000);

/*
  if (horizontalBF > 200) {
    Serial.println("Forward");
    analogWrite(HorizontalLeftP, HIGH);
    analogWrite(HorizontalLeftN, LOW);
    analogWrite(HorizontalRightP, HIGH);
    analogWrite(HorizontalRightN, LOW);
  } else if (horizontalBF < -200) {
    Serial.println("Backward");
    analogWrite(HorizontalLeftP, LOW);
    analogWrite(HorizontalLeftN, HIGH);
    analogWrite(HorizontalRightP, LOW);
    analogWrite(HorizontalRightN, HIGH);
  } else if (horizontalLR > 0) {
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
    Serial.println("Stop");
    analogWrite(HorizontalLeftP, LOW);
    analogWrite(HorizontalLeftN, LOW);
    analogWrite(HorizontalRightP, LOW);
    analogWrite(HorizontalRightN, LOW);
  }

  */
}

int readJoystick(int pin) {
  int rawValue = analogRead(pin);
  int mappedValue = map(rawValue, 0, 1023, -255, 255);
  if (abs(mappedValue) < 65) {
    mappedValue = 0;
  }
  return mappedValue;
}

int readPot(int pin) {
  int rawValue = analogRead(pin);
  int mappedValue = map(rawValue, 0, 1023, 0, 180);
  if (abs(mappedValue) < 10) {
    mappedValue = 10;
  }
  if (abs(mappedValue) > 170) {
    mappedValue = 170;
  }
  return mappedValue;
}