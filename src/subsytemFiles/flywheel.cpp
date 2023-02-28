#include "main.h"

bool latch = false;
bool toggle = false;
bool latch2 = false;
bool toggle2 = false;
bool latch3 = false;
bool toggle3 = false;
int flywheelSpeed = 0;

void setFlywheelMotors(int value) {
    flywheel_a = value;
    flywheel_b = value;
}

void setFlywheel() {
   //flywheel
    if (toggle && !toggle2) { //slow
        setFlywheelMotors(90);
    }
    else if (toggle2 && !toggle) { //fast
        setFlywheelMotors(115);
    }
    else {
        setFlywheelMotors(0);
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && shift() == false) {//slow
        if (!latch) {
            //flip the toggle one time and set the latch
            toggle = !toggle;
            latch = true;
        }
    }
    else{
        //Once the BumperA is released then then release the latch too
        latch = false;
    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && shift() == true) {//fast
        if (!latch2) {
            //flip the toggle one time and set the latch
            toggle2 = !toggle2;
            latch2 = true;
        }
    }
    else {
        //Once the BumperA is released then then release the latch too
        latch2 = false;
    }

  }
  