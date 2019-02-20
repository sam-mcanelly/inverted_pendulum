/* Encoder.cpp
 *
 * Class for reading ticks from quadrature encoder
 *
 * Sam McAnelly
 * Oklahoma State University
 * Spring 2019
 *
 */

#include "Encoder.h"

void Encoder::init()
{
    pinMode(PIN_A, INPUT_PULLUP);
    pinMode(PIN_B, INPUT_PULLUP);

    encoder_ticks = START_TICKS;

    attachInterrupt(ENCODER_INTERRUPT, Encoder::_tick, RISING);
}

int Encoder::getPosition()
{
    return encoder_ticks;
}

void Encoder::_tick()
{
    encoder_B_set = digitalReadFast(PIN_B);

    //increment if A leads B
    #ifdef ENCODER_REVERSED
        encoder_ticks -= (encoder_B_set) ? -1 : 1;
    #else
        encoder_ticks += (encoder_B_set) ? -1 : 1;
    #endif
}