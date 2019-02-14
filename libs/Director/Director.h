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
#define Director_H

//#include "Arudino.h"
//#include "PIDLibrary.h"
#include "Receiver.h"

#define min_start_threshold -1
#define max_start_threshold 1
#define within_range(a) (((a) > (min_start_threshold)) && ((a) < (max_start_threshold)))

enum Channel {
    throttle=0,
    turn=1
};

class Director {
    public:
        Director(int receiver_pin, int motor_pins[4], int pendulum_pin) {
            active=false;
            receiver = new Receiver(receiver_pin, &active);
        };

        ~Director() {
            delete receiver;
            //delete other dynamically allocated objects
        }

        //start and stop control loop
        void reset();

    private:
        bool active;
        Receiver* receiver;
        //motor controller object;
        //pendulum reader object; 

        //main control loop
        void loop();

        int getThrottleValue() { return receiver->getChannelValue(throttle); }
        int getTurnValue() { return receiver->getChannelValue(turn); }

        //convert the throttle value to a set_point value
        //this will allow the cart to go backwards or forwards
        double convert_throttle(int throttle_value);
};

#endif