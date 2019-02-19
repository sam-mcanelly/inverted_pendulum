/* Drive.h
 *
 * Class for robot driving
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */
 #include "MotorControl.h"
 class Drive {
	 public:
		Drive();
		Drive(int *pinsA, int *pinsB);
		
		void setPinsFront(int *passedPins);
		void setPinsBack(int *passedPins);
		void setPins(int *pinsFront, int *pinsBack);
		
		
		void turn(bool direction, int speed);
		void move(bool direction, int speed);
		
		
	 private:
		const bool LEFT = false;
		const bool RIGHT = true;
		MotorControl front, back;
 };