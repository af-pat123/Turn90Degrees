#include "main.h"
#include "values.h"

extern pros::Motor left_mtr1;
extern pros::Motor left_mtr2;
extern pros::Motor right_mtr1;
extern pros::Motor right_mtr2;
extern pros::ADIEncoder left_sensor;
extern pros::ADIEncoder right_sensor;

void resetEncoder(){


	left_mtr1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	left_mtr2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	right_mtr1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	right_mtr2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  left_sensor.reset(); // The encoder is now zero again
	right_sensor.reset(); // The encoder is now zero again
}
