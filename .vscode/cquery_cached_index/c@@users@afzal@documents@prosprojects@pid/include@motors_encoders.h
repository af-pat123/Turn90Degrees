#include "main.h"
#define PORT_TOP_LEFT 'E'
#define PORT_BOTTOM_LEFT 'F'
#define PORT_TOP_RIGHT 'C'
#define PORT_BOTTOM_RIGHT 'D'

pros::Motor left_mtr1(1);
pros::Motor left_mtr2(2);
pros::Motor right_mtr1(3);
pros::Motor right_mtr2(4);
pros::ADIEncoder left_sensor (PORT_TOP_LEFT, PORT_BOTTOM_LEFT, false);
pros::ADIEncoder right_sensor (PORT_TOP_RIGHT, PORT_BOTTOM_RIGHT, false);
