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
extern pros::ADIDigitalOut highgoaldescore;
extern bool highgoal_descore_state;

extern pros::Optical high_goal_sensor;
extern pros::ADIDigitalIn limit_switch;

extern pros::ADIDigitalOut matchloader;
extern bool matchloader_state;

enum intakeState {
    NONE,
    INTAKE_INDEX,
    LOW_GOAL,
    MID_GOAL,
    HIGH_GOAL
};

enum teamColor {
    SKILLS,
    RED,
    BLUE
};

enum auton {
    SKILLS_AUTON,
    RIGHT_8,
    LEFT_8,
    SAWP
};

extern intakeState intake;

extern teamColor current_team_color;

extern auton selected_auton;

// sensory boolean declarations

extern bool indexer_red_detected;
extern bool indexer_blue_detected;
extern bool high_goal_detected;