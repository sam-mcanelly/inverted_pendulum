/* MotorController.cpp
 *
 * Class for using a L298N Motor Controller with Arduino
 * See "MotorController.h" for method descriptions
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "MotorController.h"

/* DISCLAIMER, PINS = {enA,in1,in2,enB,in3,in4} */


 MotorController::MotorController()
 {
	// setPinsDefault();
 }
 
 MotorController::MotorController(int *passedPins)
 {
	 for(int i = 0; i < MC_PIN_COUNT; i++) {
		pins[i] = passedPins[i];
	}
 }
 
 void MotorController::setPins(int *passedPins)
 {
	for(int i = 0; i < MC_PIN_COUNT; i++) {
		pins[i] = passedPins[i];
	}
	initialize();
 }
 
 
 void MotorController::initialize()
{
	for(int i = 0; i < MC_PIN_COUNT; i++) {
		pinMode(pins[i], OUTPUT);
	}
}


/*Note: Velocity is a variable from -255 to 255
 *      with sign (+/-) defining wheel rotation direction
 *		and magnitude defining wheel speed
 */
void MotorController::turnWheelA(int velocity)
{
	if(velocity>>15 & 1) //Compares MSB to see if velocity is negative
	{
		digitalWrite(pins[in1], LOW);
		digitalWrite(pins[in2], HIGH);
		analogWrite(pins[enA],-1*velocity);  //Sends PWM signal
	} else {
		digitalWrite(pins[in1], HIGH);
		digitalWrite(pins[in2], LOW);
		analogWrite(pins[enA],velocity)
	}
}

void MotorController::turnWheelB(int velocity)
{
	if(velocity>>15 & 1) //Compares MSB to see if velocity is negative
	{
		digitalWrite(pins[in3], LOW);
		digitalWrite(pins[in4], HIGH);
		analogWrite(pins[enB],-1*velocity);  //Sends PWM signal
	} else {
		digitalWrite(pins[in3], HIGH);
		digitalWrite(pins[in4], LOW);
		analogWrite(pins[enB], velocity);
	}
}

void MotorController::moveBothWheels(int velocity)
{
	turnWheelA(velocity);
	turnWheelB(velocity);
}

void MotorController::moveWheelsOpposite(int velocity)
{
	turnWheelA(velocity);
	turnWheelB(velocity);
}