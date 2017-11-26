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
	pinMode(PIN_RED_DISK_LED, OUTPUT);
	pinMode(PIN_GREEN_DISK_LED, OUTPUT);
	pinMode(PIN_BLUE_DISK_LED, OUTPUT);
}
	
void DiskLed::apply()
{
	digitalWrite(PIN_RED_DISK_LED, pinRedLedValue);
	digitalWrite(PIN_GREEN_DISK_LED, pinGreenLedValue);
	digitalWrite(PIN_BLUE_DISK_LED, pinBlueLedValue);
}

const DiskLed DiskLed::OFF = DiskLed(LOW, LOW, LOW);
const DiskLed DiskLed::RED = DiskLed(HIGH, LOW, LOW);
const DiskLed DiskLed::GREEN = DiskLed(LOW, HIGH, LOW);
const DiskLed DiskLed::BLUE = DiskLed(LOW, LOW, HIGH);

