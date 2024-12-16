#include <Arduino.h>

int readJoystick(int pin);

class Joystick
{
private:
    int xp;
    int yp;

public:
    int xValue;
    int yValue;

    void update() {
        xValue = readJoystick(xp);
        yValue = readJoystick(yp);
    }

    Joystick(int xPin, int yPin) {
        xp = xPin;
        yp = yPin;
        pinMode(xp, INPUT);
        pinMode(yp, INPUT);
    }
};