/* MotorControl.h
 *
 * Class for using MotorControl (L298N)
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

/* DISCLAIMER, PINS = {enA,in1,in2,enB,in3,in4} */

class MotorControl {
    public:
		MotorControl();
		MotorControl(int *passedPins);
		void initialize(); //Should be run after creating creating MotorControl object.
		
		void setPinsDefault(); // default case
        void setPins(int *passedPins); // pin order: enA, in1, in2, enB, in3, in4

		/* direction = true when you move wheels with respect to wiring
		 * speed = 0-255 where 0 is none and 255 is max
		 */
        void turnWheelA(bool direction, int speed);
		void turnWheelB(bool direction, int speed);
		void moveBothWheels(bool direction, int speed);
		
		
		/* direction = TRUE for left and FALSE for right
		 * speed = 0-255 where 0 is none and 255 is max
		 */
		void moveWheelsOpposite(bool turnDirection, int speed);
		~MotorControl(){};
    private:
	int defaultPins[6] = {10, 9, 8, 5,7,6};
	int enA,in1,in2,enB,in3,in4;
};

