#include "main.h"

void drive()
{
    int throttle = controller1.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = controller1.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    chassis.arcade(throttle, turn, false, 0.75);
}