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
	virtual int defineValue() { return 0; };

public:
	virtual void init();

	virtual void apply();

	static TonearmState* const PLAY;			//tonearm is on plate, antiscate force is applied. joystick is ignored
	static TonearmState* const MOVE;			//tonearm can be moved to any side by joystick
	static TonearmState* const AUTOSTOP;		// tonearm is on autostop and can move only rightwards
	static TonearmState* const HOLDER;		// tonearm is on holder and can move only leftwards
	static TonearmState* const STOP;			//tonearm is steady in horyzontal plane			   
	static TonearmState* const FULL_RIGHT;	//automatic move right on full speed
	static TonearmState* const FULL_LEFT;	//automatic move left on full speed
};
#endif

