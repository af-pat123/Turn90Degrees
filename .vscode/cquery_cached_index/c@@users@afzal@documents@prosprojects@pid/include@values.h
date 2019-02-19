#include "main.h"
#define PORT_TOP_LEFT 'E'
#define PORT_BOTTOM_LEFT 'F'
#define PORT_TOP_RIGHT 'C'
#define PORT_BOTTOM_RIGHT 'D'
#define PORT_TOP_LEFT 'E'
#define PORT_BOTTOM_LEFT 'F'
#define PORT_TOP_RIGHT 'C'
#define PORT_BOTTOM_RIGHT 'D'
#define pi 3.14
#define KP 0.8
#define KI 0.001f
#define KD 0.1f
#define threshold 1000
#define turn_threshold 20
#define degreesPerRotation 360
#define wheelDiameter 4 //4.0" wheels

extern pros::Motor left_mtr1;
extern pros::Motor left_mtr2;
extern pros::Motor right_mtr1;
extern pros::Motor right_mtr2;
extern pros::ADIEncoder left_sensor;
extern pros::ADIEncoder right_sensor;
