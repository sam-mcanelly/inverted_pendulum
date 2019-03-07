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
#include <stdio.h>

#include "Director.h"

bool Director::is_init = false;
// arguments; (P, I, D, Hz, bits, signed)
FastPID Director::pid_controller(1.5, 0.0, 0.0, 100, 16, true);

void Director::init() 
{
    if(is_init) return;

    active=true;

    Serial.println("Setting PID range");
    pid_controller.setOutputRange(MIN_PWM, MAX_PWM);
    delay(2000);

    Serial.println("Initializing Encoder");
    delay(1000);
    encoder.init();
    Serial.println("Encoder initialized");

    //initialize driver

    is_init = true;

}

void Director::reset()
{
    if(!is_init)
    {
        Serial.println("Cannot start Director! Improper config");
        return;
    }

    Serial.println("Waiting for active signal");

    //constantly loop and look for an arm signal
    while(active == false) {
        //do nothing and wait
        //receiver->update();
    }

    int starting_position = encoder.getPosition();

    Serial.println("Starting encoder value: ");

    //wait for pendulum to be in an acceptable start range
    while(!within_range(starting_position)) {
        starting_position = encoder.getPosition();
        Serial.println("Warning! Pendulum out of range...");
    }

    Serial.println("Starting PID Loop");
    loop();
}

void Director::loop()
{
    unsigned long cur_time, last_time = 0;
    int set_point, input, output = 0; 

    while(active == true) {
        //receiver->update();
        cur_time = millis();

        // 10m is 100hz
        if(cur_time - last_time > 10)
        {
            input = encoder.getPosition();
            output = pid_controller.step(set_point, input);
            driver.move(output);
        }

        last_time = cur_time;
        /*convert_throttle(receiver->getChannelValue(throttle));*/
        
    }

    reset();
}

int Director::convert_throttle(int throttle_value)
{
    //normalize throttle value to range specified by MAX_ANGLE_TICKS
    return (int)((throttle_value - 1500) / MAX_ANGLE_TICKS);
}