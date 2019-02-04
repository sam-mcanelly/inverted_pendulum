/* Receiver.h
 *
 * Class for reading and interpretting PPM Input
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef RECEIVER_H
#define RECEIVER_H

//#include "Arduino.h"

class Receiver {
    public:
        Receiver(int pin) {
            //set pin
            //pinMode(pin, INPUT_PULLUP);
            channel_values = new int[6];
        };

        ~Receiver() {
            delete channel_values;
        };

        void update();
        int getChannelValue(int channel);

    private:
        int *channel_values;
};

#endif
