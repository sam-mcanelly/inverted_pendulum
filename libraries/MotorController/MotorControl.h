/* MotorControl.h
 *
 * Class for using MotorControl (L298N)
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */


//#include "Arduino.h"

/* DISCLAIMER, PINS = {enA,in1,in2,enB,in3,in4} */

class MotorControl {
    public:
		MotorControl();
		MotorControl(int *passedPins);
		void initialize(); //Should be run after creating creating MotorControl object.
		
		setPinsDefault(); // default case
        setPins(int *passedPins); // pin order: enA, in1, in2, enB, in3, in4

		/* Forward = true when you move wheels with respect to wiring
		 * Speed = 0-255 where 0 is none and 255 is max
		 */
        void turnWheelA(bool forward, int speed);
		void turnWheelB(bool forward, int speed);
		void moveBothWheels(bool forward, int speed);
		
		~MotorControl()
		{
			destroy pins;
		};
    private:
	int pins[];
	int defaultPins[] = {10, 9, 8, 5,7,6};
};

#endif
