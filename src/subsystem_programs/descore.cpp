#include "main.h"

// goal - create 2 toggle functions that toggle the descoring pneumatics for middle and long goal

void midGoalDescoreState()
{
    if(controller1.get_digital_new_press(DIGITAL_Y))
    {
        mid_descore_state = !mid_descore_state;
        middescore.set_value(mid_descore_state);
        
    }
}

void highGoalDescoreState()
{
    if(controller1.get_digital_new_press(DIGITAL_B))
    {
        highgoal_descore_state = !highgoal_descore_state;
        highgoaldescore.set_value(highgoal_descore_state);
        
    }
}