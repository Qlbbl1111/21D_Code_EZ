#include "main.h"

void setIntakeMotors(int value) {
    intake = value;
}

void setIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && !shift()) {
        intake = 127;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && shift()) {
        intake = -127;
    } else {
        intake = 0;
    }
}