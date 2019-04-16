/* ESC.cpp
 *
 * Class for using a 60A ESC for DC brushed motor
 * See "ESC.h" for method descriptions
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "ESC.h"

 ESC::ESC()
 {
	initialize();
 }
 
 ESC::ESC(int assignPin)
 {
	PIN = assignPin;
	initialize();
 }
 
 void ESC::setPin(int assignPin)
 {
	PIN = assignPin;
	initialize();
 }
 
 
 void ESC::initialize()
 {
	 myESC.attach(PIN);
 }
 
 void ESC::arm()
 {
	 Serial.print ("Arming... ");
	 myESC.writeMicroseconds(1350);
	 delay(30000);
	 Serial.println("DONE");
 }

 int ESC::getNeutral()
 {
	 return neutral;
 }
 
 int ESC::getMaxThrottle()
 {
	 return maxThrottle;
 }
 
 int ESC::getBrake()
 {
	 return brake;
 }

/*Note: pulseWidth is a variable from 700 to 2000
 *      with: 1350 meaning no movement
 *			  700 meaning brake
 *			  < 1350 meaning reverse
 *			  > 1350 meaning throttle
 */
 void ESC::move(int pulseWidth)
 {
	 myESC.writeMicroseconds(pulseWidth);
 }
 
 /* Note: Quicrun WP brushed only takes values between 700 and 2000;
  *		  For a Quicrun ESC: hold the set button while powering on motors.
  *		  Then run configureThrottle().
  *       To configure another esc, refer to the motor controller manual 
  *       and use configureThrottle(int neutralPos, int fullThrottlePos, int brakePos)
  */
void ESC::configureThrottle()
 {
	
	myESC.writeMicroseconds(1350);
	Serial.println("Neutral Position: 1350");
	delay(10000);
	
	myESC.write(2000);
	Serial.println("Full Throttle: 2000");
	delay(10000);
			
	myESC.writeMicroseconds(700);
	Serial.println("Brake Position: 700");
	delay(10000);
	
 }
 
 // Remember to write down the values you used if you use the following method.
 void ESC::configureThrottle(int newNeutral, int newFullThrottle, int newBrake)
 {
	
	neutral = newNeutral;
	maxThrottle = newFullThrottle;
	brake = newBrake;
	
	myESC.writeMicroseconds(neutral);
	Serial.println("Neutral Position: 1350");
	delay(10000);
	
	myESC.write(maxThrottle);
	Serial.println("Full Throttle: 2000");
	delay(10000);
			
	myESC.writeMicroseconds(brake);
	Serial.println("Brake Position: 700");
	delay(10000);
	
 }
 
 