/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "joyDigitalU.h"
#include "sys/time.h"
#include "robot.h"
#include "squeakyConts.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 /*bool firstP = false;
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

void gantry()
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
}*/

void operatorControl()
{
  usartInit(uart1, 600, 0);
	//joyDigitalU_init();

  motorSet(gantServ, -100);

  bool a = false;
  bool b = false;

	while (1)
	{
    /*gantry();
    gantArm();

    updateRobot();
    joyDigitalU_update();

    motorSet(gantServ, joystickGetAnalog(1, 3));

    if(joystickGetDigital(1, 7, JOY_UP) && !a)
    {
      fputc(0x33, uart1);
      motorSet(gantServC, 127);
      a = true;
    }

    if(!joystickGetDigital(1, 7, JOY_UP))
    {
      a = false;
      motorSet(gantServC, -127);
    }

    if(joystickGetDigital(1, 7, JOY_DOWN) && !b)
    {
      fputc(0xAA, uart1);
      motorSet(gantServC, 127);
      b = true;
    }

    if(!joystickGetDigital(1, 7, JOY_DOWN))
    {
      b = true;
      motorSet(gantServC, -127);
    }*/

    motorSet(gantServ2, motorGet(gantServ));

    updateMode();
    changeSpeed();

		delay(20);
	}
}
