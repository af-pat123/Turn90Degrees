#include "main.h"
#include "values.h"
#include "resetEncoder.h"


pros::Motor left_mtr1(1);
pros::Motor left_mtr2(2);
pros::Motor right_mtr1(3);
pros::Motor right_mtr2(4);
pros::ADIEncoder left_sensor (PORT_TOP_LEFT, PORT_BOTTOM_LEFT, false);
pros::ADIEncoder right_sensor (PORT_TOP_RIGHT, PORT_BOTTOM_RIGHT, false);

/*pros::Motor left_mtr1;
pros::Motor left_mtr2;
pros::Motor right_mtr1;
pros::Motor right_mtr2;
extern pros::ADIEncoder left_sensor;
extern pros::ADIEncoder right_sensor;*/

void turn90degrees(int direction){



    double setpoint = 0.6875 * degreesPerRotation; //How many rotation it needs to turn 90 degrees
  	//Resets the encoder value
  	//reads encoder values
  	double left_pos = left_sensor.get_value();
  	double right_pos = right_sensor.get_value();
    double last_error = 0;
    double totalError = 0;

  	double error, reference,speed;
  	speed = 30; //max speed

  	if (direction == 1){
  			left_mtr1.set_reversed(false);
  			right_mtr1.set_reversed(true);
  		}
  	else if (direction ==2)
  		{
  			right_mtr1.set_reversed(false);
  			left_mtr1.set_reversed(true);
  		}
  	while(true){

  			if (direction ==1)
  				error = setpoint - left_pos; // = setpoint - right_pos1 (in degrees)
  			else if (direction==2)
  				error = setpoint - right_pos;
  			std::cout << "error: " << error << "			left position: " << left_pos << "			right position: " << right_pos << "\n";
  			pros::delay(10);
  			if (abs(error)<=turn_threshold){
          resetEncoder();
          totalError=0;
          break;
        }
  				//break; //don't think this condition will work because the motor spins pretty fast, so it will probably overshoot and undershoot the target position forever.

  			// not really sure how to use the KP constant on the error, since we are changing speed which is in different units than the error's units (meters/s vs meters).
  			//Play around with different ways of using error and KP constant to change speed
        //kp=proportional control: Basically trial and error and test the distance.
        //
        speed = error * KP + (error-last_error)*KD + totalError*KI;

  			left_mtr1.move(speed); //move() is same as move_velocity() command
  			left_mtr2.move(speed); //move() is same as move_velocity() command
  			right_mtr1.move(speed);
  			right_mtr2.move(speed);
  			left_pos = left_sensor.get_value(); //Constantly reads the encoder value
  			right_pos = right_sensor.get_value();
  			pros::delay(50);
  			/*tpoint||left_pos<=-setpoint||right_pos>=setpoint||right_pos<=-setpoint){

  			}*/
        last_error=error;
        totalError+=error;
  		}
  		left_mtr1.move_velocity(0);
  		left_mtr2.move_velocity(0);
  		right_mtr1.move_velocity(0);
  		right_mtr2.move_velocity(0);
  		pros::delay(50);
  	}
