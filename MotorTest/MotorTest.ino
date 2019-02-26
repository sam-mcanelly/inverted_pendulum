#include <Drive.h>
#include <MotorController.h>
Drive driver;
MotorController a;
 // pins = {enA,in1,in2,enB,in3,in4};
  int pinsA[6] = {11,4,2,5,6,7};
  int pinsB[6] = {9,8,10,7,12,13};
  
void setup() {
  Serial.begin(9600);
  Serial.println("Begin Program");

  driver.setPins(pinsA,pinsB);
}

void loop() {
  driver.move(true,255);
   //driver.turnSingleWheelTest(2,255);
  delay(500);
}
