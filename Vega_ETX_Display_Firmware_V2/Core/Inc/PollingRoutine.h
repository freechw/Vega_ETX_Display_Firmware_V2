/*
 * PollingRoutine.h
 *
 *  Created on: Dec 17, 2022
 *      Author: codek
 */


#ifndef INC_POLLINGROUTINE_H_
#define INC_POLLINGROUTINE_H_

#include "RingBuff.h"
#include "data_structures.h"
void PollingInit(void);
void PollingRoutine(void);
void SomeTask(void);

void SaveToUART_TxBuffer(uint8_t *data, uint32_t dataSize);
void UART_SendMessage(void);

#endif /* INC_POLLINGROUTINE_H_ */
