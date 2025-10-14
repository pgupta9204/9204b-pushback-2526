#include "main.h"

// sensory boolean declarations
bool indexer_red_detected = false;
bool indexer_blue_detected = false;
bool high_goal_detected = false;

// boolean update function
void booleanUpdate()
{
    // indexer red color detection
    if(indexer.get_hue() > 0 && indexer.get_hue() < 30)
    {
        indexer_red_detected = true;
    }
    else
    {
        indexer_red_detected = false;
    }
    // indexer blue color detection
    if(indexer.get_hue() > 190 && indexer.get_hue() < 230)
    {
        indexer_blue_detected = true;
    }
    else
    {
        indexer_blue_detected = false;
    }
    // high goal color detection
    if(high_goal_sensor.get_hue() > 20 && high_goal_sensor.get_hue() < 40 && limit_switch.get_value() == 1)
    {
        high_goal_detected = true;
    }
    else
    {
        high_goal_detected = false;
    }
}    