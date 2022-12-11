/*
 * timer.h
 *
 *  Created on: Feb 20, 2020
 *      Author: Nisal
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"

//typedef enum { false, true } bool;

typedef struct tick_tock_struct
{
	uint32_t counter;
	bool timeout_50ms;
	bool timeout_0_5s;
	bool timeout_1s;
	bool timeout_2s;
	bool timeout_4s;
	bool timeout_6s;
	bool timeout_8s;
	bool timeout_10s;
	bool timeout_15s;
	bool timeout_30s;
	bool timeout_5m;
} tick_tock;

void tick_clear(volatile tick_tock *timer_ptr);
void tick_count(volatile tick_tock *timer_ptr);

extern volatile tick_tock timeout;
extern volatile tick_tock serial_send;

#endif /* TIMER_H_ */
