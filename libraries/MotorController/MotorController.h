/* MotorController.h
 *
 * Class for using a L298N Motor Controller with Arduino
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef MotorController_h
#define MotorController_h

#define MC_PIN_COUNT 6 // Total Pins on single L298N

#include "Arduino.h"

// Each Controller has 2 PWM inputs (enA, enB) and 4 digital inputs (in1,in2,in3,in4)
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
		//Class Constructors
		MotorController();
		MotorController(int *passedPins);

        void setPins(int *passedPins); // pin order: enA, in1, in2, enB, in3, in4
		void initialize();  // Is ran after creating MotorController object and during setPins.

		/* Note: Velocity is a variable from -255 to 255
		 *       with sign (+/-) defining wheel rotation direction
		 *       and magnitude defining wheel speed.
		 *		 Motor Controller has "A" side and "B" side
		 */
        void turnWheelA(int velocity);
		void turnWheelB(int velocity);
		
		void moveBothWheels(int velocity);     // Turns both wheels in same direction at same speed
		void moveWheelsOpposite(int velocity); //Turns Both wheels in opposite directions at same speed
		
		~MotorController(){}; //Destructor just in case
		
    private:
		int pins[6] = {-1, -1, -1, -1, -1, -1};
		int defaultPins[MC_PIN_COUNT] = {10, 9, 8, 5, 7, 6};
};

#endif
