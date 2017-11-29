// 
// 
// 

#include "Relays.h"

Relays::Relays(bool _pinPickupRelayValue, bool _pinDamperRelayValue)
{
	pinPickupRelayValue = _pinPickupRelayValue;
	pinDamperRelayValue = _pinDamperRelayValue; 
}

void Relays::init()
{
	pinMode(PIN_PICKUP_RELAY, OUTPUT);
	pinMode(PIN_DAMPER_RELAY, OUTPUT);
}

void Relays::apply()
{
	digitalWrite(PIN_PICKUP_RELAY, pinPickupRelayValue);
	digitalWrite(PIN_DAMPER_RELAY, pinDamperRelayValue);
}

Relays* const Relays::PLAY = new Relays(LOW, LOW);
Relays* const Relays::MOVE = new Relays(HIGH, HIGH);

