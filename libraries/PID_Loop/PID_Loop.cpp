#include "PID_Loop.h"

#define LOWRANGE 700 //Low range for driving robot
#define HIGHRANGE 2000 //High range for driving robot

bool PIDLoop::Configure() { //Set up PID Loop
  fastPID.configure(KP, KI, KD, HZ, BITS, true);
  fastPID.setOutputRange(LOWRANGE, HIGHRANGE); //Setup to accurately drive robot
}

int PIDLoop::Position_to_Speed (int Desired_Position, int Current_Position) {
    int output = 0;
    current_time = millis();
    if ((current_time - last_time) >= TIME) { //If the PID Loop is ready, get new output
        output = fastPID.step(Desired_Position, Current_Position);
        last_time = current_time; //update time
        last_output = output; //Update last output
        return output;
    }
    return last_output; //Use if PID Loop isn't ready
}
