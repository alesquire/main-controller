// 
// 
// 

#include "DiskLed.h"
DiskLed::DiskLed(bool _pinRedLedValue, bool _pinGreenLedValue, bool _pinBlueLedValue)
{
	pinRedLedValue = _pinRedLedValue;
	pinGreenLedValue = _pinGreenLedValue;
	pinBlueLedValue = _pinBlueLedValue;
}

void DiskLed::init()
{
	initOutput(PIN_RED_DISK_LED);
	initOutput(PIN_GREEN_DISK_LED);
	initOutput(PIN_BLUE_DISK_LED);
}
	
void DiskLed::apply()
{
	digitalWrite(PIN_RED_DISK_LED, pinRedLedValue);
	digitalWrite(PIN_GREEN_DISK_LED, pinGreenLedValue);
	digitalWrite(PIN_BLUE_DISK_LED, pinBlueLedValue);
}

DiskLed* const DiskLed::OFF = new DiskLed(LOW, LOW, LOW);
DiskLed* const DiskLed::RED = new DiskLed(HIGH, LOW, LOW);
DiskLed* const DiskLed::GREEN = new DiskLed(LOW, HIGH, LOW);
DiskLed* const DiskLed::BLUE = new DiskLed(LOW, LOW, HIGH);

