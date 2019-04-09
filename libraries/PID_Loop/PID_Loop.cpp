#include "PID_Loop.h"

bool PIDLoop::Configure() {
  fastPID.configure(KP, KI, KD, HZ, BITS, true);
}

int PIDLoop::Position_to_Speed (int Desired_Position, int Current_Position) {
    int output = 0;
    current_time = millis();
    if ((current_time - last_time) >= TIME) {
        output = fastPID.step(Desired_Position, Current_Position);
        last_time = current_time;
        last_output = output;
        return output;
    }
    return last_output;
}
