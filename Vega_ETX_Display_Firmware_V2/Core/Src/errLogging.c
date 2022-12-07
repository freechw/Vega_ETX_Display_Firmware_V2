/*
 * errLogging.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Akila
 */
#include "errLogging.h"
//Call When in the Error Log Page

void readErrorLog(void) {
	//Display Error Code and Time Stamp on the Error Log Page
	//Write errLog data into this page using display functions
	//HAL_UART_Transmit(&huart3, Errors, sizeof(Errors), HAL_MAX_DELAY);
}

void setError(void) {
	if (err_device == 0) { //General
		switch (err_error) {
		case 0: //CAN_Lost
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 1: //DCDC_Fault
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 2: //Aux_Bat_Low
			error_on = false;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = true;
			//error_exit = true;
			break;
		default:
			break;
		}
	}
	if (err_device == 1) { //BMS
		switch (err_error) {
		case 0: //Over_Discharge_Current
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 1: //Over_Charge_Current
			error_on = false;
			milderror_on = true;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 2: //Over_Charge_Current_Regen
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 3: //Pre_Charger_Error
			error_on = true;
			milderror_on = false;
			service_on = true;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 4: // Cell_Deviation
			error_on = false;
			milderror_on = true;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 5: //Lowest_Cell_Error
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = true;
			//error_exit = true;
			break;
		case 6: //Contactor_not_closing
			error_on = true;
			milderror_on = false;
			service_on = true;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 7: //Battery_Over_Temperature
			error_on = false;
			milderror_on = false;
			service_on = false;
			bat_temp_high = true;
			aux_low_on = false;
			//error_exit = true;
			break;
		case 8: //BMS_Internal_Communication_Error
			error_on = true;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			//error_exit = true;
			break;
		default:
			error_on = false;
			milderror_on = false;
			service_on = false;
			bat_temp_high = false;
			aux_low_on = false;
			break;
		}
	}
	//_errorSelection = true;
}

