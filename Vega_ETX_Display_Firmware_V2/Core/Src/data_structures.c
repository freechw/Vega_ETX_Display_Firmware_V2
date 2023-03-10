/*
 * data_structures.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Akila
 */
#include"data_structures.h"
//Button Flags

struct gpioStruct gpio;

//Buttons
bool hand_Break = false;
bool door = false;
bool reserve = false;
bool nav_SW1 = false;
bool nav_SW2 = false;
bool nav_SW3 = false;
bool nav_SW4 = false;
bool nav_SW5 = false;
bool turn_R = false;
bool turn_L = false;
bool high_Beam = false;
bool park = false;
bool buttonEn1 = false;
bool buttonEn2 = false;
bool forward = false;
bool backward = false;
bool okay = false;
bool tripreset = false;
bool longpress = false;
bool mode = false;

//Flags
bool back = false;
bool modeChange = false;
bool inSettings = false;
bool inInfoBat = false;

uint8_t serialDATA[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t strDATA[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t strDATA2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

struct distanceCAN distance;
struct afterChargeCAN afterChargeData;
struct appDataCAN appData;

struct gpioStruct gpio;

uint16_t test_speed = 0;

//Flags
uint16_t mode_count = 0;
uint8_t soc_value = 0;
uint8_t soh_value = 0;
uint16_t pack_voltage = 0;
uint16_t hcell_voltage = 0;
uint16_t lcell_voltage = 0;
uint16_t rpm_meter = 0;
uint8_t pack_temp = 0;
int16_t dc_current = 0;
int16_t power = 0;
uint16_t timer_val;
uint32_t timerCounter = 0;
uint8_t currentstate = 0;
uint8_t previousState = 0;
uint8_t accessory = 0;
uint8_t readytodrive = 0;
uint8_t start = 0;
uint8_t buzzer = 0;
uint8_t trip_ack = 0;
uint8_t mode_override = 0;
uint8_t mode_evcu = 0;
uint8_t warning = 0;
uint8_t shutdown = 0;

//Error Flags
uint8_t err_error = 0;
uint8_t err_device = 0;
uint8_t err_crit_mild = 0;
uint8_t err_or_not = 1;
uint32_t err_fullerror = 1;
uint32_t err_previous = 0;
bool err_State_Navigation = false;
bool rtn = false;

uint32_t transferCount = 1;
uint8_t pageCounter = 1;
uint16_t CounterTicks = 0;
int battery_count = 1;
bool bat_data_received = false;

bool startup = true;
bool entry = true;
bool begin = true;
bool checklit = true;

//UI States
volatile uitype_t currentPage = front;
volatile uitype_t previousPage = front;
//State Machine States
volatile uism_t currentStateSM = startingup_state;
volatile uism_t previousStateSM = startingup_state;
//Menu States
volatile uitype_t currentMenu = vehicleMenu;
volatile uint8_t currentSubMenu = 0;

volatile uitype_t previousMenuBack = vehicleMenu;
volatile uitype_t previousMenuForward = vehicleMenu;

volatile uint8_t previousSubMenuBack = 0;
volatile uint8_t previousSubMenuForward = 0;

uint8_t _menupage = 0;
//Inital Mode
volatile uimode_t currentMode = normalMode;
volatile uimode_t targetMode = normalMode;
bool starupMode = true;

//Entry Flags
bool state_entry = true;
bool page_entry = true;
bool error_entry = false;

//Menu Flags
bool menuAccess = false;
bool inVehicleMenu = false;
bool inSystemMenu = false;
bool inTimeSettings = false;
uint8_t vpCounter = 3;
uint8_t timerSetValueH = 0;
uint8_t timerSetValueMin = 0;
bool timeChanged = false;
bool inBluetoothMenu = false;
bool inErrorsMenu = false;
bool inTheMenu = false;

//Error Flags
bool error_on = false;
bool milderror_on = false;
bool service_on = false;
bool bat_temp_high = false;
bool bat_crit_low = false;
bool aux_low_on = false;
bool error_exit = false;

//CAN Error Data 5 bytes -> 4 bytes: UNIX TIme Stamp; 1 byte: Error Code
uint8_t errLog[10][8];
uint32_t byteIndex = 0;
uint8_t errorRead = 0;
uint32_t unixTime = 0;

bool error_check = 0;

//Mode Change
bool modeChangeOK = false;
bool modeIcon = 0;
bool mode_err = false;

//Charging Error
bool charge_error = false;
uint8_t chargingcomp = 0;
uint8_t chargerconn = 0;

//Debugging Flag//
bool testFlag_1 = false;
bool testFlag_2 = false;
bool testFlag_3 = false;

//Vehicle interface Control Variables
uint8_t longPress_Time = 30;

//Transmit Control Flags
bool _startingUp = false;
bool _navigation = false;
bool _realTimeData = false;
bool _setDriverPage = false;
bool _oneTimeData = false;
uint8_t _modeSelection = 0;
bool _modeChangeDisabled = false;
bool _allowNavigation = false;
bool _errorSetPopup = false;
bool _errorSetCode = false;
bool _errorSetIcon = false;
bool _L_Signal = false;
bool _R_Signal = false;
bool _highBeam = false;
bool _errorClear = false;
bool _charingState = false;
bool _chargingUI = false;
bool _chargeComplete = false;
uint8_t modePopup = 0;


bool _modeChanged = false;
bool _gearCleared = false;
bool _gearChanged = false;
bool _setPage = false;
bool _menuChanged = false;
uint8_t  menuCounter = 0;
uint8_t subMenuCounter = 0;

bool inSystemSubMenu = false;

//Page Flags
bool _Disengage_KillSwitch_Page = false;
bool _Press_Brake_Page = false;
bool _Gear_Error_Page = false;
bool _System_Check_Okay_No_Icon_Page = false;
bool _System_Check_All_Icon_Page = false;
bool _testPage = false;

bool _setPoup = false;

bool _SysError_Shutdown_Page = false;
bool _SysError_StopDrive_Page = false;
bool _ModeChangeOFF_Page = false;

bool _After_Charge_Page = false;
bool _Vehicle_Settings_Page = false;
bool _Trip_Summary_Page = false;
//Vehicle Info
bool _Vehicle_Info_Page = false;
bool _Battery_Info_Page = false;
bool _Motor_Info_Page = false;
bool _Inverter_Info_Page = false;
bool buttonPressed = false;
//Vehicle Charging
bool _Charging_Page = false;
bool _ChargeComplete_Page = false;
bool _Charge_Error_Page = false;

uint8_t realTime_counter = 0;
uint8_t priorityLevel1_counter = 0;
uint8_t priorityLevel2_counter = 0;

uint8_t _transmit_Function = 0;

uint8_t popUpCounter = 0;
uint8_t popUpNumber = 0;
bool inPopup = true;
//uint8_t navigationCount = 0;

uint8_t _fireModeEnable = 0;
bool _firePage = false;

uitype_t volatile _drivePageSet = front;
uiTrasnmittype_t volatile _trasmitGlobal = Disengage_Page;

UART_QueueStruct txMsg = {0};

bool queueOverFlowed = false;

