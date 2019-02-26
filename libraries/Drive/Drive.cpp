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
	// Serial.println("Drive created");
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
	 for(int i = 0; i < front.MC_PIN_COUNT; i++) {
		Serial.print("Pin numbers: ");
		Serial.print(pinsFront[i]);
		serial.print(",");
		Serial.println(pinsBack[i]);
	}
	 
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
 void Drive::turnSingleWheelTest(int wheel, int speed)
 {
	 switch(wheel)
	 {
		 case 0:
			front.turnWheelA(true, speed);
			Serial.println("Front wheel A turned");
		 break;
		 case 1:
			front.turnWheelB(true, speed);
			Serial.println("Front wheel B turned");
		 break;
		 case 2:
			back.turnWheelA(true, speed);
			Serial.println("Back wheel A turned");
		 break;
		 case 3:
			back.turnWheelB(true, speed);
			Serial.println("Back wheel B turned");
		 break;
		 default: Serial.println("Invalid number");
	 }
 }
 