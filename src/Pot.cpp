#include <Arduino.h>

int readPot(int pin);

class Pot
{
private:
    int usePin;

public:
    int value;

    void update() {
        value = readPot(usePin);
    }

    Pot(int pin) {
        usePin = pin;
        pinMode(usePin, INPUT);
    }
};