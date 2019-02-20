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
    bool updated = false;
    int i = 0;

    long start_time = micros();

    while(!updated) {
        if(pulseIn(pin, HIGH) > SYNC_DELAY) {
            for(i = 0; i < CHANNEL_COUNT; i++) {
                channel_values[i] = pulseIn(pin, HIGH);
            }

            if(channel_values[ARM_CHANNEL] > ACTIVE_THRESHOLD) {
                *active = true;
            } else {
                *active = false;
            }

            updated = true;
        }

        if(micros() - start_time > UPDATE_TIMEOUT_THRESHOLD) {
            Serial.println("Error: PPM signal not found!");
            return;
        }
    }
}

int Receiver::getChannelValue(int channel)
{
    //check bounds
    if(channel < 1 || channel > CHANNEL_COUNT)
        return -1;
    
    return channel_values[channel - 1];
}

const int *Receiver::getAllChannels()
{
    return channel_values;
}