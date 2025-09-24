#include "main.h"

// DRIVETRAIN INIT

float track_width = 15;

pros::MotorGroup left_motor({-11, -12, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({18, 19, 20}, pros::MotorGearset::blue);

pros::Controller controller1(pros::E_CONTROLLER_MASTER);

lemlib::Drivetrain drivetrain(&left_motor, // left motors
                              &right_motor, // right motors
                              track_width, // track width (will become obsolete with tracking wheel implementation)
                              lemlib::Omniwheel::NEW_325, // using new 3.25in wheels
                              450, // 450rpm drivetrain
                              2 // horizontal drift is 2 (for now)
);

pros::Imu inertial(10);

// pros::Rotation vertical_tracker(1);

// lemlib::TrackingWheel vertical_tracking_wheel(&vertical_tracker, lemlib::Omniwheel::NEW_2, 0);

// odometry settings
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &inertial // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// input curve for throttle input during opcontrol
lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain,
                        lateral_controller,
                        angular_controller,
                        sensors,
                        &throttle_curve, 
                        &steer_curve
);





// SUBSYSTEM INIT

pros::Motor preroller(-1);
pros::Optical indexer(4);



pros::Motor rollers(-2, pros::MotorGearset::blue);
pros::Motor hood(3);

pros::ADIDigitalOut midgoal('C');
pros::ADIDigitalOut middescore('D');
bool mid_descore_state = false;

intakeState intake = NONE;