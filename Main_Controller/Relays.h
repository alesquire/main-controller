// Relays.h

#ifndef _RELAYS_h
#define _RELAYS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"

class Relays : public Appliable
{
private:
	bool pinPickupRelayValue = LOW;
	bool pinDamperRelayValue = LOW;

public:
	Relays(bool _pinPickupRelayValue, bool _pinDamperRelayValue);

	static void init();

	virtual void apply();

	static Relays* const PLAY;
	static Relays* const MOVE;
};

#endif

