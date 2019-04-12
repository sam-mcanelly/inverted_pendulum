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
 #include "Servo.h"
 #include "Arduino.h"
 
 class Drive {
	 public:
		
		Drive();
		Drive(int changePin);
		
		//Allows setting Motor Controller pins to nondefault ones.
		void setESCPin(int changePin);
		void setPins(int changePin);
		void armESC();
		void initialize();
		
		/*Note: pulseWidth is a variable from 700 to 2000
		 *      with: 1350 meaning no movement
		 *			  700 meaning brake
		 *			  < 1350 meaning reverse
		 *			  > 1350 meaning throttle
		 */
		
		void move(int pulseWidth); //moves robot at specified speed and direction
		
		//void turn(int angle); // turns robot at specified speed and direction
		
		void configureThrottle();  //Most ESCs require you to calibrate it for different RC Remote values.
		void configureThrottle(int newNeutral, int newFullThrottle, int newBrake);
		
		void printESC();
		int getEscMax();
		int getEscMin();
		int getEscNeutral();
		
		//Note: default destructor should work fine
		
	 private:
		int pin = 9;
		Servo myESC;
		int neutral = 1350;
		int maxThrottle = 2000;
		int brake = 700;
 };
 
 #endif