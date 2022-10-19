// Include Libraries
#include "drivetrain.h"

// Define Constant Values
const double PHASE_ONE_SLOPE = ((127.0 - MINIMUM_MOTOR_POWER) / (127.0 - DEADZONE)) * PHASE_ONE_MULTIPLIER;

const double PHASE_TWO_ANALOG_VALUE = PHASE_SWITCH * (127.0 - DEADZONE) + DEADZONE;
const double PHASE_TWO_MOTOR_POWER = (PHASE_TWO_ANALOG_VALUE - DEADZONE) * PHASE_ONE_SLOPE + MINIMUM_MOTOR_POWER;

const double PHASE_TWO_SLOPE = (127.0 - PHASE_TWO_MOTOR_POWER) / (127.0 - PHASE_TWO_ANALOG_VALUE);

// Define Variables to Store Updated Information
int rawLeftAnalogValue;
int rawRightAnalogValue;

int currentLeftAnalogValue;
int currentRightAnalogValue;

int leftWheelSpeed;
int rightWheelSpeed;

// Define Header's Functions
void setLeftWheel(int speed) {
    motorSet(LEFT_MOTOR_PORT, speed);
}

void setRightWheel(int speed) {
    motorSet(RIGHT_MOTOR_PORT, -speed);
}

void updateDriveTrain() {
    // Update Values
    rawLeftAnalogValue = joystickGetAnalog(1, LEFT_ANALOG_AXIS);
    rawRightAnalogValue = joystickGetAnalog(1, RIGHT_ANALOG_AXIS);

    currentLeftAnalogValue = abs(rawLeftAnalogValue);
    currentRightAnalogValue = abs(rawRightAnalogValue);

    // Calculate Wheel Speeds
    if (currentLeftAnalogValue >= PHASE_TWO_ANALOG_VALUE) {
        leftWheelSpeed = (currentLeftAnalogValue - PHASE_TWO_ANALOG_VALUE) * PHASE_TWO_SLOPE + PHASE_TWO_MOTOR_POWER;

    } else if (currentLeftAnalogValue >= DEADZONE) {
        leftWheelSpeed = (currentLeftAnalogValue - DEADZONE) * PHASE_ONE_SLOPE + MINIMUM_MOTOR_POWER;

    } else {
        leftWheelSpeed = 0;
    }



    if (currentRightAnalogValue >= PHASE_TWO_ANALOG_VALUE) {
        rightWheelSpeed = (currentRightAnalogValue - PHASE_TWO_ANALOG_VALUE) * PHASE_TWO_SLOPE + PHASE_TWO_MOTOR_POWER;

    } else if (currentRightAnalogValue >= DEADZONE) {
        rightWheelSpeed = (currentRightAnalogValue - DEADZONE) * PHASE_ONE_SLOPE + MINIMUM_MOTOR_POWER;

    } else {
        rightWheelSpeed = 0;
    }

    // Determine Wheel Direction
    if (rawLeftAnalogValue < 0) {
        leftWheelSpeed *= -1;
    }

    if (rawRightAnalogValue < 0) {
        rightWheelSpeed *= -1;
    }

    // Set Wheel Speeds
    setLeftWheel(leftWheelSpeed);
    setRightWheel(rightWheelSpeed);
}