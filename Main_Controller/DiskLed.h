// DiskLed.h

#ifndef _DISKLED_h
#define _DISKLED_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#else 
	#include "ArduinoStub.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"
class DiskLed : public Appliable
{
private:
	bool pinGreenLedValue = LOW;
	bool pinBlueLedValue = LOW;
	bool pinRedLedValue = LOW;

public:
	DiskLed(bool _pinRedLedValue, bool _pinGreenLedValue, bool _pinBlueLedValue);

	virtual void init();

	virtual void apply();

	const static DiskLed OFF;
	const static DiskLed RED;
	const static DiskLed GREEN;
	const static DiskLed BLUE;
};

#endif

