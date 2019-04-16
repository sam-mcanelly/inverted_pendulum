#ifndef ControlPID_H
#define ControlPID_H

#include <FastPID.h>
#include <Drive.h>
#include <Encoder.h>


class ControlPID {
    
public:

    ControlPID() { };
    
    ~ControlPID() { };
    
    void setup();
	int loop();
	void setConfig(float kp, float ki, float kd, float hz);
    void STOP();
private:
	float Kp = 0.3, Ki = 0.5,Kd = 0.5, Hz = 100;
	int output_bits = 8, setpoint = 0;
	int prevTime = 0;
	bool output_signed = true;
	
	FastPID myPID;
	Drive driver;
	Encoder enc;    
};

#endif
