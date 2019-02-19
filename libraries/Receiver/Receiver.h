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

#define SYNC_DELAY 4000
#define CHANNEL_COUNT 6
#define ARM_CHANNEL 3
#define ACTIVE_THRESHOLD 1500
#define UPDATE_TIMEOUT_THRESHOLD 30000 //30ms (chosen from Wikipedia PPM frame length)

class Receiver {
    public:
        Receiver(int _pin, bool *_active)
        {
            //set pin
            pin=_pin;
            pinMode(pin, INPUT_PULLUP);
            active = _active;
            channel_values = new int[6];
        }

        ~Receiver()
        {
            delete channel_values;
        }

        void update();
        int getChannelValue(int channel);

    private:
        bool *active;
        int *channel_values;
        int pin;
};

#endif
