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
    Serial.println("Arming ESC!");
    driver.initialize();

    //set zero of pendulum with full reverse throttle
    while(throttle_value > receiver.getThrottleMin())
    {
        receiver.update();
        throttle_value = receiver.getThrottleValue();
    }
    Serial.println("Initializing encoder!");
    encoder.init();

    //make motors whine for half a second to signify 
    //encoder initialization
    driver.move(1370);
    delay(300);
    driver.move(1350);

    Serial.println("Initializing PID Loops");
    motor_pid.initialize(500, 4.78/*3.87*/, 0.0, 2.0, -650, 650);
    direction_pid.initialize(100, 0.32, 0.0, 0.0, -15, 15);

    is_init = true;
    reset();
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
        //receiver.update();
        //int val = receiver.getThrottleValue();
    }

    Serial.println("Starting loop!");

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
        encoder_set_point = direction_pid.compute(motor_set_point, motor_output);
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