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
    //bool updated = false;
    //int i = 0;

    //long start_time = micros();
    long ret = pulseIn(_pin, LOW);
    ret = map(ret, 14000, 15000, 700, 2000);
    if(ret < 1450 && ret > 1250) _throttle_value = 1350;
    else _throttle_value = ret;

    // while(!updated) {
    //     if(pulseIn(_pin, LOW, UPDATE_TIMEOUT_THRESHOLD) >= SYNC_DELAY) {
    //         for(i = 0; i < CHANNEL_COUNT; i++) {
    //             channel_values[i] = pulseIn(_pin, LOW, CHANNEL_TIMEOUT_THRESHOLD);
    //         }

    //         if(channel_values[ARM_CHANNEL] > ACTIVE_THRESHOLD) {
    //             _active = true;
    //         } else {
    //             _active = false;
    //         }

    //         updated = true;
    //     }

    //     if(micros() - start_time > UPDATE_TIMEOUT_THRESHOLD) {
    //         Serial.println("Error: PPM signal not found!");
    //         return;
    //     }
    // }
}

int Receiver::getThrottleValue()
{
    return _throttle_value;
}

// const int *Receiver::getAllChannels()
// {
//     return channel_values;
// }