#include "main.h"

void intakeUpdate() 
{
    if(controller1.get_digital_new_press(DIGITAL_L1))
    {
        if(intake == INTAKE_INDEX)
        {
            intake = NONE;
        } else {
            intake = INTAKE_INDEX;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_L2))
    {
        if(intake == MID_GOAL){
            intake = NONE;
        } else {
            intake = MID_GOAL;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_R1))
    {
        if(intake == HIGH_GOAL){
            intake = NONE;
        } else {
            intake = HIGH_GOAL;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_R2))
    {
        if(intake == LOW_GOAL)
        {
            intake = NONE;
        } else {
            intake = LOW_GOAL;
        }
    }
}

void intakeChange() 
{
    if(intake == NONE)
    {
        midgoal.set_value(LOW);
        preroller.move(0);
        rollers.move(0);
        hood.move(0);
    } 
    else if (intake == INTAKE_INDEX)
    {
        hood.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        midgoal.set_value(LOW);
        preroller.move(127);
        rollers.move(60);
        hood.move(-30);
        if(indexer.get_hue() > 0 && indexer.get_hue() < 30 && preroller.get_power() > 5){
            rollers.move(127);
            pros::delay(50);
            rollers.move(60);
        }
        if (indexer.get_hue() > 190 && indexer.get_hue() < 230)
        {
            while (indexer.get_hue() > 190 && indexer.get_hue() < 230)
            {   
                if(intake != NONE)
                {
                    rollers.move(-60);
                    preroller.move(-127);
                }
                
            }
            if(intake != NONE)
            {
                pros::delay(100);
                preroller.move(127);
            }
            
        }
    } 
    else if (intake == HIGH_GOAL)
    {
        midgoal.set_value(LOW);
        preroller.move(127);
        rollers.move(127);
        hood.move(127);
        if(rollers.get_power() > 10)
        {
            pros::delay(100);
            if(rollers.get_power() > 10)
            {
                rollers.move(-127);
                pros::delay(50);
                rollers.move(127);
                pros::delay(100);
            }
        }
        
    } 
    else if (intake == LOW_GOAL)
    {
        midgoal.set_value(LOW);
        preroller.move(-127);
        rollers.move(-127);
        hood.move(-127);
    }
    else if (intake == MID_GOAL)
    {
        midgoal.set_value(HIGH);
        preroller.move(64);
        rollers.move(100);
        hood.move(64);
    }
}