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

bool Director::is_init = false;

void Director::init() 
{
    if(is_init) return;
    active=true;
	
    int throttle_value = 1350;

    //arm esc by pulling full throttle on the controller
    while(throttle_value < receiver.getThrottleMax())
    {
        receiver.update();
        throttle_value = receiver.getThrottleValue();
    }
    driver.initialize();
	driver.configureRevGain(0.78);

    //make motors whine for half a second to signify 
    //encoder initialization
    driver.move(1368);
    delay(1000);
    driver.move(1350);

    motor_pid.initialize(500, 7.0, 1.8, 10.0, -350, 350);
    direction_pid.initialize(100, 0.12, 0.0, 0.0, -15, 15);

    is_init = true;
}

void Director::reset()
{
    if(!is_init)
    {
        return;
    }

    int throttle_value = 1350;

    //set zero of pendulum with full reverse throttle
    while(throttle_value > receiver.getThrottleMin())
    {
        receiver.update();
        throttle_value = receiver.getThrottleValue();
    }
    motor_pid.clear();
    direction_pid.clear();
    encoder.init();

    motor_output = 1350;

    active = true;

    loop();
}

void Director::loop()
{
    int encoder_input, encoder_set_point, cycle_counter = 0; 
    int throttle_val, new_motor_output = 1350;


    while(active == true) {
        if(cycle_counter == 100) {
            receiver.update();
            throttle_val = receiver.getThrottleValue();
            cycle_counter = 0;
        } else {
            cycle_counter++;
        }
        motor_set_point = throttle_val;
        encoder_input = encoder.getPosition();

        //failure condition
        if(encoder_input > 300 || encoder_input < -300) { 
            driver.move(1350);
            active = false;
            break;
        }
        encoder_set_point = direction_pid.compute(motor_set_point, motor_output);
        new_motor_output = motor_pid.compute(encoder_set_point, encoder_input) + 1350;

        if(new_motor_output != motor_output) {
            motor_output = new_motor_output;
            driver.move(motor_output);
        }
    }
    reset();
}
