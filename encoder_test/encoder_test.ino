#include <Encoder.h>

Encoder _encoder;
int enc_val;

void setup() {
  enc_val = 0;
  
  Serial.begin(9600);  
  _encoder.init();
}

void loop() {
  enc_val = _encoder.getPosition();
  Serial.print("Encoder value: ");
  Serial.println(enc_val);
}
