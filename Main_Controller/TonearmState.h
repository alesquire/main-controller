// TonearmState.h

#ifndef _TONEARMSTATE_h
#define _TONEARMSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"


enum TonearmDirection
{
	LEFT,
	RIGHT,
	IDLE,  //is returned when tonearm is not in PLAY mode and when it is nod moving
	ANTISCATE
};
/*
	Class applies voltage to solenoid according to mode. Two global modes defines - which input will drive solenoid voltage ( and force):
	1. Play mode- when tonearm is on disk. Antiscate voltage is applied
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
		if (_value > getZeroOutputValue())
			return TonearmDirection::RIGHT;
		if (_value < getZeroOutputValue())
			return TonearmDirection::LEFT;
		return TonearmDirection::IDLE;
	}

	static const int tonearmReferenceOutput = 2000; //todo- specify correct value

public:
	static void init();

	virtual void apply();
	
	virtual char* getTonearmStateName() 
	{
		return "Illegal state- parent class is used instead of child class";
	};

	virtual TonearmDirection getDirection()
	{
		int outputValue = defineValue();
		return getDirectionByOutputValue(outputValue);
	}

	/*
		method is used for initialization to define - is in necessary to move tonearm back to holder or not
	*/
	static bool isTonearmOnHolder();

	static TonearmState* const PLAY;			//tonearm is on plate, antiscate force is applied. joystick is ignored
	static TonearmState* const MOVE;			//tonearm can be moved to any side by joystick
	static TonearmState* const AUTOSTOP;		// tonearm is on autostop and can move only rightwards
	static TonearmState* const HOLDER;		// tonearm is on holder and can move only leftwards
	static TonearmState* const STOP;			//tonearm is steady in horyzontal plane			   
	static TonearmState* const FULL_RIGHT;	//automatic move right on full speed
	static TonearmState* const FULL_LEFT;	//automatic move left on full speed
};

class StopMode : public TonearmState
{
protected:
	virtual int defineValue();
	virtual TonearmDirection getDirection();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------
/*
Poickup is on disk- antiscate force is applied. joystick is ignored
*/
class Play : public TonearmState
{
protected:
	virtual int defineValue();
	virtual TonearmDirection getDirection();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------
/*
tonearm can be moved to any direction
*/
class Move : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class Autostop : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class Holder : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class FullLeft : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class FullRight : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};

#endif

