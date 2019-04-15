#include "PID_Loop.h"

#define LOWRANGE -650 //Low range for driving robot
#define HIGHRANGE 650 //High range for driving robot

FastPID PIDLoop::fastPID(4.5, 0, 0, HZ, BITS, true);

bool PIDLoop::initialize() { //Set up PID Loop
  last_time = micros();
  last_output = 1350;
  fastPID.setOutputRange(LOWRANGE, HIGHRANGE); //Setup to accurately drive robot
}

int PIDLoop::positionToSpeed(int desired_position, int current_position) {
    int output = 0;
    current_time = micros();
    if (current_time - last_time >= 1000) { //If the PID Loop is ready, get new output
        output = fastPID.step(desired_position, current_position) + 1350;
        last_time = current_time; //update time
        last_output = output; //Update last output
        return output;
    }
    return last_output; //Use if PID Loop isn't ready
}
