#pragma once
#ifndef _APPLIABLE_H
#define _APPLIABLE_H

/*
	Basic class for all turntable state. Class has implementation for each state. 
	To change turntable state (i.e. set another values to output pins) - controller changes class instance and calls apply method to update output pins
*/

class Appliable
{

public:
	/*
		function updates output pin values and also can perform device-specific logic (especially for solenoid control)
	*/
	virtual void apply() =0;

	/*
		function is called to initialise class and pins on turntable start	
	*/
	virtual void init() =0;

};

#endif