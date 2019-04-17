#ifndef PIDLoop_h
#define PIDLoop_h

#include "Arduino.h"
#include <digitalWriteFast.h>
#include "FastPID.h"

#define HZ 1000 //Frequency to run PID Loop
#define BITS 16 //Set the number of bits for PID Loop output
#define TIME (1/HZ * 1000) //Used in Position_to_Speed

class PIDLoop {
public:
    bool initialize(); //Sets up PID Loop
    int positionToSpeed(int desired_position, int current_position); //Runs the PID Loop
    
private:
    static FastPID fastPID; //PID code that handles PID calculation
    long current_time, last_time; //Time used in Position_to_Speed
    int last_output; //Used in Position_to_Speed
};

#endif
