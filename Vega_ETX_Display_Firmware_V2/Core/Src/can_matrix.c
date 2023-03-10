/*
 * can_matrix.c
 *
 *  Created on: Aug 12, 2022
 *      Author: DELL
 */
#include <can_matrix.h>

#define logSize 8

time_t t_of_day;

struct EVCU_setData EVCU_setData_i;

void EVCU_setData_write(uint8_t *canTX) {
	//timeStampSend();6
//	testFlag_1 = true;
	EVCU_setData_i.dataID = 0;
	EVCU_setData_i.fixSetS.bit.mode = targetMode;
	EVCU_setData_i.fixSetS.bit.trip_rst = tripreset;
	EVCU_setData_i.fixSetS.bit.currentMenu = currentMenu;
	//EVCU_setData_i.fixSetS.bit.espRequest = espDataRequest;
	canTX[0] = EVCU_setData_i.dataID;
	canTX[1] = EVCU_setData_i.fixSetS.all;
	//Time Stamp: Call time Stamp Here
//	canTX[2] = (t_of_day << 24);
//	canTX[3] = (t_of_day << 16);
//	canTX[4] = (t_of_day << 8);
//	canTX[5] = (t_of_day & 0xFF);0
	HAL_CAN_AddTxMessage(&hcan1, &txHeader, canTX, &canMailbox);
	//Reset Flags
	//tripreset = false;
}

//Call Through the interrupt
void EVCU_getData_read_40(uint8_t *canRX) {
	currentstate = ((canRX[1] & 0xFF) >> 4);
	accessory = ((canRX[1] & 0x08) >> 3);
	readytodrive = ((canRX[1] & 0x04) >> 2);
	start = ((canRX[1] & 0x02) >> 1);
	buzzer = (canRX[1] & 0x01);
	trip_ack = ((canRX[2] & 0x80) >> 7);
	mode_override = ((canRX[2] & 0x40) >> 6);
	mode_evcu = ((canRX[2] & 0x30) >> 4);
	chargerconn = ((canRX[2] & 0x08) >> 3);
	shutdown = ((canRX[2] & 0x04) >> 2);

	//ID 0
	power = ((canRX[4] << 8) | canRX[3]);
	test_speed = canRX[5];
	rpm_meter = ((canRX[7] << 8) | canRX[6]);
	if (starupMode) {
		starupMode = false;
		currentMode = mode_evcu;
	}


}

void EVCU_getData_read_41(uint8_t *canRX) {
	if (canRX[0] == 0) {
		err_error = (canRX[1] & 0x0F);
		err_device = ((canRX[1] & 0x30) >> 4);
		err_crit_mild = ((canRX[1] & 0x40) >> 6);
		err_or_not = ((canRX[1] & 0x80) >> 7);

		warning = ((canRX[2] & 0xC0) >> 6);

	}
	if (canRX[0] == 1) {
		//			chargingcomp = (canRX[4] & 0x1);
		distance.ODO = ((canRX[4] & 0xFF) | (canRX[3] << 8) | (canRX[2] << 16)
				| (canRX[1] << 24)); //ODO
		distance.range = 10 *canRX[5];
	}

	if (canRX[0] == 2) {

		soc_value = canRX[1];
		soh_value = canRX[2];
		pack_temp = canRX[3];
		lcell_voltage = ((canRX[5] & 0xFF) | (canRX[4] << 8));
		hcell_voltage = ((canRX[7] & 0xFF) | (canRX[6] << 8));
	}

	if (canRX[0] == 3) {
		pack_voltage = ((canRX[2] & 0xFF) | (canRX[1] << 8));
		dc_current = ((canRX[4] & 0xFF) | (canRX[3] << 8));

	}
	if (canRX[0] == 4) {
		distance.trip = ((canRX[2] & 0xFF) | (canRX[1] << 8)); //Trip
		distance.tripAvgSpeed = ((canRX[6] & 0xFF) | (canRX[5] << 8));

	}
	if (canRX[0] == 5) {
		afterChargeData.trip = ((canRX[2] & 0xFF) | (canRX[1] << 8));
		afterChargeData.avarage_Speed = ((canRX[4] & 0xFF) | (canRX[3] << 8));
		afterChargeData.economy = ((canRX[6] & 0xFF) | (canRX[5] << 8));
	}
	if (canRX[0] == 6) {
		distance.trip_Power = ((canRX[2] & 0xFF) | (canRX[1] << 8));
		;
		afterChargeData.power = ((canRX[4] & 0xFF) | (canRX[3] << 8));
		;

	}

}

void EVCU_getData_read_43(uint8_t *canRX) {
	if (canRX[0] == 0) {
		appData.speed = (canRX[1]);
		appData.RPM = ((canRX[3] & 0xFF) | (canRX[4] << 8));
		appData.DC_Current = ((canRX[5] & 0xFF) | (canRX[6] << 8));
		appData.MC_Current = ((canRX[7] & 0xFF) | (canRX[6] << 8));
	}
	if (canRX[0] == 1) {
		appData.SOC = (canRX[1]);
		appData.pack_Voltage = ((canRX[3] & 0xFF) | (canRX[2] << 8));
		appData.mcu_Temp = (canRX[4]);
		appData.motor_Temp = (canRX[5]);
		appData.pack_Temp = (canRX[6]);
		appData.mode = (canRX[7]);
	}
}
