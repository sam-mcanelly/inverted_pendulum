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
 MotorControl()
 {
	 pins = defaultPins();
 }
 
 MotorControl(int *passedPins)
 {
	 pins = passedPins;
 }
 
 void MotorControl::setPinsDefault()
 {
	 pins = defaultPins;
	 initialize();
 }
 
 void MotorControl::setPins(int *passedPins)
 {
	 pins = passedPins;
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


/*Note: Speed is a variable from 0 to 255
 *      and "forward" defines wheel rotation
 *		with respect to the the wiring 
 */
void MotorControl::turnWheelA(bool forward, int speed)
{
	if(forward) {
		digitalWrite(in1, HIGH);
		digitalWrite(in2, LOW);
		digitalWrite(enA, speed);
	} else {
		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
		digitalWrite(enA, speed);
	}
}

void MotorControl::turnWheelB(bool forward, int speed)
{
	if(forward) {
		digitalWrite(in3, HIGH);
		digitalWrite(in4, LOW);
		digitalWrite(enB, speed);
	} else {
		digitalWrite(in3, LOW);
		digitalWrite(in4, HIGH);
		digitalWrite(enB, speed);
	}
}

void MotorControl::moveBothWheels(bool forward, int speed)
{
	turnWheelA(forward, speed);
	turnwheelB(forward, speed);
}