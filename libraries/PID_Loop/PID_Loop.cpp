#include "PID_Loop.h"

#define LOWRANGE 700 //Low range for driving robot
#define HIGHRANGE 2000 //High range for driving robot

FastPID PIDLoop::fastPID(22, 0, 0, 1000, 16, true);

bool PIDLoop::initialize() { //Set up PID Loop
  last_time = millis();
  last_output = 1350;
  fastPID.setOutputRange(-650, 650); //Setup to accurately drive robot
}

int PIDLoop::position_to_speed (int Desired_Position, int Current_Position) {
    int output = 0;
    current_time = micros();
    if (current_time - last_time >= 1000) { //If the PID Loop is ready, get new output
        output = fastPID.step(Desired_Position, Current_Position) + 1350;
        last_time = current_time; //update time
        last_output = output; //Update last output
        return output;
    }
    return last_output; //Use if PID Loop isn't ready
}
