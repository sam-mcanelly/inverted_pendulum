#ifndef PID_Loop_h
#define PID_Loop_h

#include "Arduino.h"
#include <digitalWriteFast.h>
#include "FastPID.h"

#define KP 0.1 //Proportional constant
#define KI 0.3 //Integral constant
#define KD 0.4 //Derivative constant
#define HZ 100 //Frequency to run PID Loop
#define BITS 16 //Set the number of bits for PID Loop output
#define TIME (1/HZ * 1000) //Used in Position_to_Speed

class PIDLoop {
public:
    bool initialize(); //Sets up PID Loop
    int position_to_speed(int Desired_Position, int Current_Position); //Runs the PID Loop
    
private:
    static FastPID fastPID; //PID code that handles PID calculation
    long current_time, last_time; //Time used in Position_to_Speed
    int last_output; //Used in Position_to_Speed
};

#endif
