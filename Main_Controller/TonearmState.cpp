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
	return 0;
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
	pinMode(PIN_ANTISCATE, INPUT);
	pinMode(PIN_DAMPER, INPUT);

}

void TonearmState::apply()
{
	int outputValue = defineValue();
	analogWrite(PIN_TONEARM_VOLTAGE_OUTPUT, outputValue);
}


//-----------------------------------------------------------------------------------
class StopMode : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return getZeroOutputValue();
	}
};
const TonearmState TonearmState::STOP = StopMode();

//-----------------------------------------------------------------------------------

class Play : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return transformAntiscateToOutput(readNormalizedAntiscateValue());
	}
};
const TonearmState TonearmState::PLAY = Play();

//-----------------------------------------------------------------------------------

class Move : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return transformJoystickToOutput(readNormalizedJoystickValue());
	}
};
const TonearmState TonearmState::MOVE = Move();

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
const TonearmState TonearmState::AUTOSTOP = Autostop();

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
const TonearmState TonearmState::HOLDER = Holder();

//-----------------------------------------------------------------------------------

class FullLeft : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return returnFullLeftValue();
	}
};
const TonearmState TonearmState::FULL_LEFT = FullLeft();

//-----------------------------------------------------------------------------------

class FullRight : public TonearmState
{
protected:
	virtual int defineValue()
	{
		return returnFullRightValue();
	}
};
const TonearmState TonearmState::FULL_RIGHT = FullRight();
