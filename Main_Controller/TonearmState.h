// TonearmState.h

#ifndef _TONEARMSTATE_h
#define _TONEARMSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"

/*
	Class applies voltage to solenoid according to mode. Two global modes defines - which input will drive solenoid voltage ( and force):
	1. Play mode- when tohearm is on disk. Antiscate voltage is applied
	2. Move mode- voltage is driven by joystick
*/

class TonearmState : public Appliable
{
protected:

	int transformAntiscateToOutput(int input);

	int transformJoystickToOutput(int input);

	/*
	returns antiscate value read from input pin normalized value - in range -X/2..0..+X/2
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
	*/
	int readNormalizedAntiscateValue();


	/*
	returns jostick value read from input pin normalized value - in range -X/2..0..+X/2
	value < 0 coresponde to move left, >0 - to move right
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
	*/
	int readNormalizedJoystickValue();

	/*
	return voltage value theat corresponds to steady tonarm state
	*/
	int getZeroOutputValue();

	/*
	returns value to be applied to tonearm during automatic move left
	*/
	int returnFullLeftValue();

	/*
	returns value to be applied to tonearm during automatic move right
	*/
	int returnFullRightValue();

	/*
	to be defined in subclasses the correspond particular tonearm states
	*/
	virtual int defineValue() {};

public:
	virtual void init();

	virtual void apply();

	const static TonearmState PLAY;			//tonearm is on plate, antiscate force is applied. joystick is ignored
	const static TonearmState MOVE;			//tonearm can be moved to any side by joystick
	const static TonearmState AUTOSTOP;		// tonearm is on autostop and can move only rightwards
	const static TonearmState HOLDER;		// tonearm is on holder and can move only leftwards
	const static TonearmState STOP;			//tonearm is steady in horyzontal plane			   
	const static TonearmState FULL_RIGHT;	//automatic move right on full speed
	const static TonearmState FULL_LEFT;	//automatic move left on full speed
};
#endif

