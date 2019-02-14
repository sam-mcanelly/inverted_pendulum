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

void Director::reset() {
    //constantly loop and look for an arm signal
    while(active == false) {
        //do nothing and wait
        receiver->update();
    }

    int starting_position = 0/*pendulum_reader->getPosition()*/;

    //wait for pendulum to be in an acceptable start range
    while(!within_range(starting_position)) {
        //delay here to wait?
        starting_position = 0/*pendulum_reader->getPosition()*/;
    }

    loop();
}

void Director::loop() {
    //create PID controller object here
    double set_point, input, output;
    //ex:
    //PID myPID(&input, &output, &set_point,2,5,1, DIRECT);

    while(active == true) {
        receiver->update();

        //set_point = convert_throttle(getThrottleValue());
        //input=pendulum_reader->getPosition();
        //myPID.compute()
        //(maybe convert output here to another value)
        //(could also be handled in the motor_controller object)
        //motor_controller->set_motors(output);
    }

    reset();
}

double Director::convert_throttle(int throttle_value) {

}