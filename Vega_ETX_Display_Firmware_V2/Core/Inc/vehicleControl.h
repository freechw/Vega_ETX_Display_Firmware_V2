/*
 * vehicleControl.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Akila
 */

#ifndef INC_VEHICLECONTROL_H_
#define INC_VEHICLECONTROL_H_
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_structures.h"

//Mode Selection
extern void evcuMode(void);
extern bool check_ack(void);
extern void trip_reset(void);



#endif /* INC_VEHICLECONTROL_H_ */
