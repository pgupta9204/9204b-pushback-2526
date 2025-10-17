#include "main.h"






/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
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
	pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(20);
        }
    }); 
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
    
    // Right side autonomous
    chassis.setPose(-54.8375, -15.975, 90);
    pros::Task auto_intake(auto_intake_thread, nullptr);
    pros::Task auto_boolean_update(auto_boolean_update_thread, nullptr);
    intake = INTAKE_INDEX;
    chassis.moveToPoint(-19.508, -23.363, 3000, {.maxSpeed = 60}); 
    chassis.moveToPoint(-6.317, -40.401, 3000, {.maxSpeed = 80});
    chassis.moveToPoint(-17.25, -19.25, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.turnToHeading(45, 1000);
    //chassis.waitUntilDone();
    //intake = LOW_GOAL;
    chassis.moveToPoint(-46, -46, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(-27, -48.5, 3000, {.forwards = false, .maxSpeed = 80});
    while(!high_goal_detected)
    {
        pros::delay(20);
    }
    intake = HIGH_GOAL;
    pros::delay(1000);
    intake = INTAKE_INDEX;
    matchloader_state = true;
    matchloader.set_value(HIGH);

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