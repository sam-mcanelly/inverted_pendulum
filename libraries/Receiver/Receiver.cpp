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

void Receiver::update() {
    //read pulse in
    //wait for long gap
    //once long gap is detected, start reading pulse-ins
    //update channel_value array with new values
    //set active variable based on the designated channel
    //if(channel_value[ARM_CHANNEL] > SOME_VALUE)
    //  *active=true
}

int Receiver::getChannelValue(int channel) {
    //check bounds
    if(channel < 1 || channel > 6)
        return -1;
    
    return channel_values[channel];
}