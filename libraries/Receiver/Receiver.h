/* Receiver.h
 *
 * Class for reading and interpretting 
 * pulse length on an analog pin
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
#define UPDATE_TIMEOUT_THRESHOLD 200000 //us
#define CHANNEL_TIMEOUT_THRESHOLD 3000 //us

class Receiver {
    public:
        Receiver()
        {
            _throttle_value = 0;
            _pin = 4;
            pinMode(_pin, INPUT);
        }
        Receiver(int pin, bool active)
        {
            _throttle_value = 0;
            _pin = pin;
            pinMode(pin, INPUT);
        }

        ~Receiver() { }

        void update();
        int getThrottleValue();

    private:
        int _throttle_value;
        int _pin;
};

#endif