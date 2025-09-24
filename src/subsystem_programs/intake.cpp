#include "main.h"

void intakeUpdate() 
{
    
    /*
    
    Goal for this function - make sure to get keypresses and toggle between states
    Keybinds:
        L1 triggers indexing
        L2 triggers upper center (middle) goal
        R1 triggers long goal
        R2 triggers lower center (low) goal

    */
    if(controller1.get_digital_new_press(DIGITAL_L1))
    {
        // If the intake is indexing already, stop indexing, otherwise start the indexing as the intake is not indexing
        if(intake == INTAKE_INDEX)
        {
            intake = NONE;
        } else {
            intake = INTAKE_INDEX;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_L2))
    {
        // If the intake is scoring middle (upper center) goal already, stop scoring there, otherwise start
        if(intake == MID_GOAL){
            intake = NONE;
        } else {
            intake = MID_GOAL;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_R1))
    {
        // If the intake is scoring high (long) goal already, stop scoring there, otherwise start
        if(intake == HIGH_GOAL){
            intake = NONE;
        } else {
            intake = HIGH_GOAL;
        }
    }
    if(controller1.get_digital_new_press(DIGITAL_R2))
    {
        // If the intake is scoring low (low center) goal already, stop scoring there, otherwise start
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

    /*
    
    Goal for this function: With inputs defined from intakeUpdate(), create a function that changes what the intake does

    */

    if(intake == NONE)
    {
        // If not intaking, disengage everything
        midgoal.set_value(LOW);
        preroller.move(0);
        rollers.move(0);
        hood.move(0);
    } 
    else if (intake == INTAKE_INDEX)
    {
        // if indexing, start rotating flaps at ~half speed, rotate hood backwards at ~1/4 speed, and disengage middle goal scoring

        hood.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        midgoal.set_value(LOW);
        preroller.move(127);
        rollers.move(60);
        hood.move(-30);

        if(indexer.get_hue() > 0 && indexer.get_hue() < 30 && preroller.get_power() > 5)
        {
            // If the indexer detects a red color and the preroller is stalling (preroller max wattage is 5.5, so anywhere above 5 is fine), then start spinning the rollers fast for a brief amount of time

            rollers.move(127);
            pros::delay(50);
            rollers.move(60);
        }
        if (indexer.get_hue() > 190 && indexer.get_hue() < 230)
        {

            // If the indexer detects a blue color, start rolling rollers and preroller backwards to reject the block

            while (indexer.get_hue() > 190 && indexer.get_hue() < 230)
            {   
                if(intake != NONE) // failsafe if any stalling happens and we decide to switch intake to stop running
                {
                    rollers.move(-60);
                    preroller.move(-127);
                }
                
            }

            if(intake != NONE)
            {
                pros::delay(100); // delay a little bit after the block goes out of range of the indexer to allow for it to be ejected
                preroller.move(127);
            }
            
        }
    } 
    else if (intake == HIGH_GOAL)
    {
        // if scoring on long goal, run everything at maximum speed and disengage middle goal scoring

        midgoal.set_value(LOW);
        preroller.move(127);
        rollers.move(127);
        hood.move(127);
        if(rollers.get_power() > 10) // check if motor is stalling: since an 11W motor is being used on the rollers, if they draw at least 10W of power it's safe to say the motor is struggling
        {
            pros::delay(100);
            if(rollers.get_power() > 10) // make sure it isn't just on startup and is a persistent issue, for proper detection of stalling
            {
                // if it fulfills that case, reverse the rollers for a little and then start rolling them again
                rollers.move(-127);
                pros::delay(50);
                rollers.move(127);
            }
        }
        
    } 
    else if (intake == LOW_GOAL)
    {
        // if scoring on lower center goal, reverse everything and disengage middle goal scoring
        midgoal.set_value(LOW);
        preroller.move(-127);
        rollers.move(-127);
        hood.move(-127);
    }
    else if (intake == MID_GOAL)
    {
        // if scoring on upper center (middle) goal, spin everything, engage middle goal scoring, and spin hood at half speed to not eject blocks too fast
        midgoal.set_value(HIGH);
        preroller.move(127);
        rollers.move(127);
        hood.move(64);
    }
}