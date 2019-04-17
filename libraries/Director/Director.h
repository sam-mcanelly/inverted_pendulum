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

#define min_start_threshold -20
#define max_start_threshold 20
#define within_range(a) (((a) > (min_start_threshold)) && ((a) < (max_start_threshold)))

enum channel_t {
    throttle=0,
    turn=1
};

class Director {
    public:
        Director()
        {
            motor_output = 1350; //stall
            motor_set_point = 1350;
            is_init = false;
        };

        void init();

        //start and stop control loop
        void reset();

    private:
        static Encoder encoder;
        static bool is_init;
        int motor_set_point;
        int motor_output;
        bool active;

        Receiver receiver;
        Drive driver;
        PIDLoop direction_pid;
        PIDLoop motor_pid;

        //main control loop
        void loop();
};

#endif