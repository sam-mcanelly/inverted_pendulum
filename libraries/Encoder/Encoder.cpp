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

volatile bool Encoder::encoder_A_set = 0;
volatile bool Encoder::encoder_B_set = 0;
volatile int Encoder::encoder_ticks = START_TICKS;

void Encoder::init()
{
    pinMode(PIN_A, INPUT_PULLUP);
    pinMode(PIN_B, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(PIN_A), Encoder::_tick, FALLING);
	attachInterrupt(digitalPinToInterrupt(PIN_B), Encoder::_tick, FALLING);
}

int Encoder::getPosition()
{
    return encoder_ticks;
}

void Encoder::_tick()
{
	noInterrupts();
	encoder_A_set = digitalReadFast(PIN_A);
    encoder_B_set = digitalReadFast(PIN_B);

	/* Serial.print(encoder_A_set);
	Serial.print(",");
	Serial.println(encoder_B_set);
	*/
    //increment if A leads B
	if (encoder_A_set > encoder_B_set)
	{
		encoder_ticks += 1;
	}
	else if (encoder_A_set < encoder_B_set)
	{
		encoder_ticks -= 1;
	}
	else  // <-- temp
	{
		//do nothing
	}
    #ifdef ENCODER_REVERSED
        encoder_ticks -= (encoder_B_set) ? -1 : 1;
    #else
        encoder_ticks += (encoder_B_set) ? -1 : 1;
    #endif
	interrupts();
}
