#include <joyDigitalU.h>
#include <API.h>

struct button butts[12];

void joyDigitalU_init()
{
  butts[0].group = 5;
  butts[0].label = 'U';

  butts[1].group = 5;
  butts[1].label = 'D';

  butts[2].group = 6;
  butts[2].label = 'U';

  butts[3].group = 6;
  butts[3].label = 'D';

  butts[4].group = 7;
  butts[4].label = 'U';

  butts[5].group = 7;
  butts[5].label = 'D';

  butts[6].group = 7;
  butts[6].label = 'R';

  butts[7].group = 7;
  butts[7].label = 'L';

  butts[8].group = 8;
  butts[8].label = 'U';

  butts[9].group = 8;
  butts[9].label = 'D';

  butts[10].group = 8;
  butts[10].label = 'R';

  butts[11].group = 8;
  butts[11].label = 'L';

  for(int i = 0; i < 12; i++)
  {
    butts[i].pressed = false;
  }
}

void joyDigitalU_update()
{
  for(int i = 0; i < 12; i++)
  {
    if(!joystickGetDigital(1, butts[i].group, butts[i].label))
    {
      butts[i].pressed = false;
    }
  }
}

bool isHeld(int group, char button)
{
  return joystickGetDigital(1, group, button);
}

bool onPress(int group, char button)
{
  for(int i = 0; i < 12; i++)
  {
    if(butts[i].group == group && butts[i].label == button)
    {
      if(joystickGetDigital(1, group, button) && !butts[i].pressed)
      {
        butts[i].pressed = true;
        return true;
      }

      return false;
    }
  }

  return false;
}
