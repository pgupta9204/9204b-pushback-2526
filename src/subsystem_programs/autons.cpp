#include "main.h"

void right_8() 
{
    // Right side autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 90);
    
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-19.508, -22.263, 3000, {.maxSpeed = 60}); 
    chassis.waitUntil(34);
    // matchloader_state = true;
    // matchloader.set_value(HIGH);
    chassis.turnToHeading(150, 1000);
    chassis.moveToPoint(-7.317, -40.401, 3000, {.maxSpeed = 80});
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-16.75, -20.50, 2000, {.forwards = false});
    
    chassis.turnToHeading(45, 500);
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
    chassis.moveToPoint(-27, -47.5, 3000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    intake = HIGH_GOAL;
    pros::delay(1500);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(-60.882, -46.5, 3000, {.maxSpeed = 55});
    
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
    chassis.moveToPoint(-27, -47, 3000, {.forwards = false, .maxSpeed = 67});
    chassis.waitUntil(33);
    // pros::delay(500);
    intake = HIGH_GOAL;
}


void left_8()
{
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    // setPose: (-54.8375, -15.975, 90) -> (-54.8375, 15.975, 90)
    chassis.setPose(-54.8375, 15.975, 90);
    
    intake = INTAKE_INDEX;
    // moveToPoint: (-19.508, -22.863) -> (-19.508, 22.863)
    chassis.moveToPoint(-19.508, 22.863, 3000, {.maxSpeed = 60}); 
    chassis.waitUntil(34);
    // matchloader_state = true;
    // matchloader.set_value(HIGH);
    // turnToHeading: (150) -> (30) [180 - 150 = 30]
    chassis.turnToHeading(30, 1000);
    // moveToPoint: (-7.317, -40.401) -> (-7.317, 40.401)
    chassis.moveToPoint(-7.317, 40.401, 3000, {.maxSpeed = 80});
    matchloader_state = false;
    matchloader.set_value(LOW);
    // moveToPoint: (-16.75, -20.50) -> (-16.75, 20.50)
    chassis.moveToPoint(-16.75, 20.50, 2000, {.forwards = false});
    
    // turnToHeading: (45) -> (135) [180 - 45 = 135]
    chassis.turnToHeading(135, 1000);
    // chassis.waitUntilDone();
    // intake = LOW_GOAL;
    // while(!indexer_team_color_detected)
    // {
    //     pros::delay(10);
    // }
    
    // pros::delay(300);
    // intake = INTAKE_INDEX;
    // moveToPoint: (-46, -46) -> (-46, 46)
    chassis.moveToPoint(-46, 46, 2000, {.forwards = false});
    // turnToHeading: (-90) -> (-90) [180 - (-90) = 270 -> -90]
    chassis.turnToHeading(-90, 1000);
    // moveToPoint: (-27, -48) -> (-27, 48)
    chassis.moveToPoint(-27, 48, 3000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    intake = HIGH_GOAL;
    pros::delay(1500);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    // moveToPoint: (-58.882, -46.5) -> (-58.882, 46.5)
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
    // moveToPoint: (-27, -48) -> (-27, 48)
    chassis.moveToPoint(-27, 48, 3000, {.forwards = false, .maxSpeed = 67});
    while(!high_goal_detected)
    {
        pros::delay(20);
    }
    intake = HIGH_GOAL;
}

void right_4_wing()
{
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 180);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    highGoalDescoreToggle();
    chassis.moveToPoint(-48, -47, 2000);
    chassis.moveToPoint(-57.249, -47, 1000, {.maxSpeed = 90});
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
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-27, -47, 3000, {.forwards = false});
    chassis.waitUntil(27);
    intake = HIGH_GOAL;
    pros::delay(500);
    intake = INTAKE_INDEX;
    highGoalDescoreToggle();
    chassis.moveToPoint(-35, -47, 1000);
    chassis.moveToPoint(-31.234, -33.622, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.moveToPoint(-10, -33.622, 2000, {.forwards = false});
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
    chassis.moveToPoint(-18.989, -21.296, 3000, {.maxSpeed = 55});
    chassis.moveToPose(-21.294, -13.435, 45, 3000, {.maxSpeed = 75});
    chassis.waitUntilDone();
    intake = LOW_GOAL;
    pros::delay(1100);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-24, -24, 2000, {.forwards = false});
    chassis.moveToPoint(-22.022, 23.522, 3000, {.maxSpeed = 50});
    chassis.moveToPose(-8.047, 8.961, 315, 1000, {.forwards = false});
    chassis.waitUntilDone();
    intake = MID_GOAL;
    pros::delay(500);

    intake = INTAKE_INDEX;
    chassis.moveToPoint(-46, 46, 2000);
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.turnToHeading(-90, 1000);


    chassis.moveToPoint(-59.882, 46.5, 3000, {.maxSpeed = 55});
    pros::delay(1000);
    // if(current_team_color == RED)
    // {
    //     while(!indexer_blue_detected)
    //     {
    //         pros::delay(20);
    //     }
    // }
    // else if (current_team_color == BLUE)
    // {
    //     while(!indexer_red_detected)
    //     {
    //         pros::delay(20);
    //     }
    // }
    pros::delay(100);
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-26.5, 47, 3000, {.forwards = false, .maxSpeed = 80});
    int timer = 0;
    chassis.waitUntilDone();
    intake = HIGH_GOAL;

}