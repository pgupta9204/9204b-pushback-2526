#include "main.h"

void matchloaderToggle()
{
    if(controller1.get_digital_new_press(DIGITAL_DOWN))
    {
        matchloader_state = !matchloader_state;
        matchloader.set_value(matchloader_state);
    }
}