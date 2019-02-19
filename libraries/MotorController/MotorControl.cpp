/* MotorControl.cpp
 *
 * Class for using MotorControl (L298N)
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "Arduino.h"
#include "MotorControl.h"

/* DISCLAIMER, PINS = {enA,in1,in2,enB,in3,in4} */
 MotorControl::MotorControl()
 {
	 setPinsDefault();
 }
 
 MotorControl::MotorControl(int *passedPins)
 {
	setPins(passedPins);
 }
 
 void MotorControl::setPinsDefault()
 {
	 enA = defaultPins[0];
	 in1 = defaultPins[1];
	 in2 = defaultPins[2];
	 enB = defaultPins[3];
	 in3 = defaultPins[4];
	 in4 = defaultPins[5];
	 
	 initialize();
 }
 
 void MotorControl::setPins(int *passedPins)
 {
	 enA = passedPins[0];
	 in1 = passedPins[1];
	 in2 = passedPins[2];
	 enB = passedPins[3];
	 in3 = passedPins[4];
	 in4 = passedPins[5];
	 
	 initialize();
 }
 
 
 void MotorControl::initialize()
{
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
}


/*Note: "speed" is a variable from 0 to 255
 *      and "direction" defines wheel rotation
 *		with respect to the the wiring 
 */
void MotorControl::turnWheelA(bool direction, int speed)
{
	if(direction) {
		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
		digitalWrite(enA, speed);
	} else {
		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(enA, speed);
	}
}

void MotorControl::turnWheelB(bool direction, int speed)
{
	if(direction) {
		digitalWrite(in3, HIGH);
		digitalWrite(in4, LOW);
		digitalWrite(enB, speed);
	} else {
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		digitalWrite(enB, speed);
	}
}

void MotorControl::moveBothWheels(bool direction, int speed)
{
	turnWheelA(direction, speed);
	turnWheelB(direction, speed);
}

void MotorControl::moveWheelsOpposite(bool turnDirection, int speed)
{
	turnWheelA(turnDirection, speed);
	turnWheelB(!turnDirection, speed);
}