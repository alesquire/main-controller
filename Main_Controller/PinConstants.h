#pragma once

#ifndef _PINCONSTANTS_H_
#define _PINCONSTANTS_H_

// global definitions
#define ANALOG_RESOLUTION 4096

//outputs
#define PIN_33_RPM A6// output to motor controller
#define PIN_45_RPM A7// output to motor controller

#define PIN_MICROLIFT_HOLD_OUTPUT 2//
#define PIN_MICROLIFT_UP_OUTPUT 3// todo- in schematics this pin is named DOWN

#define PIN_PLAY_LED 6//
#define PIN_ROTATE_LED 5//
#define PIN_STOP_LED 4//

#define PIN_33_LED 7//
#define PIN_45_LED 8//

#define PIN_RED_DISK_LED 10//
#define PIN_GREEN_DISK_LED 12//
#define PIN_BLUE_DISK_LED 11//

#define PIN_PICKUP_RELAY A3// relay that is put in parallel with pickup and shortens output when turntable is not in play mode
#define PIN_DAMPER_RELAY A4// relay that shortens damper resistor in move mode

#define PIN_TONEARM_REFERENCE_OUTPUT DAC0//
#define PIN_TONEARM_VOLTAGE_OUTPUT DAC1//

#define PIN_STROBOSCOPE A2//analog input is used as digital output
#define PIN_BOTTOM_CHASSIS_LIGHT A5//analog input is used as digital output
#define PIN_UPPER_CHASSIS_LIGHT 9//

//inputs
#define PIN_ANTISCATE A1 //Analog input- antiscate force from variable resistor
#define PIN_DAMPER A0 //Analog input- tonearm damping factor variable resistor

#define PIN_JOYSTICK_UP_DOWN A10//
#define PIN_JOYSTICK_LEFT_RIGHT A11//

#define PIN_PLAY_BUTTON 36//
#define PIN_ROTATE_BUTTON 34//
#define PIN_STOP_BUTTON 18//

#define PIN_33_BUTTON 16//
#define PIN_45_BUTTON 17//

#define PIN_MICROLIFT_UPPER_SENSOR 14//
#define PIN_MICROLIFT_LOWER_SENSOR 15//

#define PIN_TONEARM_HOLDER 32//
#define PIN_FIRST_TRACK 30//
#define PIN_AUTOSTOP 28//

#endif
