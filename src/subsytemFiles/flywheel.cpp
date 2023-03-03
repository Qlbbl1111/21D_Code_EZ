#include "main.h"
//#include "include/okapi/api/filter/averageFilter.hpp"

void setFlywheelMotors(int value) {
    flywheel_a = value;
    flywheel_b = value;
}

void setFlywheel(double targetVelocity) {
    double currentVelocity = okapi::EmaFilter(1).filter(flywheel_a.get_actual_velocity());
    double error = targetVelocity - currentVelocity;

    if (error < 15) {
    setFlywheelMotors(100);
    }
    else if (error >= 15) {
    setFlywheelMotors(127);
} 
    if (targetVelocity <= 0) {
        setFlywheelMotors(0);
    }
    pros::lcd::print(6, "Error: %lf\n", error);
}

bool latch = false;
bool toggle = false;
bool latch2 = false;
bool toggle2 = false;

void controlFlywheel() {
   //flywheel
    if (toggle && !toggle2) { //slow
        setFlywheel(520);
    }
    else if (toggle2 && !toggle) { //fast
        setFlywheel(550);
    }
    else {
        setFlywheel(0);
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

  /*
 void controlFlywheel() {
   //flywheel
    if (toggle && !toggle2) { //slow
        Flywheel(110);
    }
    else if (toggle2 && !toggle) { //fast
        Flywheel(115);
    }
    else {
        Flywheel(0);
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
  */