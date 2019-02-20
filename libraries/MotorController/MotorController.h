/* MotorController.h
 *
 * Class for using MotorControl (L298N)
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef MotorController_h
#define MotorController_h

#define MC_PIN_COUNT 6

#include "Arduino.h"

/* DISCLAIMER, PINS = {enA,in1,in2,enB,in3,in4} */

enum mc_pins_t {
	enA,
	in1,
	in2,
	enB,
	in3,
	in4
};

class MotorController {
    public:
		MotorController();
		MotorController(int *passedPins);
		void initialize(); //Should be run after creating MotorController object.
		
		void setPinsDefault(); // default case
        void setPins(int *passedPins); // pin order: enA, in1, in2, enB, in3, in4

		/* Forward = true when you move wheels with respect to wiring
		 * Speed = 0-255 where 0 is none and 255 is max
		 */
        void turnWheelA(bool forward, int speed);
		void turnWheelB(bool forward, int speed);
		void moveBothWheels(bool forward, int speed);
		void moveWheelsOpposite(bool turnDirection, int speed);
		
		~MotorController()
		{
			//this will only be needed for dynamically allocated variables
			if(pins != defaultPins)
				delete pins;
		};
    private:
		int *pins;
		int defaultPins[MC_PIN_COUNT] = {10, 9, 8, 5, 7, 6};
};

#endif
