/*
 * state_machine.h
 *
 *  Created on: Sep 27, 2022
 *      Author: Akila
 */

#ifndef INC_STATE_MACHINE_H_
#define INC_STATE_MACHINE_H_

#include "data_structures.h"
#include "vehicleControl.h"
#include "transmit.h"
#include "menu.h"


void mainStateMachine(void);

void startUpState(void);
void driveState(void);
void chargeState(void);
void errorState(void);



#endif /* INC_STATE_MACHINE_H_ */
