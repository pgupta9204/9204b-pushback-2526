#include "main.h"

void right_8() 
{
    // Right side autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 90);
    
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-19.508, -22.863, 3000, {.maxSpeed = 60}); 
    chassis.waitUntil(34);
    // matchloader_state = true;
    // matchloader.set_value(HIGH);
    chassis.turnToHeading(150, 1000);
    chassis.moveToPoint(-7.317, -40.401, 3000, {.maxSpeed = 80});
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-16.75, -20.50, 2000, {.forwards = false});
    
    chassis.turnToHeading(45, 1000);
    // chassis.waitUntilDone();
    // intake = LOW_GOAL;
    // while(!indexer_team_color_detected)
    // {
    //     pros::delay(10);
    // }
    
    // pros::delay(300);
    // intake = INTAKE_INDEX;
    chassis.moveToPoint(-46, -46, 2000, {.forwards = false});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(-27, -48, 3000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    intake = HIGH_GOAL;
    pros::delay(1500);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(-58.882, -46.5, 3000, {.maxSpeed = 55});
    
    if(current_team_color == RED)
    {
        while(!indexer_blue_detected)
        {
            pros::delay(20);
        }
    }
    else if (current_team_color == BLUE)
    {
        while(!indexer_red_detected)
        {
            pros::delay(20);
        }
    }
    
    
    pros::delay(100);
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-27, -48, 3000, {.forwards = false, .maxSpeed = 67});
    while(!high_goal_detected)
    {
        pros::delay(20);
    }
    intake = HIGH_GOAL;
}


void left_8()
{
    // flip vertically
    // Left side autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, 15.975, 90);

    intake = INTAKE_INDEX;
    chassis.moveToPoint(-19.508, 22.063, 3000, {.maxSpeed = 60}); 
    chassis.waitUntil(34);
    // matchloader_state = true;
    // matchloader.set_value(HIGH);
    chassis.turnToHeading(30, 1000);
    chassis.moveToPoint(-7.317, 42.401, 3000, {.maxSpeed = 80});
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-16.75, 20.50, 2000, {.forwards = false});

    chassis.turnToHeading(135, 1000);
    // chassis.waitUntilDone();
    // intake = LOW_GOAL;
    // while(!indexer_team_color_detected)
    // {
    //     pros::delay(10);
    // }
    // pros::delay(300);
    // intake = INTAKE_INDEX;
    chassis.moveToPoint(-46, 46, 2000, {.forwards = false});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(-27, 48, 3000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    intake = HIGH_GOAL;
    pros::delay(1500);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(-58.882, 46.5, 3000, {.maxSpeed = 55});
    if(current_team_color == RED)
    {
        while(!indexer_blue_detected)
        {
            pros::delay(20);
        }
    }
    else if (current_team_color == BLUE)
    {
        while(!indexer_red_detected)
        {
            pros::delay(20);
        }
    }
    pros::delay(100);
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-27, 48, 3000, {.forwards = false, .maxSpeed = 80});
    while(!high_goal_detected)
    {
        pros::delay(20);
    }
    intake = HIGH_GOAL;
}

void skills_auton()
{
    // Skills autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    intake = HIGH_GOAL;
    
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
    chassis.waitUntilDone();
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(0, 30, 60000, {.forwards = true});
}

void sawp()
{
    // SAWP autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 90);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-22.989, -22.446, 3000, {.maxSpeed = 60});
    chassis.moveToPose(-15.294, -14.935, 45, 3000);
    chassis.waitUntilDone();
    intake = LOW_GOAL;
    pros::delay(1000);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-23.172, 23.722, 3000, {.maxSpeed = 60});
    chassis.moveToPose(-15.477, 15.661, 315, 1000, {.forwards = false});
    chassis.waitUntilDone();
    intake = MID_GOAL;
    pros::delay(1000);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-46, 46, 2000);
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.turnToHeading(-90, 1000);


    chassis.moveToPoint(-58.882, 46.5, 3000, {.maxSpeed = 55});
    if(current_team_color == RED)
    {
        while(!indexer_blue_detected)
        {
            pros::delay(20);
        }
    }
    else if (current_team_color == BLUE)
    {
        while(!indexer_red_detected)
        {
            pros::delay(20);
        }
    }
    pros::delay(100);
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-27, 48, 3000, {.forwards = false, .maxSpeed = 80});
    while(!high_goal_detected)
    {
        pros::delay(20);
    }
    intake = HIGH_GOAL;

}