#include "Receiver.h"

bool active = false;
const int *channel_values;
Receiver _receiver(A0, &active);

void setup() {
  Serial.begin(9600);
  delay(500);
}

void loop() {
  _receiver.update();
  channel_values = _receiver.getAllChannels();
  
  Serial.print("Armed: ");
  Serial.println(active);

  Serial.println("---- Channel Values ----");
  for(int i = 0; i < CHANNEL_COUNT; i++) {
    Serial.print("  ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(channel_values[i]);
  }
  Serial.println("\n");

  delay(500);
}
