#include "squeakyConts.h"

int mode = 0;
/*
0 - drive (default)
1 - lift
2 - rotate
*/

bool pps[] = {false, false, false, false};
/*
0 - JOY_UP
1 - JOY_LEFT
2 - JOY_DOWN
3 - JOY_RIGHT
*/

void updateMode()
{
  // lift
  if(joystickGetDigital(1, 5, JOY_UP) && mode != 1)
  {
    mode = 1;
    fputc(0x55, uart1);
  }

  //rotate
  else if(joystickGetDigital(1, 6, JOY_UP) && mode != 2)
  {
    mode = 2;
    fputc(0x33, uart1);
  }

  //drive
  else if(!joystickGetDigital(1, 6, JOY_UP) && !joystickGetDigital(1, 5, JOY_UP) && joystickGetAnalog(1, 3) > 10 && mode != 0)
  {
    mode = 0;
    fputc(0x3C, uart1);
  }
}

//TODO: UPDATE HEX VALUES WHEN MY PHONE ISN'T AT 18%
void changeSpeed()
{
  //high
  if(joystickGetDigital(1, 7, JOY_UP) && ! pps[0])
  {
    fputc(0xFF, uart1);
    fputc(0xFF, uart1);
    pps[0] = true;
  }

  else if(!joystickGetDigital(1, 7, JOY_UP))
  {
    pps[0] = false;
  }

  //mid (like ur mom)
  if(joystickGetDigital(1, 7, JOY_LEFT) && !pps[1])
  {
    fputc(0xFF, uart1);
    fputc(0xFF, uart1);
    pps[1] = true;
  }

  else if(!joystickGetDigital(1, 7, JOY_LEFT))
  {
    pps[1] = false;
  }

  //low
  if(joystickGetDigital(1, 7, JOY_DOWN) && !pps[2])
  {
    fputc(0xFF, uart1);
    fputc(0xFF, uart1);
    pps[2] = true;
  }

  else if(!joystickGetDigital(1, 7, JOY_DOWN))
  {
    pps[2] = false;
  }

  //reset
  if(joystickGetDigital(1, 7, JOY_RIGHT) && !pps[3])
  {
    fputc(0xAA, uart1);
    pps[3] = true;
  }

  else if(!joystickGetDigital(1, 7, JOY_RIGHT))
  {
    pps[3] = false;
  }
}
