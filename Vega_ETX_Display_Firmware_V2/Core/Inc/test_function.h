/*
 * test_function.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Akila
 */

#ifndef INC_TEST_FUNCTION_H_
#define INC_TEST_FUNCTION_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include"data_structures.h"
#include "gpio.h"


extern void buttonTest(void);
extern void canTest(void);
extern void uartTest(void);

extern uint8_t message;
#endif /* INC_TEST_FUNCTION_H_ */
