/* Receiver.h
 *
 * Class for reading and interpretting PPM Input
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef Receiver_h
#define Receiver_h

#include "Arduino.h"

#define SYNC_DELAY 11000
#define CHANNEL_COUNT 3
#define ARM_CHANNEL 2
#define ACTIVE_THRESHOLD 1500
#define UPDATE_TIMEOUT_THRESHOLD 20000 //us
#define CHANNEL_TIMEOUT_THRESHOLD 3000 //us

class Receiver {
    public:
        Receiver(int pin, bool *active)
        {
            //set pin
            _pin = pin;
            pinMode(pin, INPUT);
            _active = active;
        }

        ~Receiver() { }

        void update();
        int getChannelValue(int channel);
        const int *getAllChannels();

    private:
        bool *_active;
        int channel_values[3] = {1000, 1000, 1000};
        int _pin;
};

#endif