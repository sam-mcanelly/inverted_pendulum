#ifndef PIDLoop_h
#define PIDLoop_h

#include "Arduino.h"
#include <digitalWriteFast.h>
#include "FastPID.h"

#define HZ 500 //Default Frequency to run PID Loop
#define BITS 16 //Set the number of bits for PID Loop output

class PIDLoop {
public:
    PIDLoop()
    {
        fastPID.configure(1.0, 1.0, 1.0, HZ, BITS, true);
    }
    bool initialize(int hz, float p, float i, float d,
                    int low_range, int high_range); //Sets up PID Loop
    int compute(int desired_position, int current_position); //Runs the PID Loop
    void updateP(float new_p);
    
private:
    FastPID fastPID; //PID code that handles PID calculation
    long current_time, last_time; //Time used in Position_to_Speed
    int last_output; //Used in Position_to_Speed
    long period;

    float _p, _i, _d;
    int _hz;
};

#endif
