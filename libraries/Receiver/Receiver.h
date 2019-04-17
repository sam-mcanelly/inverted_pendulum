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
            _throttle_max = 30;
            _throttle_min = -30;
            _throttle_value = 0;
            _pin = 4;
            pinMode(_pin, INPUT);
        }
        Receiver(int pin, int t_max, int t_min)
        {
            _throttle_max = t_max;
            _throttle_min = t_min;
            _throttle_value = 0;
            _pin = pin;
            pinMode(pin, INPUT);
        }

        ~Receiver() { }

        void update();
        int getThrottleValue();
        int getThrottleMax();
        int getThrottleMin();

    private:
        int _throttle_max;
        int _throttle_min;
        int _throttle_value;
        int _pin;
};

#endif