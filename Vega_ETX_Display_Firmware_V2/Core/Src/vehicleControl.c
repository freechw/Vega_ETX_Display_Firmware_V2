/*
 * vehicleControl.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Akila
 */
#include "vehicleControl.h"

//Check EVCU Confirmation on mode change
bool check_ack() {
	//Mode Change request
	if (mode_evcu == targetMode) {
		modeChangeOK = true;
	} else {
		modeChangeOK = false;
	}

	//Debug//
	//modeChangeOK = true;
	//////////////////

	return modeChangeOK;
}

//Read CAN
//Set Driving Mode of the EVCU
//Set targerMode to corresponding mode
//This will call on external interrupt
void evcuMode() {
	if (mode_override == false && mode == true) { //Mode Override
		if (currentMode == ecoMode) {
			//Set Normal Mode
			targetMode = normalMode;
			if (check_ack()) {
				currentMode = normalMode;
				mode = false;
				modeIcon = true;
				//_setPoup = true;
				popUpNumber = 1;

				_modeSelection = 1;
				rtn = false;
			}
		} else if (currentMode == normalMode) {
			//Set Sports Mode
			targetMode = sportMode;
			if (check_ack()) {
				currentMode = sportMode;
				modeIcon = true;
				//_setPoup = true;
				popUpNumber = 3;

				_modeSelection = 1;
				mode = false;
				rtn = false;
				modeChangeOK = false;
			}
		} else if (currentMode == sportMode) {
			//Set Eco Mode
			targetMode = ecoMode;
			if (check_ack()) {
				currentMode = ecoMode;
				mode = false;
				modeIcon = true;
				//_setPoup = true;
				popUpNumber = 2;

				_modeSelection = 1;
				rtn = false;
				modeChangeOK = false;
				currentMode = ecoMode;
			}
		}
	}
	//Turtle Mode: Show as Eco Mode but EVCU will set as turtle Mode. Limited Power
	//Power Limit Icon Should be appeared
	if (mode_override == true) {
		currentMode = ecoMode;
		targetMode = ecoMode;
		if (mode == true) {
			mode = false;
			_modeSelection = 1;
			modeIcon = true;
			rtn = false;
		}
	}
	//modeSelection -  set false in transmit function
	//_modeSelection = true;
}

void trip_reset(void){

	if(trip_ack == 1){
		tripreset = false;
		//resetThings();
	}
}
