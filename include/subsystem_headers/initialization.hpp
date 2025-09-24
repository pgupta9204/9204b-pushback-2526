#include "main.h"

// DECLARATIONS

// motor groups
extern pros::MotorGroup left_motor;
extern pros::MotorGroup right_motor;

// drivetrain setup
extern lemlib::Drivetrain drivetrain;
extern float track_width;

// inertial setup
extern pros::Imu inertial;

// odometry setup
extern lemlib::OdomSensors odometry;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
// extern pros::Rotation vertical_tracker;

// total setup
extern lemlib::Chassis chassis;

// controller initialization
extern pros::Controller controller1;

// expo drive declaration
extern lemlib::ExpoDriveCurve throttle_curve;
extern lemlib::ExpoDriveCurve steer_curve;



// Subsystem Declarations

extern pros::Motor preroller;
extern pros::Optical indexer;
extern pros::Motor rollers;
extern pros::Motor hood;
extern pros::ADIDigitalOut midgoal;
extern bool mid_descore_state;
extern pros::ADIDigitalOut middescore;

enum intakeState {
    NONE,
    INTAKE_INDEX,
    LOW_GOAL,
    MID_GOAL,
    HIGH_GOAL
};

extern intakeState intake;