#include "main.h"

void setIndexerMotors(int value) {
    indexer = value;
}

void setIndexer() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && !shift()) {
        indexer = 110;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && shift()) {
        indexer = 110;
    } else {
        indexer = 0;
    }
}