/*
 * errLogging.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Akila
 */

#ifndef INC_ERRLOGGING_H_
#define INC_ERRLOGGING_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stm32f1xx_hal.h>
#include "data_structures.h"
#include "main.h"
#include "transmit.h"

extern void errorTimeStamp(void);
extern void readErrorLog(void);
extern void setError(void);


#endif /* INC_ERRLOGGING_H_ */
