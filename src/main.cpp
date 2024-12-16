#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include "Joystick.cpp"
#include "Pot.cpp"
#include <SPI.h>
#include <Servo.h>

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
#define VerticalRightN 9
#define VerticalLeftP 10
#define VerticalRightN 11

// Controls

#define DriverLH A5 // A7
#define DriverLV A0 // A8
#define DriverRH 9
#define DriverRV 10

#define ArmJoy A0
#define EleJoy A1

Joystick armElbow(ArmJoy, EleJoy);

#define ClawPot A0

Pot claw(ClawPot);

int readJoystick(int pin);
int readPot(int pin);

Servo myServo;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  myServo.attach(3);
  
  Serial.begin(9600);
  Serial.println("I'm awake!");
  pinMode(LED_BUILTIN, OUTPUT);

  pwm.begin();
  
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
}

void loop() {
  // Serial.println(readPot(A0));
  delay(100);
  armElbow.update();
  claw.update();

  int horizontalBF = armElbow.xValue; // Horizontal Back and Forth
  int horizontalLR = armElbow.yValue; // Horizontal Left and Right

  digitalWrite(HorizontalLeftP, HIGH);
  digitalWrite(HorizontalLeftN, LOW);
  digitalWrite(HorizontalRightP, HIGH);
  digitalWrite(HorizontalRightN, LOW);

  delay(1000);

  digitalWrite(HorizontalLeftP, LOW);
  digitalWrite(HorizontalLeftN, HIGH);
  digitalWrite(HorizontalRightP, LOW);
  digitalWrite(HorizontalRightN, HIGH);

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