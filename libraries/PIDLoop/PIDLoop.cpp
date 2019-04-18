#include "PIDLoop.h"

//FastPID PIDLoop::fastPID(1.0, 1.0, 1.0, HZ, BITS, true);

bool PIDLoop::initialize(int hz, float p, float i, float d,
                         int low_range, int high_range) { //Set up PID Loop
  period = (1/hz) * 1000000l;
  last_time = micros();
  last_output = 0;
  _p = p;
  _i = i;
  _d = d;
  _hz = hz;
  fastPID.setCoefficients(p, i, d, hz);
  fastPID.setOutputRange(low_range, high_range); //Setup to accurately drive robot
}

void PIDLoop::updateP(float new_p)
{
  _p = new_p;
  fastPID.setCoefficients(_p, _i, _d, _hz);
}

int PIDLoop::compute(int desired_position, int current_position) {
    int output = 0;
    current_time = micros();
    long dt = current_time - last_time;
    if (dt >= period) { //If the PID Loop is ready, get new output
        output = fastPID.step(desired_position, current_position);
        last_time = current_time; //update time
        last_output = output; //Update last output
        return output;
    }
    return last_output; //Use if PID Loop isn't ready
}
