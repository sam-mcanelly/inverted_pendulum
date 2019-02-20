/* Encoder.h
 *
 * Class for reading ticks from quadrature encoder
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"
#include <digitalWriteFast.h>

#define ENCODER_INTERRUPT 4
#define PIN_A 19
#define PIN_B 25
#define START_TICKS 256 //parallel to ground (1/4 of 1024)

class Encoder {
    public:
        Encoder(){}

        void init();
        int getPosition();

    private:
        static volatile bool encoder_B_set;
        static volatile int encoder_ticks;

        static void _tick();
};

#endif