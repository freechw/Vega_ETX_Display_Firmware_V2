/*
 * data_structures.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Akila
 */

#ifndef INC_DATA_STRUCTURES_H_
#define INC_DATA_STRUCTURES_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stm32f1xx_hal.h>
#include "can.h"
#include "gpio.h"
#include "usart.h"

//Button Flags
struct gpioStruct {
	union {
		uint8_t all;
		struct {
//			uint8_t button_hand_Break :1;
//			uint8_t button_door :1;
//			uint8_t button_reserve :1;
//			uint8_t button_nav_SW1 :1;
//			uint8_t button_nav_SW2 :1;
//			uint8_t button_nav_SW3 :1;
//			uint8_t button_nav_SW4 :1;
//			uint8_t button_nav_SW5 :1;
//			uint8_t button_turn_R :1;
//			uint8_t button_turn_L :1;
//			uint8_t button_high_Beam :1;
//			uint8_t button_park :1;
			uint8_t in1 :1;
			uint8_t in2 :1;
			uint8_t in3 :1;
			uint8_t in4 :1;
			uint8_t in5 :1;
			uint8_t in6 :1;
			uint8_t in7 :1;
			uint8_t in8 :1;
			uint8_t in9 :1;
			uint8_t in10 :1;
			uint8_t in11 :1;
			uint8_t in12 :1;
		} bit;
	} buttonInputs;
};

extern struct gpioStruct gpio;
//Button Flags
extern bool hand_Break;
extern bool door;
extern bool reserve;
extern bool nav_SW1;
extern bool nav_SW2;
extern bool nav_SW3;
extern bool nav_SW4;
extern bool nav_SW5;
extern bool turn_R;
extern bool turn_L;
extern bool high_Beam;
extern bool park;
extern bool buttonEn1;
extern bool buttonEn2;

//Main States
typedef enum {
	startingup_state = 0, driving_state, charging_state, Error_state
} uism_t;

//Basic UI's States
typedef enum {
	front = 0,
	trip,
	after_charge,
	info,
	infobat,
	infomot,
	infoinv,
	settings,
	vehicleMenu,
	systemMenu,
	bluetoothMenu,
	errorsMenu,
	noLitMenu,
	charging_ui,
	chargingcomp_ui,
	chargingerr_ui,
} uitype_t;

typedef enum{
	Disengage_Page = 0,
	MainMenuPages = 1
} uiTrasnmittype_t;

extern volatile uiTrasnmittype_t _trasmitGlobal;

//Mode States
typedef enum {
	normalMode = 0, turtleMode, ecoMode, sportMode, modeCleared
} uimode_t;

//typedef enum {
//	E1000, //CAN_Lost
//	E0100, //Over_Discharge_Current
//	E0101, //Over_Charge_Current
//	E1102, //Over_Charge_Current_Regen
//	E1106, //Contactor_not_closing
//	E1108, //BMS_Internal_Communication_Error
//	E1103, //Pre_Charger_Error
//	E1105, //Lowest_Cell_Error
//	E1001, //DC_DC_Fault
//	E0002  //12V_Battery_Low
//} errors_t;

//Page Flags
extern volatile uitype_t currentPage;
extern volatile uitype_t previousPage;

//Main State Machine Flag
extern volatile uism_t previousStateSM;
extern volatile uism_t currentStateSM;
extern bool _startingUp;
extern bool _realTimeData;
extern bool _oneTimeData;
extern bool _navigation;
extern bool _driverPageSet;
extern bool _modeSelection;
extern bool _allowNavigation;
extern bool _errorSetPopup;
extern bool _errorSetCode;
extern bool _errorSetIcon;
extern bool _L_Signal;
extern bool _R_Signal;
extern bool _highBeam;
extern bool _errorClear;
extern bool _charingState;
extern bool _chargingUI;
extern bool _chargeComplete;
extern uint8_t modePopup;
extern bool _modeChanged;
extern bool _gearCleared;
extern bool _gearChanged;
//Page Flags
extern bool _Disengage_KillSwitch_Page;
extern bool _Press_Brake_Page;
extern bool _Gear_Error_Page;
extern bool _System_Check_Okay_No_Icon_Page;
extern bool _System_Check_All_Icon_Page;
extern bool _After_Charge_Page;
extern bool _Vehicle_Settings_Page;
extern bool _Trip_Summary_Page;
extern bool _Vehicle_Info_Page;
extern bool _Battery_Info_Page;
extern bool _Motor_Info_Page;
extern bool _Inverter_Info_Page;
extern bool _Charging_Page;
extern bool _ChargeComplete_Page;
extern bool _Charge_Error_Page;
extern uint8_t _fireModeEnable;
extern bool _firePage;
extern volatile uitype_t _drivePageSet;
//extern uint8_t navigationCount;
//Menu Flags
extern volatile uitype_t currentMenu;
extern volatile uitype_t previousMenuBack;
extern volatile uitype_t previousMenuForward;
extern uint8_t _menupage;

extern bool menuAccess;
extern bool inVehicleMenu;
extern bool inSystemMenu;
extern bool inBluetoothMenu;
extern bool inErrorsMenu;

//Mode Flags
extern volatile uimode_t currentMode;
extern volatile uimode_t targetMode;

