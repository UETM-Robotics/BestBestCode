#ifndef DISPENSER_H
#define DISPENSER_H

#define DISPENSER_SERVO_ANGLE 90
#define DISPENSER_SERVO_DELAY 500

#define DISPENSER_BUTTON_GROUP 7
#define DISPENSER_BUTTON JOY_RIGHT

#define DISPENSER_SERVO_PORT 5

#include <API.h>

void updateDispenser();
void activateDispenser();

#endif
