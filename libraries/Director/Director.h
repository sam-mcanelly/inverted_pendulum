/* Director.h
 *
 * Class for combining the individual libraries
 * of the project and coordinating their interaction
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef Director_h
#define Director_h

#include "Arduino.h"
#include "Encoder.h"
//#include <FastPID.h>
#include "Receiver.h"

#define MAX_ANGLE_TICKS 86 //used to set max speed (this is 30 degrees off center if center is 0)

#define min_start_threshold -1
#define max_start_threshold 1
#define within_range(a) (((a) > (min_start_threshold)) && ((a) < (max_start_threshold)))

enum channel_t {
    throttle=0,
    turn=1
};

class Director {
    public:
        Director(int receiver_pin, int motor_pins[4])
        {
            active=false;
            encoder.init();
            receiver = new Receiver(receiver_pin, &active);
        };

        ~Director()
        {
            delete receiver;
            //delete other dynamically allocated objects
        }

        //start and stop control loop
        void reset();

    private:
        bool active;
        Receiver* receiver;
        Encoder encoder;
        //Drive drive;

        //main control loop
        void loop();

        int getThrottleValue() { return receiver->getChannelValue(throttle); }
        int getTurnValue() { return receiver->getChannelValue(turn); }

        //convert the throttle value to a set_point value
        //this will allow the cart to go backwards or forwards
        int convert_throttle(int throttle_value);
};

#endif