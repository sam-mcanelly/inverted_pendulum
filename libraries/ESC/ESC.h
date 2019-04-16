/* ESC.h
 *
 * Class for using a 60A Quicrun ESC for DC brushed motor
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef ESC_h
#define ESC_h

#define MC_PIN_COUNT 6 // Total Pins on single L298N

#include "Arduino.h"
#include "Servo.h"

// Each Controller has 2 PWM inputs (enA, enB) and 4 digital inputs (in1,in2,in3,in4)


class ESC {
    public:
		//Class Constructors
		ESC();
		ESC(int assignPin);

        void setPin(int assignPin); // pin order: enA, in1, in2, enB, in3, in4
		void initialize();  // Is ran after creating ESC object and during setPins.
		void arm();
	/*Note: pulseWidth is a variable from 700 to 2000
	 *      with: 1350 meaning no movement   
	 *			  700 meaning brake
	 *			  < 1350 meaning reverse
	 *			  > 1350 meaning throttle
	 */
		void move(int pulseWidth);   

		
		void configureThrottle();  //Most ESCs require you to calibrate it for different RC Remote values.
		void configureThrottle(int newNeutral, int newFullThrottle, int newBrake);
		
		~ESC(){}; //Destructor just in case
		
		int getNeutral();
		int getMaxThrottle();
		int getBrake();
		
    private:
		int PIN = 9;
		Servo myESC;
		int neutral = 1350;
		int maxThrottle = 2000;
		int brake = 700;
};

#endif
