// Include Libraries
#include "lift.h"

// Define Variables to Store Updated Information
bool leftTriggerIsHeld;
bool rightTriggerIsHeld;

bool leftTriggerWasHeld = false;
bool rightTriggerWasHeld = false;

int currentLiftSpeed = 0;

// Define Header's Functions
void setLift(int speed) {
    motorSet(LIFT_MOTOR_PORT, speed);
}

void updateLift() {
    leftTriggerIsHeld = joystickGetDigital(1, LIFT_DOWN_BUTTON_GROUP, LIFT_DOWN_BUTTON);
    rightTriggerIsHeld = joystickGetDigital(1, LIFT_UP_BUTTON_GROUP, LIFT_UP_BUTTON);

    if (leftTriggerIsHeld && !leftTriggerWasHeld) {
        leftTriggerWasHeld = true;
        currentLiftSpeed -= LIFT_SPEED;

    } else if (!leftTriggerIsHeld && leftTriggerWasHeld) {
        leftTriggerWasHeld = false;
        currentLiftSpeed += LIFT_SPEED;
    }

    if (rightTriggerIsHeld && !rightTriggerWasHeld) {
        rightTriggerWasHeld = true;
        currentLiftSpeed += LIFT_SPEED;

    } else if (!rightTriggerIsHeld && rightTriggerWasHeld) {
        rightTriggerWasHeld = false;
        currentLiftSpeed -= LIFT_SPEED;
    }

    setLift(currentLiftSpeed);
}
