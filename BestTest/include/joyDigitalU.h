#include <stdbool.h>

struct button
{
  int group;
  char label;
  bool pressed;
};

void joyDigitalU_init();
void joyDigitalU_update();
bool onPress(int group, char button);
