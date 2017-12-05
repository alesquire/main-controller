// 
// 
// 

#include "TonearmState.h"

int TonearmState::transformAntiscateToOutput(int input)
{
	//todo: implement transformation table
	return input;
}

int TonearmState::transformJoystickToOutput(int input)
{
	//todo: implement transformation table
	return input;
}

/*
	returns antiscate value read from input pin normalized value - in range -X/2..0..+X/2
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
*/
int TonearmState::readNormalizedAntiscateValue()
{
	return analogRead(PIN_ANTISCATE);
}


/*
	returns jostick value read from input pin normalized value - in range -X/2..0..+X/2
	value < 0 coresponde to move left, >0 - to move right
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
*/
int TonearmState::readNormalizedJoystickValue()
{
	return analogRead(PIN_JOYSTICK_LEFT_RIGHT);
}

/*
	return voltage value theat corresponds to steady tonarm state
*/
int TonearmState::getZeroOutputValue()
{
	return ANALOG_RESOLUTION/2;
}

/*
	returns value to be applied to tonearm during automatic move left
*/
int TonearmState::returnFullLeftValue()
{
	return 0;
}

/*
	returns value to be applied to tonearm during automatic move right
*/
int TonearmState::returnFullRightValue()
{
	return ANALOG_RESOLUTION-1;
}

void TonearmState::init()
{
	pinMode(PIN_TONEARM_VOLTAGE_OUTPUT, OUTPUT);
	pinMode(PIN_TONEARM_REFERENCE_OUTPUT, OUTPUT);
	pinMode(PIN_ANTISCATE, INPUT);
	pinMode(PIN_DAMPER, INPUT);
	pinMode(PIN_JOYSTICK_LEFT_RIGHT, INPUT);
	pinMode(PIN_JOYSTICK_UP_DOWN, INPUT);
	pinMode(PIN_TONEARM_HOLDER, INPUT);
	pinMode(PIN_FIRST_TRACK, INPUT);
	pinMode(PIN_AUTOSTOP, INPUT);

	analogWrite(PIN_TONEARM_REFERENCE_OUTPUT,tonearmReferenceOutput);
}

void TonearmState::apply()
{
	int outputValue = defineValue();
	analogWrite(PIN_TONEARM_VOLTAGE_OUTPUT, outputValue);
}


//-----------------------------------------------------------------------------------
/*
	Tonearm is not moving despite on joystick state
*/

class StopMode : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return getZeroOutputValue();
	}
	virtual TonearmDirection getDirection()
	{
		return IDLE;
	}
};
TonearmState* const TonearmState::STOP = new StopMode();

//-----------------------------------------------------------------------------------
/*
	Poickup is on disk- antiscate force is applied. joystick is ignored
*/
class Play : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return transformAntiscateToOutput(readNormalizedAntiscateValue());
	}

	virtual TonearmDirection getDirection()
	{
		return ANTISCATE;
	}

};
TonearmState* const TonearmState::PLAY = new Play();

//-----------------------------------------------------------------------------------
/*
	tonearm can be moved to any direction
*/
class Move : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return transformJoystickToOutput(readNormalizedJoystickValue());
	}

};
TonearmState* const TonearmState::MOVE = new Move();

//-----------------------------------------------------------------------------------

class Autostop : public TonearmState
{
protected:
	virtual int defineValue()
	{
		int value = readNormalizedJoystickValue();
		if (value < 0) // try to move left
			return getZeroOutputValue();
		else
			return transformJoystickToOutput(value);
	}

};
TonearmState* const TonearmState::AUTOSTOP = new Autostop();

//-----------------------------------------------------------------------------------

class Holder : public TonearmState
{
protected:
	virtual int defineValue()
	{
		int value = readNormalizedJoystickValue();
		if (value > 0)  // try to move right
			return getZeroOutputValue();
		else
			return transformJoystickToOutput(value);
	}
};
TonearmState* const TonearmState::HOLDER = new Holder();

//-----------------------------------------------------------------------------------

class FullLeft : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return returnFullLeftValue();
	}
};
TonearmState* const TonearmState::FULL_LEFT = new FullLeft();

//-----------------------------------------------------------------------------------

class FullRight : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return returnFullRightValue();
	}
};
TonearmState* const TonearmState::FULL_RIGHT = new FullRight();
