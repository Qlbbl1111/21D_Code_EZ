#include "main.h"

void setIndexerMotor(int value) {
    indexer = value;
}

void setIndexer() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !shift()) {
        indexer = 110;
        setFlywheelMotors(127);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && shift()) {
        indexer = 110;
        setFlywheelMotors(127);
    } else {
        indexer = 0;
    }
}