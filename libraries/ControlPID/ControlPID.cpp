#include "ControlPID.h"

void ControlPID::setup() 
{
	enc.init();
	myPID.clear();
	myPID.configure(Kp,Ki,Kd,Hz,output_bits,output_signed);
	myPID.setOutputRange(driver.getEscMin(),driver.getEscMax());
	/*setpoint = getEncoderValue(); */
}
int ControlPID::loop()
{
	
	int feedback = enc.getPosition(); //Make it the encoder
	uint16_t before,after;
	before = micros();
	//if(feedback > 500 || feedback < -500)
	//	STOP();
	if((millis() - prevTime) >= 10000)
	{
		int16_t output = myPID.step(setpoint,feedback); 

		Serial.print("Feedback of PID: ");
		Serial.print(feedback);
		Serial.print(", Output of PID: ");
		Serial.println(output);
		
		prevTime = millis();
		return output;
	}
	
	
	//driver.move(output);
	
}

void ControlPID::setConfig(float kp, float ki, float kd, float hz)
{
	myPID.clear();
	myPID.setCoefficients(kp, ki, kd, hz);
	Kp = kp;
	Ki = ki;
	Kd = kd;
	Hz = hz;
}

void ControlPID::STOP(){
	driver.move(driver.getEscNeutral());
	while(true)
	{
		
	}
}