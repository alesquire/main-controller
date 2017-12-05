// TonearmState.h

#ifndef _TONEARMSTATE_h
#define _TONEARMSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"

/*
	Tonearm direction is controlled by operational amplifier, both inputs of amplifier are supplied by arduino DAC0 and DAC1.

	DAC0 controls reference value applied to non-inverting input and is a constant.
	DAC1 is connected to inverting op-amp input (trough resistors- see scheme) and controls output voltage and tus - tonearm direction. 

	Output voltage is controlled by several input signals that can be grouped in two groups depending on two basic tonearm work modes:

	Play mode. 
	In this mode - pickup is on disk and playing the record. Antiscate force is applied. Force is defined by two manual controls, provided as input 
	voltages read from potentiometers:
		- antiscate level. Is read from input PIN_ANTISCATE
		- damper level. Is read from inpu pin PIN_DAMPER
	Damper is a resistance put in series to output solenoid to control reaction from move sensor voltage applied to solenoid. When resistance is increased- to keep
	constant output voltage (and this - antiscate force)- we should increase DAC1 output voltage
	
	Class applies voltage to solenoid according to mode. Two global modes defines - which input will drive solenoid voltage ( and force):
	1. Play mode- when tonearm is on disk. Antiscate voltage is applied
	2. Move mode- voltage is driven by joystick

*/

enum TonearmDirection
{
	LEFT,
	RIGHT,
	IDLE,  //is returned when tonearm is not in PLAY mode and when it is nod moving
	ANTISCATE
};

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
		return voltage value theat corresponds to steady tonearm state
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

	TonearmDirection getDirectionByOutputValue(int _value)
	{
		if (_value < getZeroOutputValue())
			return TonearmDirection::RIGHT;
		if (_value > getZeroOutputValue())
			return TonearmDirection::LEFT;
		return TonearmDirection::IDLE;
	}

	static const int tonearmReferenceOutput = 2000; //todo- specify correct value

public:
	static void init();

	virtual void apply();
	
	virtual TonearmDirection getDirection()
	{
		int outputValue = defineValue();
		return getDirectionByOutputValue(outputValue);
	}

	static TonearmState* const PLAY;			//tonearm is on plate, antiscate force is applied. joystick is ignored
	static TonearmState* const MOVE;			//tonearm can be moved to any side by joystick
	static TonearmState* const AUTOSTOP;		// tonearm is on autostop and can move only rightwards
	static TonearmState* const HOLDER;		// tonearm is on holder and can move only leftwards
	static TonearmState* const STOP;			//tonearm is steady in horyzontal plane			   
	static TonearmState* const FULL_RIGHT;	//automatic move right on full speed
	static TonearmState* const FULL_LEFT;	//automatic move left on full speed
};
#endif

