#include "main.h"

void right_8() 
{
    // Right side autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 90);
    
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-15.508, -23.763, 3000, {.maxSpeed = 60}); 
    chassis.waitUntil(34);
    // matchloader_state = true;
    // matchloader.set_value(HIGH);
    chassis.turnToHeading(130, 1000);
    chassis.moveToPoint(-7.317, -40.401, 3000, {.maxSpeed = 100});
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-16.75, -28.50, 2000, {.forwards = false});
    
    chassis.turnToHeading(55, 500);
    // chassis.waitUntilDone();
    // intake = LOW_GOAL;
    // while(!indexer_team_color_detected)
    // {
    //     pros::delay(10);
    // }
    
    // pros::delay(300);
    // intake = INTAKE_INDEX;
    chassis.moveToPoint(-46, -45, 2000, {.forwards = false});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(-27, -48, 3000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    intake = HIGH_GOAL;
    pros::delay(1500);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(-60.882, -47.5, 3000, {.maxSpeed = 65});
    
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
    chassis.moveToPoint(-27, -47.5, 3000, {.forwards = false, .maxSpeed = 67});
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
    chassis.setPose(-54.8375, -15.975, 90);
    intake = INTAKE_INDEX;
    
    highGoalDescoreToggle();
    chassis.moveToPoint(-48, -47.5, 1600);
    chassis.waitUntilDone();
    chassis.turnToHeading(260, 500);
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.waitUntilDone();
    chassis.moveToPoint(-56.249, -48, 1000, {.maxSpeed = 90});
    chassis.moveToPoint(-27, -47, 1500, {.forwards = false, .minSpeed = 40});
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.waitUntil(27);
    intake = HIGH_GOAL;
    pros::delay(1250);
    intake = INTAKE_INDEX;
    highGoalDescoreToggle();
    chassis.moveToPoint(-40, -47, 500);
    chassis.moveToPoint(-30, -36, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.turnToHeading(270, 500);
    chassis.moveToPoint(-10, -36, 1000, {.forwards = false});
    chassis.moveToPose(-10, -33.622, 270, 2000, {.forwards = false});
    chassis.turnToHeading(250, 10000, {.minSpeed = 127});
}

void skills_auton()
{
    // Skills autonomous
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    chassis.setPose(-54.8375, -15.975, 90);
    // score preload
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-48, -47.5, 1600);
    chassis.turnToHeading(-90, 500);
    chassis.moveToPoint(-27, -47, 3000, {.forwards = false});
    chassis.waitUntil(27);
    intake = HIGH_GOAL;
    pros::delay(400);
    // matchload bottom right loader
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    pros::delay(500);
    chassis.moveToPoint(-56.249, -48, 1000, {.maxSpeed = 90});
    pros::delay(2500); // too long of matchload time?
    matchloader_state = false;
    matchloader.set_value(LOW);
    // drive to opposite side of long goal and score
    chassis.moveToPoint(-36, -60, 2000, {.forwards = false});
    chassis.turnToHeading(-90, 500);
    chassis.moveToPoint(48, -60, 3000, {.forwards = false}); // too long of drive time?
    chassis.turnToHeading(-180, 500);
    chassis.moveToPoint(48, -48, 1000, {.forwards = false});
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(27, -47, 1500, {.forwards = false});
    intake = HIGH_GOAL;
    pros::delay(2000); // is this too long of outtake for 6 blocks?
    // matchload and score bottom right loader
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    pros::delay(500);
    chassis.moveToPoint(56.249, -48, 1000, {.maxSpeed = 90});
    pros::delay(2500); // too long of matchload time?
    matchloader_state = false;
    matchloader.set_value(LOW);
    pros::delay(100);
    chassis.moveToPoint(27, -47, 2000, {.forwards = false});
    intake = HIGH_GOAL;
    pros::delay(2000); // too long of outtake for 6 blocks?
    // drive to far side of field
    chassis.moveToPoint(40, -48, 1000);
    chassis.turnToHeading(0, 1000);
    chassis.moveToPoint(40, 48, 3000); // too long of wait for driving?
    // matchload loader
    matchloader_state = true;
    matchloader.set_value(HIGH);
    pros::delay(500);
    chassis.moveToPoint(56.249, 48, 1000, {.maxSpeed = 90});
    pros::delay(2500); // too long of matchload time?
    matchloader_state = false;
    matchloader.set_value(LOW);
    // drive to other side of long goal and score
    chassis.moveToPoint(36, 60, 2000, {.forwards = false});
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(-48, 60, 3000, {.forwards = false}); // too long of drive time?
    chassis.turnToHeading(0, 500);
    chassis.moveToPoint(-48, 48, 1000, {.forwards = false});
    chassis.turnToHeading(-90, 500);
    chassis.moveToPoint(-27, 48, 1500, {.forwards = false});
    intake = HIGH_GOAL;
    pros::delay(2000); // too long of outtake?
    // matchload loader
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);
    pros::delay(500);
    chassis.moveToPoint(-56.249, 48, 1000, {.maxSpeed = 90});
    pros::delay(2500); // too long of matchload time?
    matchloader_state = false;
    matchloader.set_value(LOW);
    pros::delay(100);
    chassis.moveToPoint(-27, 48, 2000, {.forwards = false});
    intake = HIGH_GOAL;
    pros::delay(2000); // too long of outtake?
    // finish auton, go to park
    chassis.moveToPoint(48, -48, 1000);
    chassis.moveToPose(-72 + 7.5, 0 - 7.5, 180, 20000, {.maxSpeed = 80});

    // old auto
    /*
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    intake = HIGH_GOAL;
    
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, -5, 1000, {.forwards = false});
    chassis.waitUntilDone();
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(0, 30, 60000, {.forwards = true});
    */
}

