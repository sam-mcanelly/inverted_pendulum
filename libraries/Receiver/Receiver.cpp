/* Receiver.cpp
 *
 * Class for reading and interpretting PPM Input
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "Receiver.h"

//TODO: sanity check on values? (test to see if necessary)
//      turn off interrupts? (time this function)
void Receiver::update() 
{
    long ret = pulseIn(_pin, LOW);
    ret = map(ret, 14000, 15000, -30, 30);
    _throttle_value = ret;
}

int Receiver::getThrottleValue()
{
    return _throttle_value;
}
