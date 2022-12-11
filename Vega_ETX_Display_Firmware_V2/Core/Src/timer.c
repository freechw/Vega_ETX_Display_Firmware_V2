/*
 * timer.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Nisal Bulathsinghala
 */
#include "timer.h"

void tick_clear(volatile tick_tock *timer_ptr)
{
	timer_ptr->counter = 0;
	timer_ptr->timeout_50ms = 0;
	timer_ptr->timeout_0_5s = 0;
	timer_ptr->timeout_1s = 0;
	timer_ptr->timeout_2s = 0;
	timer_ptr->timeout_4s = 0;
	timer_ptr->timeout_6s = 0;
	timer_ptr->timeout_8s = 0;
	timer_ptr->timeout_10s = 0;
	timer_ptr->timeout_15s = 0;
	timer_ptr->timeout_30s = 0;
	timer_ptr->timeout_5m = 0;
}

void tick_count(volatile tick_tock *timer_ptr)
{
	timer_ptr->counter++;

	switch (timer_ptr->counter)
	{
		case 1:
			timer_ptr->timeout_50ms = true;
			break;
		case 10:
			timer_ptr->timeout_0_5s = true;
			break;
		case 20:
			timer_ptr->timeout_1s = true;
			break;
		case 40:
			timer_ptr->timeout_2s = true;
			break;
		case 80:
			timer_ptr->timeout_4s = true;
			break;
		case 120:
			timer_ptr->timeout_6s = true;
			break;
		case 160:
			timer_ptr->timeout_8s = true;
			break;
		case 200:
			timer_ptr->timeout_10s = true;
			break;
		case 300:
			timer_ptr->timeout_15s = true;
			break;
		case 600:
			timer_ptr->timeout_30s = true;
			break;
		case 6000:
			timer_ptr->timeout_5m = true;
			break;
		default:
			break;
	}
}

volatile tick_tock timeout;
volatile tick_tock serial_send;

