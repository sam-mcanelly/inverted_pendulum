/* Director.cpp
 *
 * Class for combining the individual libraries
 * of the project and coordinating their interaction
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "Director.h"

void Director::reset()
{
    //constantly loop and look for an arm signal
    while(active == false) {
        //do nothing and wait
        receiver->update();
    }

    int starting_position = encoder.getPosition();

    //wait for pendulum to be in an acceptable start range
    while(!within_range(starting_position)) {
        starting_position = encoder.getPosition();
    }

    loop();
}

void Director::loop()
{
    //create PID controller object here
    double set_point, input, output;
    //ex:

    while(active == true) {
        receiver->update();

        set_point = convert_throttle(receiver->getChannelValue(throttle));
        input = encoder.getPosition();
        //compute PID
        //(maybe convert output here to another value)
        //(could also be handled in the motor_controller object)
        //motor_controller->set_motors(output);
    }

    reset();
}

int Director::convert_throttle(int throttle_value)
{
    //normalize throttle value to range specified by MAX_ANGLE_TICKS
    return (int)((throttle_value - 1500) / MAX_ANGLE_TICKS);
}