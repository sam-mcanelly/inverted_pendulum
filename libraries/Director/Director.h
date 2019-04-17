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
#include "MotorController.h"
#include "Encoder.h"
#include "PIDLoop.h"
#include "Receiver.h"

#define MAX_ANGLE_TICKS 86 //used to set max speed (this is 30 degrees off center if center is 0)
#define MIN_PWM -255
#define MAX_PWM 255

#define min_start_threshold -20
#define max_start_threshold 20
#define within_range(a) (((a) > (min_start_threshold)) && ((a) < (max_start_threshold)))

enum channel_t {
    throttle=0,
    turn=1
};

class Director {
    public:
        Director(/*int receiver_pin, int motor_pins[4]*/)
        {
            set_point = 0;
            is_init = false;
        };

        ~Director()
        {
            //delete other dynamically allocated objects
        }

        void init();

        //start and stop control loop
        void reset();

    private:
        static Encoder encoder;
        static bool is_init;
        int set_point;
        bool active;

        Receiver receiver;
        Drive driver;
        PIDLoop pid_controller;

        //main control loop
        void loop();

        //convert the throttle value to a set_point value
        //this will allow the cart to go backwards or forwards
        int convert_throttle(int throttle_value);
};

#endif