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
  drive.initialize();
  PID_Loop.Configure();
}

void loop() {
  Serial.print("Input: ");
  Serial.print(100);
  Serial.print(", Output: ");
  drive.move(PID_Loop.Position_to_Speed(0, encoder.getPosition()));
}
