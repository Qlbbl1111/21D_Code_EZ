#include "main.h"

//MOTORS
pros::Motor intake(7, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor indexer(21, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor_Group flywheel({flywheel_a, flywheel_b});
pros::Motor flywheel_a(1, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor flywheel_b(2, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor driveRightBack(17, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(18, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(11, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftFront(12, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//SENSORS
pros::Imu inertial(16);
pros::ADIDigitalIn selecter('D');

//PNUEMATICS
pros::ADIDigitalOut expansion('A');
pros::ADIDigitalOut blocker('B');
pros::ADIDigitalOut compesser('C');

//SHIFT
bool shift() {
    return controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
}
