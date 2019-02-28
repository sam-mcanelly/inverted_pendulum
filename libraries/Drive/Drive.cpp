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
	/* Serial.println("Setting Pins [Drive accessed]");
	 for(int i = 0; i < 6; i++) {
		Serial.print("Pin numbers: ");
		Serial.print(pinsFront[i]);
		Serial.print(",");
		Serial.println(pinsBack[i]);
	}
	 */
	 front.setPins(pinsFront);
	 back.setPins(pinsBack);
 }
 
 void Drive::move(int velocity)
 {
	 front.moveBothWheels(velocity);
	 back.moveBothWheels(-velocity);
 }
 
 
 void Drive::turn(int velocity)
 {
	 front.moveWheelsOpposite(velocity);
	 back.moveWheelsOpposite(velocity);
		 
 }
 void Drive::turnSingleWheelTest(int wheel, int speed)
 {
	 switch(wheel)
	 {
		 case 0:
			front.turnWheelA(speed);
			//Serial.println("Front wheel A turned");
		 break;
		 case 1:
			front.turnWheelB(speed);
			//Serial.println("Front wheel B turned");
		 break;
		 case 2:
			back.turnWheelA(speed);
			//Serial.println("Back wheel A turned");
		 break;
		 case 3:
			back.turnWheelB(speed);
			//Serial.println("Back wheel B turned");
		 break;
		 default: Serial.println("Invalid number");
	 }
 }
 