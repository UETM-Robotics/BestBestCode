#include "gantry.h"

bool firstP = false;
bool firstH = false;
unsigned long counter = 0;
unsigned long begin = 0;
unsigned long end = 0;

bool deployed = false;
bool held = false;

void gantArm()
{
  if (joystickGetDigital(1, 8, JOY_UP) && !firstP) {
    firstP = true;

    if (counter == 0) {
      begin = millis();
    } else {
      end = millis();
      counter = -1;
    }

    counter++;

  } else if (!joystickGetDigital(1, 8, JOY_UP)) {
    firstP = false;
  }

  //fine tune time
  if (end - begin > 0 && end - begin < dt) {
    begin = 0;
    end = 0;

    if(!deployed)
    {
        motorSet(gantServ, 0);
    }

    else
    {
      motorSet(gantServ, -100);
    }

    deployed = !deployed;
  }

  if (joystickGetDigital(1, 8, JOY_DOWN) && !firstH)
  {
    firstH = true;
    held = !held;
  }

  else if (!joystickGetDigital(1, 8, JOY_DOWN))
  {
    firstH = false;
  }

  if (!held)
  {
    motorSet(gantServC, 127);
  }

  else {
    motorSet(gantServC, -127);
  }

  if(joystickGetDigital(1, 8, JOY_RIGHT) && deployed)
  {
    motorSet(gantServ, 127);
  }

  else if(deployed)
  {
    motorSet(gantServ, 0);
  }
}

void gantryGant()
{
	if(joystickGetDigital(1, 6, JOY_DOWN))
	{
		motorSet(gant, 127);
	}

	else if(joystickGetDigital(1, 5, JOY_DOWN))
	{
		motorSet(gant, -127);
	}

	else
	{
		motorSet(gant, 0);
	}
}

bool isDeployed()
{
  return deployed;
}

void gantry_update()
{
  gantryGant();
  gantryArm();
}
