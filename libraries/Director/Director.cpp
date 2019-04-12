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

    Serial.println("Initializing Encoder");
    delay(1000);
    encoder.init();
    Serial.println("Encoder initialized");

    pid_controller.initialize();
    

    driver.initialize();

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
    int set_point, input, output = 0; 

    while(active == true) {
        //receiver->update();
        input = encoder.getPosition();
        if(input > 400 || input < -400) { 
            driver.move(1350);
            break;
        }
        output = pid_controller.position_to_speed(set_point, input);
        //Serial.println(encoder.getPosition());
        Serial.println(output);
        driver.move(output);
        /*convert_throttle(receiver->getChannelValue(throttle));*/
    }

    reset();
}

int Director::convert_throttle(int throttle_value)
{
    //normalize throttle value to range specified by MAX_ANGLE_TICKS
    return (int)((throttle_value - 1500) / MAX_ANGLE_TICKS);
}