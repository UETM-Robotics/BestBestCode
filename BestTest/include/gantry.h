#ifndef GANTRY_H
#define GANTRY_H

#include <API.h>

void gantryGant();
void gantryArm();
void gantry_update();
bool isDeployed();

#define gantServ 2
#define gantServC 3
#define gant 7
#define dt 1000

#endif
