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
 
 Drive::Drive(int *pinsA, int *pinsB)
 {
	 front.setPins(pinsA);
	 back.setPins(pinsB);
 
 }
 void Drive::setPinsFront(int *passedPins)
 {
	 front.setPins(passedPins);
 }
 
 void Drive::setPinsBack(int *passedPins)
 {
	 back.setPins(passedPins);
 }
 
 void Drive::setPins(int *pinsFront, int *pinsBack)
 {
	 front.setPins(pinsFront);
	 back.setPins(pinsBack);
 }
 
 void Drive::move(bool direction, int speed)
 {
	 front.moveBothWheels(direction, speed);
	 back.moveBothWheels(direction, speed);
 }
 
 
 void Drive::turn(bool direction, int speed)
 {
	 front.moveWheelsOpposite(direction, speed);
	 back.moveWheelsOpposite(direction, speed);
		 
 }
 