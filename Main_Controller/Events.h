// Events.h

#ifndef _EVENTS_h
#define _EVENTS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

enum Events 
{
	StopButtonPress,
	RotateButtonPress,
	PlayButtonPress,
	UpJoystickPress,
	DownJoystickPress,
	TonearmLevelUp,
	TonearmLevelMiddle,
	TonearmLevelDown,
	TonearmPositionHolder,
	TonearmPositionOverGap,
	TonearmPositionOverFirstTrack,
	TonearmPositionOverDisk,
	TonearmPositionOnAutostop,
	Speed33ButtonPress,
	Speed45ButtonPress,
	AutostopTimerEvent
};

#endif