void sawp()
{
    // NEW SAWP

    // Run intake threads
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    // First movement - push and back up to matchloader
    chassis.setPose(-45.523 - 7/8, 0 - 7.5, 0);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-45.523 - 7/8, 0 - 7.5 + 14, 500);
    chassis.moveToPoint(-45.523 - 7/8, -47, 1500, {.forwards = false});
    chassis.turnToHeading(-90, 500);
    matchloader_state = true;
    matchloader.set_value(HIGH);    
    // Matchload & score long goal
    
    chassis.moveToPoint(-56.249, -47, 1000, {.maxSpeed = 90});
    
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

    
    
    chassis.moveToPoint(-27, -48, 2000, {.forwards = false});
    matchloader_state = false;
    matchloader.set_value(LOW);
    
    chassis.waitUntil(27);
    intake = HIGH_GOAL;
    

    // middle goal movements

    chassis.moveToPoint(-47, -47, 750);
    
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-22, -22, 2000, {.maxSpeed = 128, .minSpeed = 60, .earlyExitRange = 15});
    chassis.moveToPoint(-22, -22, 1000, {.maxSpeed = 60});
    chassis.turnToHeading(0, 500);
    chassis.moveToPoint(-24, 22, 3000, {.maxSpeed = 128, .minSpeed = 50, .earlyExitRange = 15});
    chassis.moveToPoint(-24, 24, 1000, {.maxSpeed = 50});
    chassis.turnToHeading(-45, 500);
    chassis.moveToPoint(-10, 10, 2000, {.forwards = false, .minSpeed = 40, .earlyExitRange = 10});
    chassis.moveToPoint(-10, 12, 500, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntilDone();
    intake = MID_GOAL;
    pros::delay(500);
    

    // second loader + long goal score

    chassis.moveToPoint(-43.523, 48, 1500);
    intake = INTAKE_INDEX;
    chassis.turnToHeading(-90, 500);
    matchloader_state = true;
    matchloader.set_value(HIGH);
    chassis.moveToPoint(-57.249, 48, 1000, {.maxSpeed = 90});
    
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
    chassis.waitUntilDone();
    pros::delay(500);
    matchloader_state = false;
    matchloader.set_value(LOW);
    chassis.moveToPoint(-27, 48, 1000, {.forwards = false});
    chassis.waitUntil(27);
    intake = HIGH_GOAL;

    // SAWP autonomous
    /*
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
    */

}