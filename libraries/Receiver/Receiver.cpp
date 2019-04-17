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
    if(ret > 15000 || ret < 14000)
    {
        _throttle_value = 0;
    }
    else {
        ret = map(ret, 14000, 15000, -30, 30);
        _throttle_value = ret;
    }
}

int Receiver::getThrottleValue()
{
    return _throttle_value;
}
