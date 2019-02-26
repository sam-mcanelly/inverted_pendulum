/* Drive.h
 *
 * Class for robot driving
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */
 
 #ifndef Drive_h
 #define Drive_h
 #include <MotorController.h>
 
 class Drive {
	 public:
	 
		const bool LEFT = false;
		const bool RIGHT = true;
		const bool FORWARD = true;
		const bool BACKWARD = false;
		
		Drive();
		Drive(int *pinsA, int *pinsB);
		
		void setPinsFront(int *passedPins);
		void setPinsBack(int *passedPins);
		void setPins(int *pinsFront, int *pinsBack);
		
		
		void turn(bool direction, int speed);
		void move(bool direction, int speed);
		void turnSingleWheelTest(int wheel, int speed);
		
		//Note: default destructor should work fine
		
	 private:
		MotorController front;
		MotorController back;
 };
 
 #endif