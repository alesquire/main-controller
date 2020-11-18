#include "PinConstants.h"

char pinNameResult[30] = { '0' };//is defined globally to be passed between contexts


char* getPinNameByNumber(int pinNumber)
{
	switch (pinNumber)
	{
		case 2:  return "PIN_MICROLIFT_HOLD_OUTPUT"; break;
		case 3:  return "PIN_MICROLIFT_UP_OUTPUT"; break;
		case 6:  return "PIN_PLAY_LED"; break;
		case 5:  return "PIN_ROTATE_LED"; break;
		case 4:  return "PIN_STOP_LED"; break;
		case 7:  return "PIN_33_LED"; break;
		case 8:  return "PIN_45_LED"; break;
		case 9:  return "PIN_UPPER_CHASSIS_LIGHT"; break;
		case 10:  return "PIN_RED_DISK_LED"; break;
		case 12:  return "PIN_GREEN_DISK_LED"; break;
		case 11:  return "PIN_BLUE_DISK_LED"; break;
		case 14:  return "PIN_MICROLIFT_UPPER_SENSOR"; break;
		case 15:  return "PIN_MICROLIFT_LOWER_SENSOR"; break;
		case 16:  return "PIN_33_BUTTON"; break;
		case 17:  return "PIN_45_BUTTON"; break;
		case 18:  return "PIN_STOP_BUTTON"; break;
		case 28:  return "PIN_AUTOSTOP"; break;
		case 30:  return "PIN_FIRST_TRACK"; break;
		case 32:  return "PIN_TONEARM_HOLDER"; break;
		case 34:  return "PIN_ROTATE_BUTTON"; break;
		case 36:  return "PIN_PLAY_BUTTON"; break;
		case A0:  return "PIN_DAMPER"; break;
		case A1:  return "PIN_ANTISCATE"; break;
		case A2:  return "PIN_STROBOSCOPE"; break;
		case A3:  return "PIN_PICKUP_RELAY"; break;
		case A4:  return "PIN_DAMPER_RELAY"; break;
		case A5:  return "PIN_BOTTOM_CHASSIS_LIGHT"; break;
		case A6:  return "PIN_33_RPM"; break;
		case A7:  return "PIN_45_RPM"; break;
		case A10:  return "PIN_JOYSTICK_UP_DOWN"; break;
		case A11:  return "PIN_JOYSTICK_LEFT_RIGHT"; break;
		case DAC0:  return "PIN_TONEARM_REFERENCE_OUTPUT"; break;
		case DAC1:  return "PIN_TONEARM_VOLTAGE_OUTPUT"; break;

		default:
		{
			std::sprintf(pinNameResult, "nuknown number %d", pinNumber);
			return pinNameResult;
		}

	}

}
