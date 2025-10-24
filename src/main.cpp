#include "main.h"






/**
 * A callback function for LLEMU's center button.
 *
 */
void on_center_button() {
	
}


void auto_intake_thread(void* param)
{
    indexer.set_integration_time(3);
    indexer.set_led_pwm(100);
    high_goal_sensor.set_led_pwm(100);
    while (pros::competition::is_autonomous()) 
    {
        intakeChange();
        
        pros::delay(20);
    }
}

void auto_boolean_update_thread(void* param)
{
    while (pros::competition::is_autonomous()) 
    {
        booleanUpdate();
        pros::delay(20);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

    teamColor current_team_color = SKILLS;
    auton selected_auton = SKILLS_AUTON;
    int auton_index = 0;
    int team_color_index = 0; // start on skills


	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    // pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // delay to save resources
    //         pros::delay(20);
    //     }
    // }); 
    
    while(true)
    {
        // wait for user to select team color and auton
        if(pros::lcd::read_buttons() & LCD_BTN_LEFT)
        {
            team_color_index++;
            team_color_index %= 3;
        }

        if(pros::lcd::read_buttons() & LCD_BTN_CENTER)
        {
            auton_index++;
            auton_index %= 4;
        }

        // display selections
        pros::lcd::clear();
        pros::lcd::print(0, "Team Color:");
        
        if (team_color_index == SKILLS)
        {
            pros::lcd::print(1, "SKILLS");
            current_team_color = SKILLS;
        }
        else if (team_color_index == RED)
        {
            pros::lcd::print(1, "RED");
            current_team_color = RED;
        }
        else if (team_color_index == BLUE)
        {
            pros::lcd::print(1, "BLUE");
            current_team_color = BLUE;
        }

        pros::lcd::print(3, "Auton:");
        if (auton_index == SKILLS_AUTON)
        {
            pros::lcd::print(4, "SKILLS AUTON");
            selected_auton = SKILLS_AUTON;
        }
        else if (auton_index == RIGHT_8)
        {
            pros::lcd::print(4, "RIGHT 8");
            selected_auton = RIGHT_8;
        }
        else if (auton_index == LEFT_8)
        {
            pros::lcd::print(4, "LEFT 8");
            selected_auton = LEFT_8;
        }
        else if (auton_index == SAWP)
        {
            pros::lcd::print(4, "SAWP");
            selected_auton = SAWP;
        }

        pros::delay(20);
    }

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() 
{
    

    if (selected_auton == RIGHT_8)
    {
        right_8();
    }
    else if (selected_auton == LEFT_8)
    {
        left_8();
    }
    else if (selected_auton == SKILLS_AUTON)
    {
        skills_auton();
    }
    else if (selected_auton == SAWP)
    {
        sawp();
    }
    

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */



void intakeThread(void* param) // thread for intake manipulation
{
    indexer.set_integration_time(3);
    indexer.set_led_pwm(100);
    high_goal_sensor.set_led_pwm(100);
    while (true) 
    {
        intakeChange();
        pros::delay(20);
    }
}
void rumbleThread(void* param) // thread for rumble feedback
{
    while (true) 
    {
        rumbleHandler(high_goal_detected && !(intake == HIGH_GOAL), "-");
        pros::delay(20);
    }
}

void opcontrol() // general drivercontrol code, has all functions listed in previous places
{
	// loop forever
    pros::Task intake_update(intakeThread, nullptr);
    pros::Task rumble_update(rumbleThread, nullptr);
    while (true) 
    {
        intakeUpdate();
        midGoalDescoreState();
        highGoalDescoreState();
        matchloaderToggle();
        booleanUpdate();
        drive();
        pros::delay(10);
    }
}