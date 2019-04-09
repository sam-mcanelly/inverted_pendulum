#ifndef PID_Loop_h
#define PID_Loop_h

#include <Arduino.h>
#include <digitalWriteFast.h>
#include "FastPID.h"

#define KP 0.1
#define KI 0.3
#define KD 0.4
#define HZ 100
#define BITS 16
#define TIME (1/HZ * 1000);

class PIDLoop {
public:
    FastPID fastPID;
    bool Configure();
    int Position_to_Speed(int Desired_Position, int Current_Position);
    
private:
    long current_time, last_time;
    int last_output;
};

#endif
