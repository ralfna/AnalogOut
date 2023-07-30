#include "AnalogOut.h"

/* Motor()
*/
AnalogOut::AnalogOut(uint8_t address)
{
	Wire.begin();
	_address=address;
    _channel=0;
    _voltage=0;
}

void AnalogOut::setChannel(byte c)
{
    _channel=c;
}
void AnalogOut::setVoltage(int i)
{
    _voltage=i;
}

byte AnalogOut::set()
{  
    byte hbyte = _voltage / 256;          //HIGH-Byte berechnen
    byte lbyte = _voltage - hbyte * 256;  //LOW-Byte berechnen
  
	// Start I2C Transmission
	Wire.beginTransmission(_address);
	// Send channel command
	Wire.write(_channel);
    // Send voltage low byte - high byte
	Wire.write(lbyte);
    Wire.write(hbyte);
	// Stop I2C transmission
	if (Wire.endTransmission()!=0) 
		return 1;  

	delay(20);
	
	if (Wire.available()!=0) 
		return 2;
	return 0;
}

byte AnalogOut::set(byte c,int i)
{  
    _channel = c;
    _voltage = i;
    byte hbyte = _voltage / 256;          //HIGH-Byte berechnen
    byte lbyte = _voltage - hbyte * 256;  //LOW-Byte berechnen
  
	// Start I2C Transmission
	Wire.beginTransmission(_address);
	// Send channel command
	Wire.write(_channel);
    // Send voltage low byte - high byte
	Wire.write(lbyte);
    Wire.write(hbyte);
	// Stop I2C transmission
	if (Wire.endTransmission()!=0) 
		return 1;  

	delay(20);
	
	if (Wire.available()!=0) 
		return 2;
	return 0;
}
