#ifndef RINGBUFF_H
#define RINGBUFF_H

#include "main.h"
#include <stdint.h>
#include "data_structures.h"


//================================================
// FUNCTION
//================================================

void DRV_RingBuffPtr__Clean(RING_BUFF_INFO *ptr);

void DRV_RingBuffPtr__Input(RING_BUFF_INFO *ptr, unsigned int iBufferSize);

void DRV_RingBuffPtr__Output(RING_BUFF_INFO *ptr, unsigned int iBufferSize);

void DRV_RingBuffPtr__Output_JumpToNew(RING_BUFF_INFO *ptr,
		unsigned int iBufferSize);

#endif // RINGBUFF_H
