#ifndef LIFT_H
#define LIFT_H

#define LIFT_SPEED 75

#define LIFT_UP_BUTTON_GROUP 5
#define LIFT_DOWN_BUTTON_GROUP 6

#define LIFT_UP_BUTTON JOY_UP
#define LIFT_DOWN_BUTTON JOY_UP

#define LIFT_MOTOR_PORT 9

#include <API.h>

void updateLift();
void setLift(int speed);

#endif
