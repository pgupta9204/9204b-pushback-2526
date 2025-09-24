#include "main.h"

void midGoalDescoreState()
{
    if(controller1.get_digital_new_press(DIGITAL_DOWN))
    {
        mid_descore_state = !mid_descore_state;
        middescore.set_value(mid_descore_state);
        
    }
}