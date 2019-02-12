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

void Director::start() {
    //create PID controller object here
    double set_point, input, output;
    //ex:
    //PID myPID(&input, &output, &set_point,2,5,1, DIRECT);

    while(true/*exit condition != true */) {
        receiver->update();

        //set_point = convert_throttle(getThrottleValue)
        //input=pendulum_reader->getPosition();
        //myPID.compute()
        //(maybe convert output here to another value)
        //(could also be handled in the motor_controller object)
        //motor_controller->set_motors(output);
        //update exit condition value
    }
}

void Director::stop() {
    //set exit condition variable
}

double Director::convert_throttle(int throttle_value) {

}