#ifndef __ANALOGOUT_H
#define __ANALOGOUT_H



#include <Arduino.h>
#include <Wire.h>

class AnalogOut{
public:
	AnalogOut(uint8_t address=0xB0);
	void setChannel(byte);
    void setVoltage(int);
    byte set();
    byte set(byte,int);
    
private:
	uint8_t _address;
    byte _channel;
    int _voltage;
    
};


#endif