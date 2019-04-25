/* Receiver.cpp
 *
 * Class for reading and interpretting 
 * pulse length on an analog pin
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "Receiver.h"

void Receiver::update() 
{
    long ret = pulseIn(_pin, LOW);
    ret = map(ret, 14000, 15000, -200, 200);
    ret += 1350;
    _throttle_value = ret;
}

int Receiver::getThrottleValue()
{
    return _throttle_value;
}

int Receiver::getThrottleMax()
{
    return _throttle_max;
}

int Receiver::getThrottleMin()
{
    return _throttle_min;
}
