// Include Libraries
#include "dispenser.h"

// Define Constant Values
const int DISPENSER_SERVO_VALUE = DISPENSER_SERVO_ANGLE * (127.0 / 90.0) - 127;

// Define Variables to Store Updated Information
bool buttonWasPressed = false;
bool buttonIsPressed;

// Define Header's Functions
void activateDispenser() {
    motorSet(DISPENSER_SERVO_PORT, DISPENSER_SERVO_VALUE);
    delay(DISPENSER_SERVO_DELAY);
    motorSet(DISPENSER_SERVO_PORT, -127);
    delay(DISPENSER_SERVO_DELAY);
}

void updateDispenser() {
    buttonIsPressed = joystickGetDigital(1, DISPENSER_BUTTON_GROUP, DISPENSER_BUTTON);

    if (buttonIsPressed && !buttonWasPressed) {
        buttonWasPressed = true;
        activateDispenser();

    } else if (!buttonIsPressed && buttonWasPressed) {
        buttonWasPressed = false;
    }
}
