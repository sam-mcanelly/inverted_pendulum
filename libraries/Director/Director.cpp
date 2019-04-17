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

    int throttle_value = 1350;
    //arm esc by pulling full throttle on the controller
    while(throttle_value != receiver.getThrottleMax())
    {
        receiver.update();
        throttle_value = receiver.getThrottleValue();
    }

    active=true;
    driver.initialize();

    //set zero of pendulum with full reverse throttle
    while(throttle_value != receiver.getThrottleMin())
    {
        receiver.update();
        throttle_value = receiver.getThrottleValue();
    }
    encoder.init();

    //make motors whine for half a second to signify 
    //encoder initialization
    driver.move(1400);
    delay(500);
    driver.move(1350);

    motor_pid.initialize(1000, 3.336, 0.0, 7.0, -650, 650);
    direction_pid.initialize(100, 5.0, 0.0, 0.0, -30, 30);

    is_init = true;
}

void Director::reset()
{
    if(!is_init)
    {
        Serial.println("Cannot start Director! Improper config");
        return;
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
    int encoder_input, encoder_set_point = 0; 
    int throttle_val = 1350;

    while(active == true) {
        receiver.update();
        throttle_val = receiver.getThrottleValue();
        motor_set_point = throttle_val;
        encoder_set_point = motor_pid.compute(motor_set_point, motor_output);
        encoder_input = encoder.getPosition();

        //failure condition
        if(encoder_input > 400 || encoder_input < -400) { 
            driver.move(1350);
            break;
        }
        motor_output = motor_pid.compute(encoder_set_point, encoder_input) + 1350;
        driver.move(motor_output);
    }

    reset();
}