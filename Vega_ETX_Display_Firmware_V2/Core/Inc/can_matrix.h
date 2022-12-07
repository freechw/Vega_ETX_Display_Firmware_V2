/*
 * can_matrix.h
 *
 *  Created on: Aug 12, 2022
 *      Author: DELL
 */

#ifndef INC_CAN_MATRIX_H_
#define INC_CAN_MATRIX_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <data_structures.h>

extern void EVCU_setData_write(uint8_t *canTX);
extern void EVCU_getData_read(uint8_t *canRX);
void EVCU_getData_read_40(uint8_t *canRX);
void EVCU_getData_read_41(uint8_t *canRX);
void EVCU_getData_read_43(uint8_t *canRX);

void timeStampSend(void);
void timeStampReceive(void);
void errorComplication(void);

struct EVCU_fixSetS_struct {
	uint8_t mode :2; //Mode Selection
	uint8_t trip_rst :1;
	uint8_t currentMenu :3; // 8-Bits
	uint8_t espRequest :1; //Time
	uint8_t reserved3 :1; //Time
//Time
	//uint8_t reserved6 :1;

};

union EVCU_fixSetS_union {
	uint8_t all;
	struct EVCU_fixSetS_struct bit;
};

struct EVCU_fixSetG_struct {
	uint8_t currentState :4;
	uint8_t accessoryMode :1;
	uint8_t readyToDrive :1;
	uint8_t start :1;
	uint8_t buzzer :1;
	uint8_t trip_ack :1;
	uint8_t mode_override :1;
	uint8_t mode_evcu :2;
	uint8_t reserved3 :1;
	uint8_t reserved4 :1;
	uint8_t reserved5 :1;
	uint8_t reserved6 :1;

};

union EVCU_fixSetG_union {
	uint16_t all;
	struct EVCU_fixSetG_struct bit;
};

struct EVCU_setData {
	uint16_t dataID;
	union EVCU_fixSetS_union fixSetS;
	uint32_t timeStamp;
};

struct EVCU_getData {
	uint16_t dataID;
	union EVCU_fixSetG_union fixSetG;
};

#endif /* INC_CAN_MATRIX_H_ */
