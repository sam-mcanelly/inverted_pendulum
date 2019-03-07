#include <Arduino.h>
#include "FastPID.cpp"
#include "FastPID.h"
#include "Encoder.cpp"
#include "Encoder.h"

int Position_to_Speed(int, int);
float Kp = 0.1, Ki = 0.1, Kd = 0.1, Hz = 100;//Kp, Ki, and Kd need to be tested
int output_bits = 16, output = 0;  
FastPID PID_Loop(Kp, Ki, Kd, Hz, output_bits, true);
Encoder encoder;

void setup() {
  
}

void loop() {
  Serial.println(Position_to_Speed(encoder.getPosition(), 0));
}

int Position_to_Speed (int Current_Position, int Set_Point) {
    return PID_Loop.step(Set_Point, Current_Position);
}