//Flags
extern bool espDataRequest;
extern bool state_entry;
extern bool page_entry;
extern bool error_entry;
extern bool forward;
extern bool backward;
extern bool okay;
extern bool tripreset;
extern bool longpress;
extern bool mode;
extern bool back;
extern bool modeChange;
extern bool inSettings;
extern bool inInfoBat;
extern bool err_State_Navigation;
extern bool rtn;

//CAN
extern uint8_t canRX[8];
extern uint8_t canTX[8];
extern uint32_t canMailbox;
extern CAN_TxHeaderTypeDef txHeader;

struct distanceCAN {
	uint32_t ODO;
	uint16_t trip;
	uint8_t range;
	uint16_t tripAvgSpeed;
	uint16_t trip_Economy;
	uint16_t trip_Power;
};
extern struct distanceCAN distance;

struct afterChargeCAN {
	uint16_t trip;
	uint16_t avarage_Speed;
	uint16_t economy;
	uint16_t power;
};

extern struct afterChargeCAN afterChargeData;

struct appDataCAN {
	uint8_t speed;
	uint16_t RPM;
	uint16_t DC_Current;
	uint16_t MC_Current;
	uint8_t SOC;
	uint16_t pack_Voltage;
	uint8_t mcu_Temp;
	uint8_t motor_Temp;
	uint8_t pack_Temp;
	uint8_t mode;
};

extern struct appDataCAN appData;

//UART
extern uint8_t serialDATA[12];
extern uint8_t strDATA[8];
extern uint8_t strDATA2[10];

//Counter
extern uint8_t counter;
extern uint8_t counter2;

extern uint16_t test_speed;

extern uint16_t mode_count;
extern uint8_t soc_value;
extern uint8_t soh_value;
extern uint16_t pack_voltage;
extern uint16_t hcell_voltage;
extern uint16_t lcell_voltage;
extern uint16_t rpm_meter;
extern uint8_t pack_temp;
extern int16_t dc_current;
extern int16_t power;
extern uint16_t timer_val;
extern uint32_t timerCounter;
extern uint8_t currentstate;
extern uint8_t previousState;
extern uint8_t accessory;
extern uint8_t readytodrive;
extern uint8_t start;
extern uint8_t buzzer;
extern uint8_t trip_ack;
extern uint8_t mode_override;
extern uint8_t mode_evcu;
extern uint8_t warning;
extern uint8_t chargerconn;
extern uint8_t shutdown;
extern uint8_t chargingcomp;

//Error Handling//
extern uint8_t err_error;
extern uint8_t err_device;
extern uint8_t err_crit_mild;
extern uint8_t err_or_not;
extern uint32_t err_fullerror;
extern uint32_t err_previous;

//Error Flags
extern bool error_on;
extern bool milderror_on;
extern bool service_on;
extern bool bat_temp_high;
extern bool bat_crit_low;
extern bool aux_low_on;
extern bool error_exit;

//struct gpioStruct {
//	union {
//		uint8_t all;
//		struct {
//			uint8_t buttonUp :1;
//			uint8_t buttonDown :1;
//			uint8_t buttonOkay :1;
//			uint8_t buttonMode :1;
//			uint8_t buttonBack :1;
//		} bit;
//	} buttonInputs;
//};
//
//extern struct gpioStruct gpio;

extern uint32_t transferCount;
extern uint8_t pageCounter;
extern uint16_t CounterTicks;
extern int battery_count;
extern bool bat_data_received;
extern bool startup;
extern bool entry;
extern bool begin;
extern bool checklit;

//Error Log Array
extern uint8_t errLog[10][8];
extern uint32_t byteIndex;
extern uint8_t errorRead;
extern uint32_t unixTime;
extern bool error_check;

//Mode Change
extern bool modeChangeOK;
extern bool modeMenu;
extern bool mode_err;
//extern volatile uimode_t previousMode;
//Charing Errors
extern bool charge_error;

//Control Variables
extern uint8_t longPress_Time;

//Debugging Flag//
extern bool testFlag_1;
extern bool testFlag_2;
extern bool testFlag_3;

//FireMode
struct fireMode {
	union {
		uint8_t flagAll;
		struct {
			uint8_t emergency_Status_Flag :1;
			uint8_t CAN_motorController_Flag :1;
			uint8_t CAN_BMS_Flag :1;
			uint8_t CAN_OBC_Flag :1;
			uint8_t IGN_In_Flag :1;
			uint8_t OBC_In_Flag :1;
			uint8_t L2_In_Flag :1;
			uint8_t ChargeComplete_Flag :1;
		} fireFlag_bits;
	} fireFlag;
	union {
		uint8_t outputAll;
		struct {
			uint8_t Gear_D_Output;
			uint8_t Gear_N_Output;
			uint8_t Gear_R_Output;
			uint8_t reGen_Output;
		} fireOutputs_bits;
	} fireOutputs;
	union {
		uint8_t inputAll;
		struct {
			uint8_t drive_Input;
			uint8_t reverse_Input;
			uint8_t brake_Input;
			uint8_t killSw_Input;
			uint8_t start_Input;
		} fireInputs_bits;
	} fireInputs;
	union {
		uint8_t relayAll;
		struct {
			uint8_t mcPower_Relay;
			uint8_t bms__Relay;
			uint8_t emergency_Relay;
			uint8_t ign_Relay;
		} fireRelays_bits;
	} fireRelays;
};

extern struct fireMode fire;

#endif /* INC_DATA_STRUCTURES_H_ */
