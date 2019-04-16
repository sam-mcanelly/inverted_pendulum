/* Drive.cpp
 *
 * Class for robot driving
 *
 * Luis Gomez
 * Oklahoma State University
 * Spring 2019
 *
 */
 
 #include "Drive.h"
 
 Drive::Drive()
 {
 }
 
 Drive::Drive(int changePin)
 {
	setESCPin(changePin); 
 }
 
 void Drive::initialize()
 {
	myESC.attach(pin);
	armESC();
 }
 
 void Drive::setESCPin(int changePin)
 {
	pin = changePin;
 }
 void Drive::setPins(int changePin)
 {
	pin = changePin;
 }
 
 void Drive::armESC()
 {
	 myESC.writeMicroseconds(1350);
	 delay(3000);
 }
 
 
 void Drive::move(int pulseWidth)
 {
	myESC.writeMicroseconds(pulseWidth);
 }
 
 
 
 /*
 void Drive::turn(int angle)
 {
	//Implement for Servo steering
 }
 */
 
 void Drive::configureThrottle()
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
 void Drive::configureThrottle(int newNeutral, int newFullThrottle, int newBrake)
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
 void Drive::printESC()
 {
	 Serial.print("Neutral: ");
	 Serial.println(neutral);
	 Serial.print("Max Throttle: ");
	 Serial.println(maxThrottle);
	 Serial.print("Brake: ");
	 Serial.println(brake);
 }
 