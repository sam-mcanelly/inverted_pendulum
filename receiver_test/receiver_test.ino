#include <Receiver.h>
#include <Drive.h>

bool active = false;
Receiver _receiver;
Drive _drive;

void setup() {
  Serial.begin(9600);
  delay(500);

  _drive.initialize();
}

void loop() {
  _receiver.update();
  long _throttle_value = _receiver.getThrottleValue();
  //Serial.println(_throttle_value);
  _drive.move(_throttle_value);
  delay(1);
  
  //Serial.print("Armed: ");
  //Serial.println(active);

  
  //Serial.println(_throttle_value);

}

