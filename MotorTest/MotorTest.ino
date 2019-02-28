#include <Drive.h>
#include <MotorController.h>
Drive driver;
 // pins = {enA,in1,in2,enB,in3,in4};
  int pinsA[6] = {3,4,2,5,6,7};
  int pinsB[6] = {9,8,10,11,12,13};
  
void setup() {
  driver.setPins(pinsA,pinsB);
}

void loop() {
  
  driver.turn(255);
  delay(1000);
  driver.move(-255);
  delay(1000);
}
