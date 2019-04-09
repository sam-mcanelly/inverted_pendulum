#include <digitalWriteFast.h>
#include <Arduino.h>
#include "Encoder.h"
#include "PID_Loop.h"

Drive drive;
Encoder encoder;
PIDLoop PID_Loop;

void setup() {
  Serial.begin(9600);
  encoder.init();
  PID_Loop.Configure();
}

void loop() {
  Serial.print("Input: ");
  Serial.print(100);
  Serial.print(", Output: ");
  drive.move(0, 20));
}
