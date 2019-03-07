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
#include "Drive.h"
#include "Encoder.h"
#include "FastPID.h"
//#include "Receiver.h"

#define MAX_ANGLE_TICKS 86 //used to set max speed (this is 30 degrees off center if center is 0)
#define MIN_PWM -255
#define MAX_PWM 255

#define min_start_threshold -50
#define max_start_threshold 50
#define within_range(a) (((a) > (min_start_threshold)) && ((a) < (max_start_threshold)))

enum channel_t {
    throttle=0,
    turn=1
};

class Director {
    public:
        Director(/*int receiver_pin, int motor_pins[4]*/)
        {
            is_init = false;
            //receiver = new Receiver(receiver_pin, &active);
        };

        ~Director()
        {
            //delete receiver;
            //delete other dynamically allocated objects
        }

        void init();

        //start and stop control loop
        void reset();

    private:
        bool active;
        //Receiver* receiver;
        static Encoder encoder;
        static Drive driver;
        static FastPID pid_controller;
        static bool is_init;
        //Drive drive;

        //main control loop
        void loop();

        //int getThrottleValue() { return receiver->getChannelValue(throttle); }
        //int getTurnValue() { return receiver->getChannelValue(turn); }

        //convert the throttle value to a set_point value
        //this will allow the cart to go backwards or forwards
        int convert_throttle(int throttle_value);
};

#endif