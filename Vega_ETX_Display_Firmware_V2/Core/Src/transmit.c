#include <transmit.h>
#include "PollingRoutine.h"

#define eco_10 101
#define eco_20 201
#define eco_30 301
#define eco_40 401
#define eco_50 501
#define power_60 581
#define power_70 662
#define power_80 743
#define power_90 821
#define power_100 821

//TIME SET 5A A5 0B 82 00 9C 5A A5 12 06 1B 0D 08 00
// 											H  M  S

uint8_t status = 0;

uint8_t timeSet[14]={0x5A,0xA5,0x0B,0x82,0x00,0x9C,0x5A,0xA5,0x12,0x06,0x1B,0x00,0x00,0x00};
																		   //H    M    S
uint8_t DisenKillSwitch[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x2C }; //Page
uint8_t PressBrake[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x2D }; //Page

uint8_t firePage[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x8E }; //page

uint8_t GearErr[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x2E }; //Page

uint8_t SysCheck_lit_IconAll[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A,
		0x01, 0x01, 0x2F }; //Page
uint8_t SysCheck_Okay_NoIcon[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A,
		0x01, 0x01, 0x30 }; //Page

uint8_t ReadytoDrive[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x31 }; //Page

uint8_t TripSum[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x32 }; //Page
uint8_t AfterRecharge[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x33 }; //Page

//System Info Menu
uint8_t VehicleInfo[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x34 }; //Page

////With Press Back Button to Main Menu
uint8_t VehicleInfoBat[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x35 }; //Page

uint8_t VehicleInfoMot[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x36 }; //Page
uint8_t VehicleInfoInv[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x37 }; //Page

//Settings Pages
uint8_t Settings[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x38 }; //Page

uint8_t Vehicle[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x39 }; //Page

uint8_t System[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x3A }; //Page

uint8_t Bluetooth[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x3B }; //Page

uint8_t Errors[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x3C }; //Page

//////////////Error_Pages//////////////////////////////////////////////////
uint8_t SysError_shutdown[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A,
		0x01, 0x01, 0x46 }; //Page
uint8_t SysError_SafeStop[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A,
		0x01, 0x01, 0x47 }; //Page
uint8_t ChargeError_Code[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x48 }; //Page
////////////////////////////////////////////////////////////////////////////////////
uint8_t Tuk[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01, 0x3D }; //Page

uint8_t Charging[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x3E }; //Page

uint8_t ChargingComp[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x3F }; //Page
uint8_t ChargingErr[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x40 }; //Page
//////////////////////////////////////////////////////////////////////////////////
uint8_t SysErrMild[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x41 }; //Page
uint8_t SysErrCritical[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x42 }; //Page
/////////////////////////////////////////////////////Test will be removed///////////////////////
uint8_t testData_Page[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
		0x01, 0x8F }; //Page

//Indicators//
//Warning Lights
uint8_t BatteryON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x10, 0x01, 0x90 };
uint8_t BatteryOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x10, 0x00, 0x01 };

uint8_t BatterySOHLowON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x30, 0x01, 0xE2 };
uint8_t BatterySOHLowOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x30, 0x00, 0x01 };

uint8_t ErrorON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x11, 0x01, 0x92 };
uint8_t ErrorOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x11, 0x00, 0x01 };

uint8_t ServiceON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x21, 0x01, 0x94 };
uint8_t ServiceOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x21, 0x00, 0x01 };

uint8_t MildErrorON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x12, 0x01, 0x96 };
uint8_t MildErrorOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x12, 0x00, 0x01 };

uint8_t BatTempHighON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x12, 0x01, 0xE4 }; //Not_Used
uint8_t BatTempHighOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x12, 0x00, 0x01 }; //Not_Used

uint8_t HandBrakeON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x13, 0x01, 0x98 }; //Icon
uint8_t HandBrakeOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x13, 0x00, 0x01 }; //Icon

uint8_t TemperatureMotCritON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x01,
		0x9A };
uint8_t TemperatureMotCritOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x00,
		0x01 };

uint8_t TemperatureMotHighON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x01,
		0x9C };
uint8_t TemperatureMotHighOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x00,
		0x01 };

uint8_t TemperatureMotMildON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x01,
		0x9E };
uint8_t TemperatureMotMildOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x23, 0x00,
		0x01 };

//Indicators//
uint8_t TailgateOpenON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x22, 0x01, 0xA0 };
uint8_t TailgateOpenOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x22, 0x00, 0x01 };

uint8_t HighBeamON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x14, 0x01, 0xA2 };
uint8_t HighBeamOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x14, 0x00, 0x01 };

uint8_t SeatBeltON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x20, 0x01, 0xA4 };
uint8_t SeatBeltOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x20, 0x00, 0x01 };

uint8_t LowBeamON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x14, 0x01, 0xA6 };
uint8_t LowBeamOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x14, 0x00, 0x01 };

uint8_t LeftSignalON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x16, 0x01, 0xA8 };
uint8_t LeftSignalOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x16, 0x00, 0x01 };

uint8_t RightSignalON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x17, 0x01, 0xAA };
uint8_t RightSignalOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x17, 0x00, 0x01 };
//////////////////////////////////////
uint8_t PowerLimitedON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x18, 0x01, 0xAC };
uint8_t PowerLimitedOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x18, 0x00, 0x01 };

uint8_t ReadytoDrive_Icon_ON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x19, 0x01,
		0xAE };
uint8_t ReadytoDrive_Icon_OFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x19, 0x00,
		0x01 };

uint8_t BluetoothON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x24, 0x01, 0xB0 };
uint8_t BluetoothOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x24, 0x00, 0x01 };

uint8_t DeviceConnON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x25, 0x01, 0xB2 };
uint8_t DeviceConneOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x25, 0x00, 0x01 };
/////////////////
//Gear Selection
uint8_t ReverseON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x50, 0x01, 0xB4 };
uint8_t NeutralON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x50, 0x01, 0xB6 };
uint8_t DriveON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x50, 0x01, 0xB8 };
uint8_t GearClear[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x50, 0x00, 0x00 };

//Drive Mode
uint8_t EcoON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x55, 0x01, 0xBA };
uint8_t NormalON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x55, 0x01, 0xBC };
uint8_t SportON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x55, 0x01, 0xBE };
uint8_t modeClear[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x55, 0x00, 0x00 };

//Drive Unit
uint8_t DriveUnitOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x26, 0x01, 0xC0 };
uint8_t DriveUnitON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x26, 0x01, 0xC2 };

//Range Indicator
uint8_t BotGreenON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x28, 0x01, 0xC4 };
uint8_t BotOrangeON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x28, 0x01, 0xC6 };
uint8_t BotRedON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x28, 0x01, 0xC8 };

//Settings Menu
uint8_t UI_Button_Vehicle[8] =
		{ 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x64, 0x01, 0xCA };
uint8_t UI_Button_System[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x64, 0x01, 0xCC };
uint8_t UI_Button_Bluetooth[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x64, 0x01,
		0xCE };
uint8_t UI_Button_Errors[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x64, 0x01, 0xD0 };
uint8_t UI_Button_Non[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x64, 0x00, 0x00 };

//Bluetooth Menu
uint8_t BluetoothONNoLit[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x88, 0x01, 0xD2 };
uint8_t BluetoothONLit[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x88, 0x01, 0xD4 };

uint8_t BluetoothOFFNoLit[8] =
		{ 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x88, 0x01, 0xD6 };
uint8_t BluetoothOFFLit[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x88, 0x01, 0xD8 };

//System Menu
uint8_t TimeSelect[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x84, 0x01, 0xDA };
uint8_t TimeSelectOff[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x84, 0x01, 0x00 };
uint8_t BrightnessSelect[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x86, 0x01, 0xDC };
uint8_t BrightnessSelectOff[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x86, 0x01,
		0x00 };
//Charging Menu
uint8_t SlowCharging[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x85, 0x01, 0xDA };
uint8_t FastCharging[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x85, 0x01, 0xDA };

//Side Menu
uint8_t HighBatTemp[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x85, 0x02, 0x58 };
uint8_t LowBat[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x85, 0x02, 0x5A };
uint8_t LowBatCharge[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x85, 0x02, 0x5C };
uint8_t BatMenuOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x85, 0x00, 0x00 };

uint8_t TailgateOpen[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x86, 0x02, 0x5E };
uint8_t TailgateClose[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x86, 0x00, 0x00 };

//Mode Pages
uint8_t Eco[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01, 0x43 }; //Page

uint8_t Normal[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01,
		0x44 }; //Page

uint8_t Sport[10] =
		{ 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01, 0x01, 0x45 }; //Page

uint8_t EcoPopUp[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x87, 0x02, 0x60 }; //0x02, 0x60
uint8_t NormalPopUp[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x87, 0x02, 0x62 }; //0x02, 0x62
uint8_t SportPopUp[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x87, 0x02, 0x64 }; //0x02, 0x64

uint8_t popOff[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x87, 0x00, 0x00 };

//uint8_t modeChange_Lock[10] = { 0x5A, 0xA5, 0x07, 0x82, 0x00, 0x84, 0x5A, 0x01,
//		0x01, 0x45 }; //Page

uint8_t modeChange_Lock[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x89, 0x02, 0x6E };

/////////////////////////////////////////////////////////

uint8_t ChargerConnErrON[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x92, 0x02, 0x66 };
uint8_t ChargerConnErrOFF[8] =
		{ 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x92, 0x00, 0x00 };

uint8_t EmergencyPressed[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x91, 0x02, 0x68 };
uint8_t EmergencyPressedOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x91, 0x00,
		0x00 };

uint8_t HighMotTempMild[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x88, 0x02, 0x6A };
uint8_t HighMotTempCrit[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x88, 0x02, 0x6C };
uint8_t HighMotTempOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x88, 0x00, 0x00 };

uint8_t DriveModeErr[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x89, 0x02, 0x6E };
uint8_t DriveModeErrOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x89, 0x00, 0x00 };

uint8_t RegenBrakeErr[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x90, 0x02, 0x70 };
uint8_t RegenBrakeErrOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x90, 0x00, 0x00 };

uint8_t ChargerErr[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x93, 0x02, 0x72 };
uint8_t ChargerErrOFF[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x93, 0x00, 0x00 };

//Others
uint8_t usartRX[15] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t TripReset[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x11, 0x40, 0x00, 0x00 };
uint8_t readTime[7] = { 0x5A, 0xA5, 0x04, 0x83, 0x00, 0x10, 0x04 };

//struct tm t;
//extern time_t t_of_day;
//
//time_t rawtime = 3056441880;
//struct tm ts;
//char timebuf[80];
//
//uint32_t canMailbox;

//Battery Bar
uint8_t bat0[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x00, 0x00 };
uint8_t bat5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xBC };
uint8_t bat10[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xBE };
uint8_t bat15[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xC0 };
uint8_t bat20[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xC2 };
uint8_t bat25[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xC4 };
uint8_t bat30[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xC6 };
uint8_t bat35[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xC8 };
uint8_t bat40[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xCA };
uint8_t bat45[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xCC };
uint8_t bat50[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xCE };
uint8_t bat55[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xD0 };
uint8_t bat60[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xD2 };
uint8_t bat65[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xD4 };
uint8_t bat70[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xD6 };
uint8_t bat75[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xD8 };
uint8_t bat80[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xDA };
uint8_t bat85[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xDC };
uint8_t bat90[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xDE };
uint8_t bat100[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x12, 0x00, 0x02, 0xE0 };

//Power Bar
uint8_t eco0[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x01, 0x00 };
uint8_t eco1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE2 };
uint8_t eco2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE4 };
uint8_t eco3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE6 };
uint8_t eco4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE8 };
uint8_t eco5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xEA };

uint8_t ecooff1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE3 };
uint8_t ecooff2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE5 };
uint8_t ecooff3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE7 };
uint8_t ecooff4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xE9 };
uint8_t ecooff5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xEB };

uint8_t power1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xEC };
uint8_t power2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xEE };
uint8_t power3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF0 };
uint8_t power4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF2 };
uint8_t power5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF4 };

uint8_t poweroff1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xED };
uint8_t poweroff2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xEF };
uint8_t poweroff3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF1 };
uint8_t poweroff4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF3 };
uint8_t poweroff5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF5 };

uint8_t charge1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF6 };
uint8_t charge2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xF8 };
uint8_t charge3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xFA };
uint8_t charge4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xFC };
uint8_t charge5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x02, 0xFE };

uint8_t chargestart0[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x01, 0x00 };
uint8_t chargestart1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xF6 };
uint8_t chargestart2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xF8 };
uint8_t chargestart3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFA };
uint8_t chargestart4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFC };
uint8_t chargestart5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFE };

uint8_t chargestartoff1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xF7 };
uint8_t chargestartoff2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xF9 };
uint8_t chargestartoff3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFB };
uint8_t chargestartoff4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFD };
uint8_t chargestartoff5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x41, 0x02, 0xFF };

//Brightness Bar
uint8_t bright0[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x01, 0x00 };
uint8_t bright1[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x00 };
uint8_t bright2[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x02 };
uint8_t bright3[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x04 };
uint8_t bright4[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x06 };
uint8_t bright5[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x08 };
uint8_t bright6[8] = { 0x5A, 0xA5, 0x05, 0x82, 0x10, 0x40, 0x03, 0x0A };

struct tm t;
extern time_t t_of_day;

time_t rawtime = 3056441880;
struct tm ts;
char timebuf[80];
//uint8_t realTime_counter = 0;
//uint8_t oneTime_counter = 0;
//uint8_t _transmit_Function = 0;

uint8_t txTest = 0;
uint8_t check1 = 0;

#define IconSize 8
#define PageSize 10

//#define VEGA_TX
//#define DMA
//#define No_DMA
#define Queue
//#define No_Queue

#ifdef No_DMA
#define Transmit_strDATA HAL_UART_Transmit(&huart3, strDATA, sizeof(strDATA), HAL_MAX_DELAY);
#define Transmit_strDATA2 HAL_UART_Transmit(&huart3, strDATA2, sizeof(strDATA2), HAL_MAX_DELAY);

#define Tuk_Page HAL_UART_Transmit(&huart3, Tuk,sizeof(Tuk),HAL_MAX_DELAY)

#define Fire_Page HAL_UART_Transmit(&huart3, firePage, sizeof(firePage), HAL_MAX_DELAY)

#define Disengage_KillSwitch_Page HAL_UART_Transmit(&huart3, DisenKillSwitch,sizeof(DisenKillSwitch),HAL_MAX_DELAY)
#define Press_Brake_Page HAL_UART_Transmit(&huart3, PressBrake, sizeof(PressBrake),HAL_MAX_DELAY)
#define Gear_Error_Page HAL_UART_Transmit(&huart3, GearErr, sizeof(GearErr),HAL_MAX_DELAY)

#define Gear_Neutral_Icon HAL_UART_Transmit(&huart3, NeutralON, sizeof(NeutralON),HAL_MAX_DELAY)
#define Gear_Drive_Icon HAL_UART_Transmit(&huart3, DriveON, sizeof(DriveON), HAL_MAX_DELAY)
#define Gear_Reverse_Icon HAL_UART_Transmit(&huart3, ReverseON, sizeof(ReverseON),HAL_MAX_DELAY)
#define Gear_Clear_Icon HAL_UART_Transmit(&huart3, GearClear, sizeof(GearClear),HAL_MAX_DELAY)

#define System_Check_Okay_No_Icon_Page HAL_UART_Transmit(&huart3, SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon),HAL_MAX_DELAY)
#define System_Check_All_Icon_Page HAL_UART_Transmit(&huart3, SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll),HAL_MAX_DELAY)

#define Vehicle_Button HAL_UART_Transmit(&huart3, UI_Button_Vehicle, sizeof(UI_Button_Vehicle),HAL_MAX_DELAY)
#define System_Button HAL_UART_Transmit(&huart3, UI_Button_System, sizeof(UI_Button_System),HAL_MAX_DELAY)
#define Bluetooth_Button HAL_UART_Transmit(&huart3, UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth),HAL_MAX_DELAY)
#define Error_Button HAL_UART_Transmit(&huart3, UI_Button_Errors, sizeof(UI_Button_Errors), HAL_MAX_DELAY)
#define NO_Button HAL_UART_Transmit(&huart3, UI_Button_Non, sizeof(UI_Button_Non),HAL_MAX_DELAY)

#define After_Charge_Page HAL_UART_Transmit(&huart3, AfterRecharge, sizeof(AfterRecharge),HAL_MAX_DELAY)

#define Vehicle_Settings_Page HAL_UART_Transmit(&huart3, Settings, sizeof(Settings), HAL_MAX_DELAY)
#define Trip_Summary_Page HAL_UART_Transmit(&huart3, TripSum, sizeof(TripSum), HAL_MAX_DELAY)
#define Vehicle_Info_Page HAL_UART_Transmit(&huart3, VehicleInfo, sizeof(VehicleInfo),HAL_MAX_DELAY)

#define General_Menu_Page HAL_UART_Transmit(&huart3, Vehicle, sizeof(Vehicle), HAL_MAX_DELAY)
#define System_Menu_Page HAL_UART_Transmit(&huart3, System, sizeof(System), HAL_MAX_DELAY)
#define Bluetooth_Menu_Page HAL_UART_Transmit(&huart3, Bluetooth, sizeof(Bluetooth),HAL_MAX_DELAY)
#define Error_Menu_Page HAL_UART_Transmit(&huart3, Errors, sizeof(Errors), HAL_MAX_DELAY)

#define TimeSetting_Button HAL_UART_Transmit(&huart3,TimeSelect,sizeof(TimeSelect),HAL_MAX_DELAY)
#define TimeSetting_Button_OFF HAL_UART_Transmit(&huart3,TimeSelectOff,sizeof(TimeSelectOff),HAL_MAX_DELAY)

#define BrightnessSetting_Button HAL_UART_Transmit(&huart3,BrightnessSelect,sizeof(BrightnessSelect),HAL_MAX_DELAY)
#define BrightnessSetting_Button_OFF HAL_UART_Transmit(&huart3,BrightnessSelectOff,sizeof(BrightnessSelectOff),HAL_MAX_DELAY)

#define Battery_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoBat, sizeof(VehicleInfoBat),HAL_MAX_DELAY)
#define Motor_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoMot, sizeof(VehicleInfoMot),HAL_MAX_DELAY)
#define Inverter_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoInv, sizeof(VehicleInfoInv),HAL_MAX_DELAY)

#define Charging_Page HAL_UART_Transmit(&huart3, Charging, sizeof(Charging),HAL_MAX_DELAY)
#define ChargeComplete_Page HAL_UART_Transmit(&huart3, ChargingComp, sizeof(ChargingComp),HAL_MAX_DELAY)
#define Charge_Error_Page HAL_UART_Transmit(&huart3, ChargingErr, sizeof(ChargingErr),HAL_MAX_DELAY)

#define Charge_Error_WithPopup_Page HAL_UART_Transmit(&huart3, ChargeError_Code,sizeof(ChargeError_Code),HAL_MAX_DELAY)

#define Charge_Connection_Error_Popup_ON HAL_UART_Transmit(&huart3, ChargerConnErrON,sizeof(ChargerConnErrON), HAL_MAX_DELAY)
#define Charge_Connection_Error_Popup_OFF HAL_UART_Transmit(&huart3, ChargerConnErrOFF,sizeof(ChargerConnErrOFF), HAL_MAX_DELAY)
///LIT

////////

#define Trip_Reset HAL_UART_Transmit(&huart3, TripReset, sizeof(TripReset), HAL_MAX_DELAY)

#define DriveUnit_ON_Icon HAL_UART_Transmit(&huart3, DriveUnitON, sizeof(DriveUnitON),HAL_MAX_DELAY)
#define DriveUnit_OFF_Icon HAL_UART_Transmit(&huart3, DriveUnitOFF, sizeof(DriveUnitOFF),HAL_MAX_DELAY)

#define ReadytoDrive_ON_Icon HAL_UART_Transmit(&huart3, ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON),HAL_MAX_DELAY)
#define ReadytoDrive_OFF_Icon HAL_UART_Transmit(&huart3, ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF),HAL_MAX_DELAY)
#define ReadytoDrive_Page HAL_UART_Transmit(&huart3, ReadytoDrive, sizeof(ReadytoDrive),HAL_MAX_DELAY)

#define PowerLimitON_Icon HAL_UART_Transmit(&huart3, PowerLimitedON, sizeof(PowerLimitedON),HAL_MAX_DELAY)
#define PowerLimitOFF_Icon HAL_UART_Transmit(&huart3, PowerLimitedOFF,sizeof(PowerLimitedOFF),HAL_MAX_DELAY)

#define HandBrake_ON_Icon HAL_UART_Transmit(&huart3, HandBrakeON,sizeof(HandBrakeON),HAL_MAX_DELAY)
#define HandBrake_OFF_Icon HAL_UART_Transmit(&huart3, HandBrakeOFF,sizeof(HandBrakeOFF),HAL_MAX_DELAY)

#define Motor_Critical_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotCritON,sizeof(TemperatureMotCritON),HAL_MAX_DELAY)
#define Motor_Critical_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF),HAL_MAX_DELAY)

#define Motor_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotHighON,sizeof(TemperatureMotHighON),HAL_MAX_DELAY)
#define Motor_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF),HAL_MAX_DELAY)

#define Motor_Mild_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotMildON,sizeof(TemperatureMotMildON),HAL_MAX_DELAY)
#define Motor_Mild_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF),HAL_MAX_DELAY)

#define Tailgate_Opened_Icon HAL_UART_Transmit(&huart3, TailgateOpenON,sizeof(TailgateOpenON),HAL_MAX_DELAY)
#define Tailgate_Closed_Icon HAL_UART_Transmit(&huart3, TailgateOpenOFF,sizeof(TailgateOpenOFF),HAL_MAX_DELAY)

//BluetoothON
//BluetoothOFF
//
//BluetoothONNoLit
//BluetoothOFFNoLit
//
//BluetoothONLit
//BluetoothOFFLit

#define Highbeam_ON_Icon HAL_UART_Transmit(&huart3, HighBeamON,sizeof(HighBeamON),HAL_MAX_DELAY)
#define Highbeam_OFF_Icon HAL_UART_Transmit(&huart3, HighBeamOFF,sizeof(HighBeamOFF),HAL_MAX_DELAY)

#define Seatbelt_ON_Icon HAL_UART_Transmit(&huart3, SeatBeltON,sizeof(SeatBeltON),HAL_MAX_DELAY)
#define Seatbelt_OFF_Icon HAL_UART_Transmit(&huart3, SeatBeltOFF,sizeof(SeatBeltOFF),HAL_MAX_DELAY)

#define Lowbeam_ON_Icon HAL_UART_Transmit(&huart3, LowBeamON,sizeof(LowBeamON),HAL_MAX_DELAY)
#define Lowbeam_OFF_Icon HAL_UART_Transmit(&huart3, LowBeamOFF,sizeof(LowBeamOFF),HAL_MAX_DELAY)

#define Error_ON_Icon HAL_UART_Transmit(&huart3, ErrorON, sizeof(ErrorON),HAL_MAX_DELAY)
#define Error_OFF_Icon HAL_UART_Transmit(&huart3, ErrorOFF, sizeof(ErrorOFF),HAL_MAX_DELAY)

#define Mild_Error_ON_Icon HAL_UART_Transmit(&huart3, MildErrorON, sizeof(MildErrorON),HAL_MAX_DELAY)
#define Mild_Error_OFF_Icon HAL_UART_Transmit(&huart3, MildErrorOFF, sizeof(MildErrorOFF),HAL_MAX_DELAY)

#define Service_Error_ON_Icon HAL_UART_Transmit(&huart3, ServiceON, sizeof(ServiceON),HAL_MAX_DELAY)
#define Service_Error_OFF_Icon HAL_UART_Transmit(&huart3, ServiceOFF, sizeof(ServiceOFF),HAL_MAX_DELAY)

#define Battery_SOH_LOW_Popup_ON HAL_UART_Transmit(&huart3, BatterySOHLowON, sizeof(BatterySOHLowON),HAL_MAX_DELAY)
#define Battery_SOH_LOW_Popup_OFF HAL_UART_Transmit(&huart3, BatterySOHLowOFF, sizeof(BatterySOHLowOFF),HAL_MAX_DELAY)
#define Battery_High_Temp_Popup_ON HAL_UART_Transmit(&huart3, HighBatTemp, sizeof(HighBatTemp),HAL_MAX_DELAY)
#define Battery_High_Temp_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
#define Battery_LOW20_Popup_ON	HAL_UART_Transmit(&huart3, LowBat, sizeof(LowBat),HAL_MAX_DELAY)
#define Battery_LOW20_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
#define Battery_LOW_Charge_Popup_ON HAL_UART_Transmit(&huart3, LowBatCharge, sizeof(LowBatCharge),HAL_MAX_DELAY)
#define Battery_LOW_Charge_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
#define Battery_Temp_High_Icon HAL_UART_Transmit(&huart3, BatTempHighON, sizeof(BatTempHighON),HAL_MAX_DELAY)
#define Battery_Temp_OK_Icon HAL_UART_Transmit(&huart3, BatTempHighOFF, sizeof(BatTempHighOFF),HAL_MAX_DELAY)
#define Battery_ON_Icon HAL_UART_Transmit(&huart3, BatteryON, sizeof(BatteryON),HAL_MAX_DELAY)
#define Battery_OFF_Icon HAL_UART_Transmit(&huart3, BatteryOFF, sizeof(BatteryOFF),HAL_MAX_DELAY)

#define SystemError_Critical_Popup HAL_UART_Transmit(&huart3, SysErrCritical, sizeof(SysErrCritical),HAL_MAX_DELAY)
#define SystemError_Mild_Popup_Page HAL_UART_Transmit(&huart3, SysErrMild, sizeof(SysErrMild),HAL_MAX_DELAY)
#define SysError_Shutdown_Page HAL_UART_Transmit(&huart3, SysError_shutdown,sizeof(SysError_shutdown),HAL_MAX_DELAY)
#define ModeChangeOFF_Page HAL_UART_Transmit(&huart3, modeChange_Lock,sizeof(modeChange_Lock),HAL_MAX_DELAY)
#define SysError_StopDrive_Page HAL_UART_Transmit(&huart3, SysError_SafeStop,sizeof(SysError_SafeStop),HAL_MAX_DELAY)

#define NormalMode_Popup_Page HAL_UART_Transmit(&huart3, Normal, sizeof(Normal),HAL_MAX_DELAY)
#define NormalMode_Popup HAL_UART_Transmit(&huart3, NormalPopUp, sizeof(NormalPopUp),HAL_MAX_DELAY)
#define NormalMode_Icon HAL_UART_Transmit(&huart3, NormalON, sizeof(NormalON), HAL_MAX_DELAY)

#define EcoMode_Popup_Page HAL_UART_Transmit(&huart3, Eco, sizeof(Eco), HAL_MAX_DELAY)
#define EcoMode_Popup HAL_UART_Transmit(&huart3, EcoPopUp, sizeof(EcoPopUp), HAL_MAX_DELAY)
#define EcoMode_Icon HAL_UART_Transmit(&huart3, EcoON, sizeof(EcoON), HAL_MAX_DELAY)

#define SportMode_Popup_Page HAL_UART_Transmit(&huart3, Sport, sizeof(Sport), HAL_MAX_DELAY)
#define SportMode_Popup HAL_UART_Transmit(&huart3, SportPopUp, sizeof(SportPopUp), HAL_MAX_DELAY)
#define SportMode_Icon HAL_UART_Transmit(&huart3, SportON, sizeof(SportON), HAL_MAX_DELAY)

#define ModeClear_Icon HAL_UART_Transmit(&huart3, modeClear, sizeof(modeClear),HAL_MAX_DELAY)
#define popUp_OFF HAL_UART_Transmit(&huart3, popOff, sizeof(popOff), HAL_MAX_DELAY)

#define L_Signal_ON_Icon HAL_UART_Transmit(&huart3, LeftSignalON, sizeof(LeftSignalON),HAL_MAX_DELAY)
#define L_Signal_OFF_Icon HAL_UART_Transmit(&huart3, LeftSignalOFF, sizeof(LeftSignalOFF),HAL_MAX_DELAY)
#define R_Signal_ON_Icon HAL_UART_Transmit(&huart3, RightSignalON, sizeof(RightSignalON),HAL_MAX_DELAY)
#define R_Signal_OFF_Icon HAL_UART_Transmit(&huart3, RightSignalOFF, sizeof(RightSignalOFF),HAL_MAX_DELAY)

#define HighBeam_ON_Icon HAL_UART_Transmit(&huart3, HighBeamON, sizeof(HighBeamON),HAL_MAX_DELAY)
#define HighBeam_OFF_Icon HAL_UART_Transmit(&huart3, HighBeamOFF, sizeof(HighBeamOFF),HAL_MAX_DELAY)
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DMA Defines
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef DMA
#define Transmit_strDATA HAL_UART_Transmit_DMA(&huart3, strDATA, sizeof(strDATA));
#define Transmit_strDATA2 HAL_UART_Transmit_DMA(&huart3, strDATA2, sizeof(strDATA2));

#define Tuk_Page HAL_UART_Transmit_DMA(&huart3, Tuk,sizeof(Tuk))

#define Fire_Page HAL_UART_Transmit_DMA(&huart3, firePage, sizeof(firePage))

#define Disengage_KillSwitch_Page HAL_UART_Transmit_DMA(&huart3, DisenKillSwitch,sizeof(DisenKillSwitch))
#define Press_Brake_Page HAL_UART_Transmit_DMA(&huart3, PressBrake, sizeof(PressBrake))
#define Gear_Error_Page HAL_UART_Transmit_DMA(&huart3, GearErr, sizeof(GearErr))

#define Gear_Neutral_Icon HAL_UART_Transmit_DMA(&huart3, NeutralON, sizeof(NeutralON))
#define Gear_Drive_Icon HAL_UART_Transmit_DMA(&huart3, DriveON, sizeof(DriveON))
#define Gear_Reverse_Icon HAL_UART_Transmit_DMA(&huart3, ReverseON, sizeof(ReverseON))
#define Gear_Clear_Icon HAL_UART_Transmit_DMA(&huart3, GearClear, sizeof(GearClear))

#define System_Check_Okay_No_Icon_Page HAL_UART_Transmit_DMA(&huart3, SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon))
#define System_Check_All_Icon_Page HAL_UART_Transmit_DMA(&huart3, SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll))

#define Vehicle_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Vehicle, sizeof(UI_Button_Vehicle))
#define System_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_System, sizeof(UI_Button_System))
#define Bluetooth_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth))
#define Error_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Errors, sizeof(UI_Button_Errors))
#define NO_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Non, sizeof(UI_Button_Non))

#define After_Charge_Page HAL_UART_Transmit_DMA(&huart3, AfterRecharge, sizeof(AfterRecharge))

#define Vehicle_Settings_Page HAL_UART_Transmit_DMA(&huart3, Settings, sizeof(Settings))
#define Trip_Summary_Page HAL_UART_Transmit_DMA(&huart3, TripSum, sizeof(TripSum))
#define Vehicle_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfo, sizeof(VehicleInfo))

#define General_Menu_Page HAL_UART_Transmit_DMA(&huart3, Vehicle, sizeof(Vehicle))
#define System_Menu_Page HAL_UART_Transmit_DMA(&huart3, System, sizeof(System))
#define Bluetooth_Menu_Page HAL_UART_Transmit_DMA(&huart3, Bluetooth, sizeof(Bluetooth))
#define Error_Menu_Page HAL_UART_Transmit_DMA(&huart3, Errors, sizeof(Errors))

#define TimeSetting_Button HAL_UART_Transmit_DMA(&huart3,TimeSelect,sizeof(TimeSelect))
#define TimeSetting_Button_OFF HAL_UART_Transmit_DMA(&huart3,TimeSelectOff,sizeof(TimeSelectOff))

#define BrightnessSetting_Button HAL_UART_Transmit_DMA(&huart3,BrightnessSelect,sizeof(BrightnessSelect))
#define BrightnessSetting_Button_OFF HAL_UART_Transmit_DMA(&huart3,BrightnessSelectOff,sizeof(BrightnessSelectOff))

#define Battery_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoBat, sizeof(VehicleInfoBat))
#define Motor_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoMot, sizeof(VehicleInfoMot))
#define Inverter_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoInv, sizeof(VehicleInfoInv))

#define Charging_Page HAL_UART_Transmit_DMA(&huart3, Charging, sizeof(Charging))
#define ChargeComplete_Page HAL_UART_Transmit_DMA(&huart3, ChargingComp, sizeof(ChargingComp))
#define Charge_Error_Page HAL_UART_Transmit_DMA(&huart3, ChargingErr, sizeof(ChargingErr))

#define Charge_Error_WithPopup_Page HAL_UART_Transmit_DMA(&huart3, ChargeError_Code,sizeof(ChargeError_Code))

#define Charge_Connection_Error_Popup_ON HAL_UART_Transmit_DMA(&huart3, ChargerConnErrON,sizeof(ChargerConnErrON))
#define Charge_Connection_Error_Popup_OFF HAL_UART_Transmit_DMA(&huart3, ChargerConnErrOFF,sizeof(ChargerConnErrOFF))
///LIT

////////

#define Trip_Reset HAL_UART_Transmit_DMA(&huart3, TripReset, sizeof(TripReset))

#define DriveUnit_ON_Icon HAL_UART_Transmit_DMA(&huart3, DriveUnitON, sizeof(DriveUnitON))
#define DriveUnit_OFF_Icon HAL_UART_Transmit_DMA(&huart3, DriveUnitOFF, sizeof(DriveUnitOFF))

#define ReadytoDrive_ON_Icon HAL_UART_Transmit_DMA(&huart3, ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON))
#define ReadytoDrive_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF))
#define ReadytoDrive_Page HAL_UART_Transmit_DMA(&huart3, ReadytoDrive, sizeof(ReadytoDrive))

#define PowerLimitON_Icon HAL_UART_Transmit_DMA(&huart3, PowerLimitedON, sizeof(PowerLimitedON))
#define PowerLimitOFF_Icon HAL_UART_Transmit_DMA(&huart3, PowerLimitedOFF,sizeof(PowerLimitedOFF))

#define HandBrake_ON_Icon HAL_UART_Transmit_DMA(&huart3, HandBrakeON,sizeof(HandBrakeON))
#define HandBrake_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HandBrakeOFF,sizeof(HandBrakeOFF))

#define Motor_Critical_Temp_ON_Icon HAL_UART_Transmit_DMA_DMA(&huart3, TemperatureMotCritON,sizeof(TemperatureMotCritON))
#define Motor_Critical_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF))

#define Motor_Temp_ON_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotHighON,sizeof(TemperatureMotHighON))
#define Motor_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF))

#define Motor_Mild_Temp_ON_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotMildON,sizeof(TemperatureMotMildON))
#define Motor_Mild_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF))

#define Tailgate_Opened_Icon HAL_UART_Transmit_DMA(&huart3, TailgateOpenON,sizeof(TailgateOpenON))
#define Tailgate_Closed_Icon HAL_UART_Transmit_DMA(&huart3, TailgateOpenOFF,sizeof(TailgateOpenOFF))

//BluetoothON
//BluetoothOFF
//
//BluetoothONNoLit
//BluetoothOFFNoLit
//
//BluetoothONLit
//BluetoothOFFLit

#define Highbeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamON,sizeof(HighBeamON))
#define Highbeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamOFF,sizeof(HighBeamOFF))

#define Seatbelt_ON_Icon HAL_UART_Transmit_DMA(&huart3, SeatBeltON,sizeof(SeatBeltON))
#define Seatbelt_OFF_Icon HAL_UART_Transmit_DMA(&huart3, SeatBeltOFF,sizeof(SeatBeltOFF))

#define Lowbeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, LowBeamON,sizeof(LowBeamON))
#define Lowbeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, LowBeamOFF,sizeof(LowBeamOFF))

#define Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, ErrorON, sizeof(ErrorON))
#define Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ErrorOFF, sizeof(ErrorOFF))

#define Mild_Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, MildErrorON, sizeof(MildErrorON))
#define Mild_Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, MildErrorOFF, sizeof(MildErrorOFF))

#define Service_Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, ServiceON, sizeof(ServiceON))
#define Service_Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ServiceOFF, sizeof(ServiceOFF))

#define Battery_SOH_LOW_Popup_ON HAL_UART_Transmit_DMA(&huart3, BatterySOHLowON, sizeof(BatterySOHLowON))
#define Battery_SOH_LOW_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatterySOHLowOFF, sizeof(BatterySOHLowOFF))
#define Battery_High_Temp_Popup_ON HAL_UART_Transmit_DMA(&huart3, HighBatTemp, sizeof(HighBatTemp))
#define Battery_High_Temp_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW20_Popup_ON	HAL_UART_Transmit_DMA(&huart3, LowBat, sizeof(LowBat))
#define Battery_LOW20_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW_Charge_Popup_ON HAL_UART_Transmit_DMA(&huart3, LowBatCharge, sizeof(LowBatCharge))
#define Battery_LOW_Charge_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
#define Battery_Temp_High_Icon HAL_UART_Transmit_DMA(&huart3, BatTempHighON, sizeof(BatTempHighON))
#define Battery_Temp_OK_Icon HAL_UART_Transmit_DMA(&huart3, BatTempHighOFF, sizeof(BatTempHighOFF))
#define Battery_ON_Icon HAL_UART_Transmit_DMA(&huart3, BatteryON, sizeof(BatteryON))
#define Battery_OFF_Icon HAL_UART_Transmit_DMA(&huart3, BatteryOFF, sizeof(BatteryOFF))

#define SystemError_Critical_Popup HAL_UART_Transmit_DMA(&huart3, SysErrCritical, sizeof(SysErrCritical))
#define SystemError_Mild_Popup_Page HAL_UART_Transmit_DMA(&huart3, SysErrMild, sizeof(SysErrMild))
#define SysError_Shutdown_Page HAL_UART_Transmit_DMA(&huart3, SysError_shutdown,sizeof(SysError_shutdown))
#define ModeChangeOFF_Page HAL_UART_Transmit_DMA(&huart3, modeChange_Lock,sizeof(modeChange_Lock))
#define SysError_StopDrive_Page HAL_UART_Transmit_DMA(&huart3, SysError_SafeStop,sizeof(SysError_SafeStop))

#define NormalMode_Popup_Page HAL_UART_Transmit_DMA(&huart3, Normal, sizeof(Normal))
#define NormalMode_Popup HAL_UART_Transmit_DMA(&huart3, NormalPopUp, sizeof(NormalPopUp))
#define NormalMode_Icon HAL_UART_Transmit_DMA(&huart3, NormalON, sizeof(NormalON))

#define EcoMode_Popup_Page HAL_UART_Transmit_DMA(&huart3, Eco, sizeof(Eco))
#define EcoMode_Popup HAL_UART_Transmit_DMA(&huart3, EcoPopUp, sizeof(EcoPopUp))
#define EcoMode_Icon HAL_UART_Transmit_DMA(&huart3, EcoON, sizeof(EcoON))

#define SportMode_Popup_Page HAL_UART_Transmit_DMA(&huart3, Sport, sizeof(Sport))
#define SportMode_Popup HAL_UART_Transmit_DMA(&huart3, SportPopUp, sizeof(SportPopUp))
#define SportMode_Icon HAL_UART_Transmit_DMA(&huart3, SportON, sizeof(SportON))

#define ModeClear_Icon HAL_UART_Transmit_DMA(&huart3, modeClear, sizeof(modeClear))
#define popUp_OFF HAL_UART_Transmit_DMA(&huart3, popOff, sizeof(popOff))

#define L_Signal_ON_Icon HAL_UART_Transmit_DMA(&huart3, LeftSignalON, sizeof(LeftSignalON))
#define L_Signal_OFF_Icon HAL_UART_Transmit_DMA(&huart3, LeftSignalOFF, sizeof(LeftSignalOFF))
#define R_Signal_ON_Icon HAL_UART_Transmit_DMA(&huart3, RightSignalON, sizeof(RightSignalON))
#define R_Signal_OFF_Icon HAL_UART_Transmit_DMA(&huart3, RightSignalOFF, sizeof(RightSignalOFF))

#define HighBeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamON, sizeof(HighBeamON))
#define HighBeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamOFF, sizeof(HighBeamOFF))
#endif

#ifdef VEGA_TX
#define Transmit_strDATA transmitPageHandler(strDATA, sizeof(strDATA));
#define Transmit_strDATA2 transmitPageHandler(strDATA2, sizeof(strDATA2));

#define Tuk_Page transmitPageHandler( Tuk,sizeof(Tuk))

#define Disengage_KillSwitch_Page transmitPageHandler( DisenKillSwitch,sizeof(DisenKillSwitch))
#define Press_Brake_Page transmitPageHandler( PressBrake, sizeof(PressBrake))
#define Gear_Error_Page transmitPageHandler( GearErr, sizeof(GearErr))

#define Gear_Neutral_Icon transmitPageHandler( NeutralON, sizeof(NeutralON))
#define Gear_Drive_Icon transmitPageHandler( DriveON, sizeof(DriveON))
#define Gear_Reverse_Icon transmitPageHandler( ReverseON, sizeof(ReverseON))
#define Gear_Clear_Icon transmitPageHandler( GearClear, sizeof(GearClear))

#define System_Check_Okay_No_Icon_Page transmitPageHandler( SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon))
#define System_Check_All_Icon_Page transmitPageHandler( SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll))

#define Vehicle_Button transmitPageHandler( UI_Button_Vehicle, sizeof(UI_Button_Vehicle))
#define System_Button transmitPageHandler( UI_Button_System, sizeof(UI_Button_System))
#define Bluetooth_Button transmitPageHandler( UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth))
#define Error_Button transmitPageHandler( UI_Button_Errors, sizeof(UI_Button_Errors))
#define NO_Button transmitPageHandler( UI_Button_Non, sizeof(UI_Button_Non))

#define After_Charge_Page transmitPageHandler( AfterRecharge, sizeof(AfterRecharge))

#define Vehicle_Settings_Page transmitPageHandler( Settings, sizeof(Settings))
#define Trip_Summary_Page transmitPageHandler( TripSum, sizeof(TripSum))
#define Vehicle_Info_Page transmitPageHandler( VehicleInfo, sizeof(VehicleInfo))

#define General_Menu_Page transmitPageHandler( Vehicle, sizeof(Vehicle))
#define System_Menu_Page transmitPageHandler( System, sizeof(System))
#define Bluetooth_Menu_Page transmitPageHandler( Bluetooth, sizeof(Bluetooth))
#define Error_Menu_Page transmitPageHandler( Errors, sizeof(Errors))
#define TimeSetting transmitPageHandler(TimeSelect,IconSize)

#define Battery_Info_Page transmitPageHandler( VehicleInfoBat, sizeof(VehicleInfoBat))
#define Motor_Info_Page transmitPageHandler( VehicleInfoMot, sizeof(VehicleInfoMot))
#define Inverter_Info_Page transmitPageHandler( VehicleInfoInv, sizeof(VehicleInfoInv))

#define Charging_Page transmitPageHandler( Charging, sizeof(Charging))
#define ChargeComplete_Page transmitPageHandler( ChargingComp, sizeof(ChargingComp))
#define Charge_Error_Page transmitPageHandler( ChargingErr, sizeof(ChargingErr))

#define Charge_Error_WithPopup_Page transmitPageHandler( ChargeError_Code,sizeof(ChargeError_Code))

#define Charge_Connection_Error_Popup_ON transmitPageHandler( ChargerConnErrON,sizeof(ChargerConnErrON))
#define Charge_Connection_Error_Popup_OFF transmitPageHandler( ChargerConnErrOFF,sizeof(ChargerConnErrOFF))
///LIT

////////

#define Trip_Reset transmitPageHandler( TripReset, sizeof(TripReset))

#define DriveUnit_ON_Icon transmitPageHandler( DriveUnitON, sizeof(DriveUnitON))
#define DriveUnit_OFF_Icon transmitPageHandler( DriveUnitOFF, sizeof(DriveUnitOFF))

#define ReadytoDrive_ON_Icon transmitPageHandler( ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON))
#define ReadytoDrive_OFF_Icon transmitPageHandler( ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF))
#define ReadytoDrive_Page transmitPageHandler(ReadytoDrive,10)

#define PowerLimitON_Icon transmitPageHandler(PowerLimitedON, sizeof(PowerLimitedON))
#define PowerLimitOFF_Icon transmitPageHandler(PowerLimitedOFF,sizeof(PowerLimitedOFF))

#define HandBrake_ON_Icon transmitPageHandler(HandBrakeON,sizeof(HandBrakeON))
#define HandBrake_OFF_Icon transmitPageHandler(HandBrakeOFF,sizeof(HandBrakeOFF))

#define Motor_Critical_Temp_ON_Icon transmitPageHandler(TemperatureMotCritON,sizeof(TemperatureMotCritON))
#define Motor_Critical_Temp_OFF_Icon transmitPageHandler(TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF))

#define Motor_Temp_ON_Icon transmitPageHandler(TemperatureMotHighON,sizeof(TemperatureMotHighON))
#define Motor_Temp_OFF_Icon transmitPageHandler(TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF))

#define Motor_Mild_Temp_ON_Icon transmitPageHandler( TemperatureMotMildON,sizeof(TemperatureMotMildON))
#define Motor_Mild_Temp_OFF_Icon transmitPageHandler( TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF))

#define Tailgate_Opened_Icon transmitPageHandler( TailgateOpenON,sizeof(TailgateOpenON))
#define Tailgate_Closed_Icon transmitPageHandler( TailgateOpenOFF,sizeof(TailgateOpenOFF))

//BluetoothON
//BluetoothOFF
//
//BluetoothONNoLit
//BluetoothOFFNoLit
//
//BluetoothONLit
//BluetoothOFFLit

#define Highbeam_ON_Icon transmitPageHandler(HighBeamON,sizeof(HighBeamON))
#define Highbeam_OFF_Icon transmitPageHandler(HighBeamOFF,sizeof(HighBeamOFF))

#define Seatbelt_ON_Icon transmitPageHandler(SeatBeltON,sizeof(SeatBeltON))
#define Seatbelt_OFF_Icon transmitPageHandler(SeatBeltOFF,sizeof(SeatBeltOFF))

#define Lowbeam_ON_Icon transmitPageHandler(LowBeamON,sizeof(LowBeamON))
#define Lowbeam_OFF_Icon transmitPageHandler(LowBeamOFF,sizeof(LowBeamOFF))

#define Error_ON_Icon transmitPageHandler( ErrorON, sizeof(ErrorON))
#define Error_OFF_Icon transmitPageHandler( ErrorOFF, sizeof(ErrorOFF))

#define Mild_Error_ON_Icon transmitPageHandler( MildErrorON, sizeof(MildErrorON))
#define Mild_Error_OFF_Icon transmitPageHandler( MildErrorOFF, sizeof(MildErrorOFF))

#define Service_Error_ON_Icon transmitPageHandler( ServiceON, sizeof(ServiceON))
#define Service_Error_OFF_Icon transmitPageHandler( ServiceOFF, sizeof(ServiceOFF))

#define Battery_SOH_LOW_Popup_ON transmitPageHandler( BatterySOHLowON, sizeof(BatterySOHLowON))
#define Battery_SOH_LOW_Popup_OFF transmitPageHandler( BatterySOHLowOFF, sizeof(BatterySOHLowOFF))
#define Battery_High_Temp_Popup_ON transmitPageHandler( HighBatTemp, sizeof(HighBatTemp))
#define Battery_High_Temp_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW20_Popup_ON	transmitPageHandler( LowBat, sizeof(LowBat))
#define Battery_LOW20_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW_Charge_Popup_ON transmitPageHandler( LowBatCharge, sizeof(LowBatCharge))
#define Battery_LOW_Charge_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
#define Battery_Temp_High_Icon transmitPageHandler( BatTempHighON, sizeof(BatTempHighON))
#define Battery_Temp_OK_Icon transmitPageHandler( BatTempHighOFF, sizeof(BatTempHighOFF))
#define Battery_ON_Icon transmitPageHandler( BatteryON, sizeof(BatteryON))
#define Battery_OFF_Icon transmitPageHandler( BatteryOFF, sizeof(BatteryOFF))

#define SystemError_Critical_Popup transmitPageHandler( SysErrCritical, sizeof(SysErrCritical))
#define SystemError_Mild_Popup_Page transmitPageHandler( SysErrMild, sizeof(SysErrMild))
#define SysError_Shutdown_Page transmitPageHandler( SysError_shutdown,sizeof(SysError_shutdown))
#define ModeChangeOFF_Page transmitPageHandler( modeChange_Lock,sizeof(modeChange_Lock))
#define SysError_StopDrive_Page transmitPageHandler( SysError_SafeStop,sizeof(SysError_SafeStop))

#define NormalMode_Popup transmitPageHandler( Normal, sizeof(Normal))
#define NormalMode_Icon transmitPageHandler( NormalON, sizeof(NormalON))
#define EcoMode_Popup transmitPageHandler( Eco, sizeof(Eco))
#define EcoMode_Icon transmitPageHandler( EcoON, sizeof(EcoON))
#define SportMode_Popup transmitPageHandler( Sport, sizeof(Sport))
#define SportMode_Icon transmitPageHandler( SportON, sizeof(SportON))
#define ModeClear_Icon transmitPageHandler( modeClear, sizeof(modeClear))

#define L_Signal_ON_Icon transmitPageHandler( LeftSignalON, sizeof(LeftSignalON))
#define L_Signal_OFF_Icon transmitPageHandler( LeftSignalOFF, sizeof(LeftSignalOFF))
#define R_Signal_ON_Icon transmitPageHandler( RightSignalON, sizeof(RightSignalON))
#define R_Signal_OFF_Icon transmitPageHandler( RightSignalOFF, sizeof(RightSignalOFF))

#define HighBeam_ON_Icon transmitPageHandler( HighBeamON, sizeof(HighBeamON))
#define HighBeam_OFF_Icon transmitPageHandler( HighBeamOFF, sizeof(HighBeamOFF))
#endif
#ifdef Queue

#define Transmit_strDATA SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#define Transmit_strDATA2 SaveToUART_TxBuffer(strDATA2, sizeof(strDATA2));

#define Tuk_Page SaveToUART_TxBuffer(Tuk,sizeof(Tuk))

#define Fire_Page SaveToUART_TxBuffer(firePage, sizeof(firePage))

#define Disengage_KillSwitch_Page SaveToUART_TxBuffer(DisenKillSwitch,sizeof(DisenKillSwitch))
#define Press_Brake_Page SaveToUART_TxBuffer(PressBrake, sizeof(PressBrake))
#define Gear_Error_Page SaveToUART_TxBuffer(GearErr, sizeof(GearErr))

#define Gear_Neutral_Icon SaveToUART_TxBuffer(NeutralON, sizeof(NeutralON))
#define Gear_Drive_Icon SaveToUART_TxBuffer(DriveON, sizeof(DriveON))
#define Gear_Reverse_Icon SaveToUART_TxBuffer(ReverseON, sizeof(ReverseON))
#define Gear_Clear_Icon SaveToUART_TxBuffer(GearClear, sizeof(GearClear))

#define System_Check_Okay_No_Icon_Page SaveToUART_TxBuffer(SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon))
#define System_Check_All_Icon_Page SaveToUART_TxBuffer(SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll))

#define Vehicle_Button SaveToUART_TxBuffer(UI_Button_Vehicle, sizeof(UI_Button_Vehicle))
#define System_Button SaveToUART_TxBuffer(UI_Button_System, sizeof(UI_Button_System))
#define Bluetooth_Button SaveToUART_TxBuffer(UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth))
#define Error_Button SaveToUART_TxBuffer(UI_Button_Errors, sizeof(UI_Button_Errors))
#define NO_Button SaveToUART_TxBuffer(UI_Button_Non, sizeof(UI_Button_Non))

#define After_Charge_Page SaveToUART_TxBuffer(AfterRecharge, sizeof(AfterRecharge))

#define Vehicle_Settings_Page SaveToUART_TxBuffer(Settings, sizeof(Settings))
#define Trip_Summary_Page SaveToUART_TxBuffer(TripSum, sizeof(TripSum))
#define Vehicle_Info_Page SaveToUART_TxBuffer(VehicleInfo, sizeof(VehicleInfo))

#define General_Menu_Page SaveToUART_TxBuffer(Vehicle, sizeof(Vehicle))
#define System_Menu_Page SaveToUART_TxBuffer(System, sizeof(System))
#define Bluetooth_Menu_Page SaveToUART_TxBuffer(Bluetooth, sizeof(Bluetooth))
#define Error_Menu_Page SaveToUART_TxBuffer(Errors, sizeof(Errors))

#define TimeSetting_Button SaveToUART_TxBuffer(TimeSelect,sizeof(TimeSelect))
#define TimeSetting_Button_OFF SaveToUART_TxBuffer(TimeSelectOff,sizeof(TimeSelectOff))

#define BrightnessSetting_Button SaveToUART_TxBuffer(BrightnessSelect,sizeof(BrightnessSelect))
#define BrightnessSetting_Button_OFF SaveToUART_TxBuffer(BrightnessSelectOff,sizeof(BrightnessSelectOff))

#define Battery_Info_Page SaveToUART_TxBuffer(VehicleInfoBat, sizeof(VehicleInfoBat))
#define Motor_Info_Page SaveToUART_TxBuffer(VehicleInfoMot, sizeof(VehicleInfoMot))
#define Inverter_Info_Page SaveToUART_TxBuffer(VehicleInfoInv, sizeof(VehicleInfoInv))

#define Charging_Page SaveToUART_TxBuffer(Charging, sizeof(Charging))
#define ChargeComplete_Page SaveToUART_TxBuffer(ChargingComp, sizeof(ChargingComp))
#define Charge_Error_Page SaveToUART_TxBuffer(ChargingErr, sizeof(ChargingErr))

#define Charge_Error_WithPopup_Page SaveToUART_TxBuffer(ChargeError_Code,sizeof(ChargeError_Code))

#define Charge_Connection_Error_Popup_ON SaveToUART_TxBuffer(ChargerConnErrON,sizeof(ChargerConnErrON))
#define Charge_Connection_Error_Popup_OFF SaveToUART_TxBuffer(ChargerConnErrOFF,sizeof(ChargerConnErrOFF))
///LIT

////////

#define Trip_Reset SaveToUART_TxBuffer(TripReset, sizeof(TripReset))

#define DriveUnit_ON_Icon SaveToUART_TxBuffer(DriveUnitON, sizeof(DriveUnitON))
#define DriveUnit_OFF_Icon SaveToUART_TxBuffer(DriveUnitOFF, sizeof(DriveUnitOFF))

#define ReadytoDrive_ON_Icon SaveToUART_TxBuffer(ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON))
#define ReadytoDrive_OFF_Icon SaveToUART_TxBuffer(ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF))
#define ReadytoDrive_Page SaveToUART_TxBuffer(ReadytoDrive, sizeof(ReadytoDrive))

#define PowerLimitON_Icon SaveToUART_TxBuffer(PowerLimitedON, sizeof(PowerLimitedON))
#define PowerLimitOFF_Icon SaveToUART_TxBuffer(PowerLimitedOFF,sizeof(PowerLimitedOFF))

#define HandBrake_ON_Icon SaveToUART_TxBuffer(HandBrakeON,sizeof(HandBrakeON))
#define HandBrake_OFF_Icon SaveToUART_TxBuffer(HandBrakeOFF,sizeof(HandBrakeOFF))

#define Motor_Critical_Temp_ON_Icon SaveToUART_TxBuffer(TemperatureMotCritON,sizeof(TemperatureMotCritON))
#define Motor_Critical_Temp_OFF_Icon SaveToUART_TxBuffer(TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF))

#define Motor_Temp_ON_Icon SaveToUART_TxBuffer(TemperatureMotHighON,sizeof(TemperatureMotHighON))
#define Motor_Temp_OFF_Icon SaveToUART_TxBuffer(TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF))

#define Motor_Mild_Temp_ON_Icon SaveToUART_TxBuffer(TemperatureMotMildON,sizeof(TemperatureMotMildON))
#define Motor_Mild_Temp_OFF_Icon SaveToUART_TxBuffer(TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF))

#define Tailgate_Opened_Icon SaveToUART_TxBuffer(TailgateOpenON,sizeof(TailgateOpenON))
#define Tailgate_Closed_Icon SaveToUART_TxBuffer(TailgateOpenOFF,sizeof(TailgateOpenOFF))

//BluetoothON
//BluetoothOFF
//
//BluetoothONNoLit
//BluetoothOFFNoLit
//
//BluetoothONLit
//BluetoothOFFLit

#define Highbeam_ON_Icon SaveToUART_TxBuffer(HighBeamON,sizeof(HighBeamON))
#define Highbeam_OFF_Icon SaveToUART_TxBuffer(HighBeamOFF,sizeof(HighBeamOFF))

#define Seatbelt_ON_Icon SaveToUART_TxBuffer(SeatBeltON,sizeof(SeatBeltON))
#define Seatbelt_OFF_Icon SaveToUART_TxBuffer(SeatBeltOFF,sizeof(SeatBeltOFF))

#define Lowbeam_ON_Icon SaveToUART_TxBuffer(LowBeamON,sizeof(LowBeamON))
#define Lowbeam_OFF_Icon SaveToUART_TxBuffer(LowBeamOFF,sizeof(LowBeamOFF))

#define Error_ON_Icon SaveToUART_TxBuffer(ErrorON, sizeof(ErrorON))
#define Error_OFF_Icon SaveToUART_TxBuffer(ErrorOFF, sizeof(ErrorOFF))

#define Mild_Error_ON_Icon SaveToUART_TxBuffer(MildErrorON, sizeof(MildErrorON))
#define Mild_Error_OFF_Icon SaveToUART_TxBuffer(MildErrorOFF, sizeof(MildErrorOFF))

#define Service_Error_ON_Icon SaveToUART_TxBuffer(ServiceON, sizeof(ServiceON))
#define Service_Error_OFF_Icon SaveToUART_TxBuffer(ServiceOFF, sizeof(ServiceOFF))

#define Battery_SOH_LOW_Popup_ON SaveToUART_TxBuffer(BatterySOHLowON, sizeof(BatterySOHLowON))
#define Battery_SOH_LOW_Popup_OFF SaveToUART_TxBuffer(BatterySOHLowOFF, sizeof(BatterySOHLowOFF))
#define Battery_High_Temp_Popup_ON SaveToUART_TxBuffer(HighBatTemp, sizeof(HighBatTemp))
#define Battery_High_Temp_Popup_OFF SaveToUART_TxBuffer(BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW20_Popup_ON	SaveToUART_TxBuffer(LowBat, sizeof(LowBat))
#define Battery_LOW20_Popup_OFF SaveToUART_TxBuffer(BatMenuOFF, sizeof(HighBatTemp))
#define Battery_LOW_Charge_Popup_ON SaveToUART_TxBuffer(LowBatCharge, sizeof(LowBatCharge))
#define Battery_LOW_Charge_Popup_OFF SaveToUART_TxBuffer(BatMenuOFF, sizeof(HighBatTemp))
#define Battery_Temp_High_Icon SaveToUART_TxBuffer(BatTempHighON, sizeof(BatTempHighON))
#define Battery_Temp_OK_Icon SaveToUART_TxBuffer(BatTempHighOFF, sizeof(BatTempHighOFF))
#define Battery_ON_Icon SaveToUART_TxBuffer(BatteryON, sizeof(BatteryON))
#define Battery_OFF_Icon SaveToUART_TxBuffer(BatteryOFF, sizeof(BatteryOFF))

#define SystemError_Critical_Popup SaveToUART_TxBuffer(SysErrCritical, sizeof(SysErrCritical))
#define SystemError_Mild_Popup_Page SaveToUART_TxBuffer(SysErrMild, sizeof(SysErrMild))
#define SysError_Shutdown_Page SaveToUART_TxBuffer(SysError_shutdown,sizeof(SysError_shutdown))
#define ModeChangeOFF_Page SaveToUART_TxBuffer(modeChange_Lock,sizeof(modeChange_Lock))
#define SysError_StopDrive_Page SaveToUART_TxBuffer(SysError_SafeStop,sizeof(SysError_SafeStop))

#define NormalMode_Popup_Page SaveToUART_TxBuffer(Normal, sizeof(Normal))
#define NormalMode_Popup SaveToUART_TxBuffer(NormalPopUp, sizeof(NormalPopUp))
#define NormalMode_Icon SaveToUART_TxBuffer(NormalON, sizeof(NormalON))

#define EcoMode_Popup_Page SaveToUART_TxBuffer(Eco, sizeof(Eco))
#define EcoMode_Popup SaveToUART_TxBuffer(EcoPopUp, sizeof(EcoPopUp))
#define EcoMode_Icon SaveToUART_TxBuffer(EcoON, sizeof(EcoON))

#define SportMode_Popup_Page SaveToUART_TxBuffer(Sport, sizeof(Sport))
#define SportMode_Popup SaveToUART_TxBuffer(SportPopUp, sizeof(SportPopUp))
#define SportMode_Icon SaveToUART_TxBuffer(SportON, sizeof(SportON))

#define ModeClear_Icon SaveToUART_TxBuffer(modeClear, sizeof(modeClear))
#define popUp_OFF SaveToUART_TxBuffer(popOff, sizeof(popOff))

#define L_Signal_ON_Icon SaveToUART_TxBuffer(LeftSignalON, sizeof(LeftSignalON))
#define L_Signal_OFF_Icon SaveToUART_TxBuffer(LeftSignalOFF, sizeof(LeftSignalOFF))
#define R_Signal_ON_Icon SaveToUART_TxBuffer(RightSignalON, sizeof(RightSignalON))
#define R_Signal_OFF_Icon SaveToUART_TxBuffer(RightSignalOFF, sizeof(RightSignalOFF))

#define HighBeam_ON_Icon SaveToUART_TxBuffer(HighBeamON, sizeof(HighBeamON))
#define HighBeam_OFF_Icon SaveToUART_TxBuffer(HighBeamOFF, sizeof(HighBeamOFF))
#endif

void transmitPageHandler(uint8_t *page, uint8_t pageSize) {
	HAL_UART_AbortTransmit(&huart3);
	HAL_UART_Transmit_DMA(&huart3, page, pageSize);
}

void fireModePage(void) {
	HAL_UART_Transmit(&huart3, firePage, sizeof(firePage),
	HAL_MAX_DELAY);
}

void fireData(void) {
	//return;
}

void transmit() {
	_transmit_Function++;
	//if (_transmit_Function == 1) {
		if (_realTimeData) {
			realTimeData();
			_realTimeData = false;
			//return;
		}
	//}

	//if (_transmit_Function == 1) {
		if (_oneTimeData) {
			oneTimeData();
			_oneTimeData = false;
			//return;
	//	}
	}

	//if (_transmit_Function == 2) {
		if (_startingUp) {
			_startingUp = false;
			startingUp();
			//return;
		}
	//}

	//if (_transmit_Function == 3) {
		if (_gearChanged) {
			_gearChanged = false;
			gearUpdate();
			return;
		}
	//}

	//if (_transmit_Function == 4) {
		//_transmit_Function = 0;
		if (_modeSelection == 1 && currentstate == 2) {
			modeSelection(currentMode);
			_modeSelection = 0;
			return;
		}
		if (_modeSelection == 2) {
			_modeSelection = 0;
			modeSelection(modeCleared);
			if (_modeChangeDisabled) {
				_setPoup = true;
				_modeChangeDisabled = false;
				//_transmit_Function = 6;
				popUpNumber = 5;
			}
		}
	//}

	//if (_transmit_Function == 5) {
		if (currentStateSM == driving_state && _setDriverPage == true && !_setPoup) {
			_setDriverPage = false;
			drivePageSetter(_drivePageSet);
			return;
		}

	//}

	if (_transmit_Function == 6) {
		_transmit_Function = 0;
		popUpCounter++;
		if (popUpCounter > 20) {
			popUpCounter = 0;
			popUpNumber = 0;
			if (inPopup) {
				_setPoup = true;
			}
		}
		//_setPoup and Popup Number should be set from else where
		if (_setPoup) {
			_setPoup = false;
			//HAL_UART_AbortTransmit(&huart3);
			popUpHandler();
		}

	}

	if (_errorSetIcon) {
		errorIcon();
	}

	if (_errorSetPopup && !_errorClear) {
		errorCode();
		errorPopup();
	}

	if (_charingState) {
		_charingState = false;
		if (_transmit_Function == 3) {
			_transmit_Function = 0;
		}

		if (_chargingUI) {
			charging_UI(charging_ui);
			_chargingUI = false;
			_trasmitGlobal = 2;
			return;
		}
		if (_chargeComplete) {
			charging_UI(chargingcomp_ui);
			_chargeComplete = false;
			_trasmitGlobal = 3;
			return;
		}
	}
}

void startingUp(void) {

	if (error_check) {
		if (err_State_Navigation == true) {
			SysError_Shutdown_Page;
		}
	}

	if (entry == true) {
		if (_navigation) {
			if (_trasmitGlobal == MainMenuPages) {
				drivePageSetter(_drivePageSet);
				return;
			}
			_trasmitGlobal = MainMenuPages;
			Disengage_KillSwitch_Page;
			_navigation = false;
			return;
		}
//		if (_trasmitGlobal == PressBrakePage && warning == 0) {
//			return;
//		}
//		_trasmitGlobal = PressBrakePage;
		Press_Brake_Page;

	}

	if (start == 1) {
		entry = false;
		//If start is set by EVCU, Then run this Gimmick Part//
		if (checklit == true) {
			//bootAnimation();
			checklit = false;
		}

		if (readytodrive == 1) {
			ReadytoDrive_ON_Icon;
			//If ready to drive is ok, Then run this Gimmick Part//
			if (startup == true) {
				//ReadytoDrive_Page;
#ifdef Queue
		SaveToUART_TxBuffer(testData_Page, sizeof(testData_Page));
#endif
				_testPage = true;
				startup = false;
			}
		} else {
			System_Check_Okay_No_Icon_Page;
		}

		/////////////////////////////////////////////////////////
		if (chargerconn == 1) {
			Charge_Connection_Error_Popup_ON;
		} else {
			Charge_Connection_Error_Popup_OFF;
		}
		/////////////////////////////////////////////////////////

	} else { //if Start == 0//
//		if (mode) {
//			startupModeChange(); //Show Tuk Page as Mode Change Unavailable
//			//Final: Mode Change unavailable before ignition
//			mode = false;
//		}
		if (warning == 1) {
			Press_Brake_Page;
		}
		if (warning == 2) {
			Mild_Error_ON_Icon;
		}
		if (warning == 3) {
			Gear_Error_Page;

		}
	}

}




uint8_t drivePageTransmit = 0;


void drivePageSetter(uitype_t page) {
	drivePageTransmit++;
	switch (page) {
	case front:
		//Checking for Errors
		if (error_check) {
			if (accessory == 1) {
				if (drivePageTransmit == 1) {
					ReadytoDrive_OFF_Icon;
				}
				if (drivePageTransmit == 2) {
					ModeClear_Icon;
				}
				if (drivePageTransmit == 3) {
					PowerLimitON_Icon;
					drivePageTransmit = 0;
				}

			}
			//Ready to drive icon
			if (err_State_Navigation == true) {
//				if (_trasmitGlobal == 10) {
//					return;
//				}
//				_trasmitGlobal = 10;
				if (drivePageTransmit == 1) {
					SysError_Shutdown_Page;
					drivePageTransmit = 0;
				}

			}

			if (currentStateSM == driving_state) {
				if (shutdown == 1) {
					if (drivePageTransmit == 1) {
						SysError_StopDrive_Page;
						drivePageTransmit = 0;
					}

				}
				if (shutdown == 0) {
					if (mode) {
						if (drivePageTransmit == 1) {
							ModeChangeOFF_Page;
							drivePageTransmit = 0;
						}

						mode = false;
					} else {
						if (drivePageTransmit == 1) {
							SysError_StopDrive_Page;
							drivePageTransmit = 0;
						}

					}
				}
			}

			//If there is no Error
		} else {
			//Check for Accessory
			if (accessory == 1) {
				if (drivePageTransmit == 1) {
					ReadytoDrive_OFF_Icon;
				}
				if (drivePageTransmit == 2) {
					ModeClear_Icon;
				}

				if (drivePageTransmit == 3) {
					Disengage_KillSwitch_Page;
					drivePageTransmit = 0;
				}

			}
			if (_testPage) {
				//if (drivePageTransmit == 4) {
				_testPage = false;
				//HAL_UART_Transmit(&huart3, testData_Page, sizeof(testData_Page), HAL_MAX_DELAY);
				//drivePageTransmit = 0;
				//}
#ifdef Queue
		SaveToUART_TxBuffer(testData_Page, sizeof(testData_Page));
#endif
			}
		}
		break;
	case trip:
		if (_menupage == 1) {
			return;
		}
		_menupage = 1;
		Trip_Summary_Page;
		break;
	case after_charge:
		if (_menupage == 2) {
			return;
		}
		_menupage = 2;
		After_Charge_Page;
		break;
	case info:
		if (_menupage == 3) {
			return;
		}
		_menupage = 3;
		//Add info pages of inverter, Motor
		Vehicle_Info_Page;
		break;
	case settings:
		if (_menupage == 4) {
			return;
		}
		_menupage = 4;
		Vehicle_Settings_Page;
		break;
	default:
		break;

	}

}


void realTimeData(void) { //Realtime updatable data sending
// Priority Level 1
	priorityLevel1_counter++;
//Speed
	if (priorityLevel1_counter == 1) {
		strDATA[4] = 0x11; //
		strDATA[5] = 0x00; //
		strDATA[7] = (test_speed & 0xFF);
		strDATA[6] = (test_speed >> 8);
#ifdef Queue
		SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif

#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

//RPM
	if (priorityLevel1_counter == 2) {
		strDATA[4] = 0x12;
		strDATA[5] = 0x50;
		strDATA[7] = (rpm_meter & 0xFF);
		strDATA[6] = (rpm_meter >> 8);
#ifdef Queue
		SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

//Power Bar
	if (priorityLevel1_counter == 3) {
#ifdef No_DMA
		powerMeter();
#endif
#ifdef Queue
		powerMeterQueue();
#endif
	}
//DC Current
	if (priorityLevel1_counter == 4) {
		priorityLevel1_counter = 0;
		realTime_counter++;
		if (realTime_counter == 1) {
			if (currentstate == 4) {
				strDATA[4] = 0x12;
				strDATA[5] = 0x80;
			} else {
				strDATA[4] = 0x12;
				strDATA[5] = 0x30;
			}
			strDATA[6] = (dc_current >> 8);
			strDATA[7] = (dc_current & 0xFF);
#ifdef Queue
			SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
		}

//Lowest Cell Voltage
		if (realTime_counter == 2) {
			strDATA[4] = 0x12;
			strDATA[5] = 0x20;
			strDATA[7] = (lcell_voltage & 0xFF);
			strDATA[6] = (lcell_voltage >> 8);
#ifdef Queue
			SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
		}

////Trip
		if (realTime_counter == 3) {
			strDATA2[4] = 0x11;
			strDATA2[5] = 0x40;
			strDATA2[9] = (distance.trip & 0xFF);
			strDATA2[8] = (distance.trip >> 8);
			strDATA2[7] = (distance.trip >> 16);
			strDATA2[6] = (distance.trip >> 24);
#ifdef Queue
			SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA2;
#endif
		}
//Power
		if (realTime_counter == 4) {
			realTime_counter = 0;
			if (currentstate == 4) {
				strDATA[4] = 0x12;
				strDATA[5] = 0x60;
			} else {
				strDATA[4] = 0x11;
				strDATA[5] = 0x70;
			}
			strDATA[7] = (power & 0xFF);
			strDATA[6] = (power >> 8);
#ifdef Queue
			SaveToUART_TxBuffer(strDATA, sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
		}
	}
}


void oneTimeData(void) {

// Priority Level 2
	priorityLevel2_counter++;
	if (readytodrive == 0) {
		///DriveUnit_OFF_Icon;
	} else {
		//DriveUnit_ON_Icon;
	}

//ODO
	if (priorityLevel2_counter == 1) {
		if (realTime_counter == 2) {
			strDATA2[4] = 0x11;
			strDATA2[5] = 0x20;
			strDATA2[9] = (distance.ODO & 0xFF);
			strDATA2[8] = (distance.ODO >> 8);
			strDATA2[7] = (distance.ODO >> 16);
			strDATA2[6] = (distance.ODO >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA2,sizeof(strDATA2));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
		}
	}

//Pack voltage
	if (priorityLevel2_counter == 2) {
		if (currentstate == 4) {
			strDATA[4] = 0x12;
			strDATA[5] = 0x10;
		} else {
			strDATA[4] = 0x12;
			strDATA[5] = 0x10;
		}
		strDATA[7] = (pack_voltage & 0xFF);
		strDATA[6] = (pack_voltage >> 8);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

//Highest Cell Voltage
	if (priorityLevel2_counter == 3) {
		strDATA[4] = 0x12;
		strDATA[5] = 0x70;
		strDATA[7] = (hcell_voltage & 0xFF);
		strDATA[6] = (hcell_voltage >> 8);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

//Estimated Range
	if (priorityLevel2_counter == 4) {
		strDATA[4] = 0x11;
		strDATA[5] = 0x30;
		//strDATA[7] = uint32_t(distance.range);
		//strDATA[6] = 0;
		strDATA[7] = (distance.range & 0xFF);
		strDATA[6] = (distance.range >> 8);
		//strDATA[7] = (distance.range >> 16);
		//strDATA[6] = (distance.range >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

////Range
//	if (priorityLevel2_counter == 5) {
//		strDATA[4] = 0x11;
//		strDATA[5] = 0x30;
//		strDATA[7] = (distance.range);
//		strDATA[6] = 0;
//#ifdef Queue
//	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
//#endif
//#ifdef No_Queue
//	Transmit_strDATA;
//#endif
//	}
//SOC - Battery Percentage
	if (priorityLevel2_counter == 5) {
		strDATA[4] = 0x11;
		strDATA[5] = 0x10;
		strDATA[7] = (soc_value);
		strDATA[6] = 0;
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

	}
	if (priorityLevel2_counter == 6) {
#ifdef No_DMA
		batteryBar();
#endif
#ifdef Queue
		batteryBarQueue();
#endif
	}
	//AVG SPEED
	if (priorityLevel2_counter == 7) {
		priorityLevel2_counter = 0;
		strDATA[4] = 0x11;
		strDATA[5] = 0x52;
		strDATA[7] = (distance.tripAvgSpeed & 0xFF);
		strDATA[6] = (distance.tripAvgSpeed >> 8);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}



// Priority Level 3

	if (_After_Charge_Page) {
		_After_Charge_Page = false;
		//After charge trip
		strDATA[4] = 0x11;
		strDATA[5] = 0x62;
		strDATA[7] = (afterChargeData.trip & 0xFF);
		strDATA[6] = (afterChargeData.trip >> 8);
		//	strDATA[7] = (afterChargeData.trip >> 16);
		//	strDATA[6] = (afterChargeData.trip >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

// After charge average speed
		strDATA[4] = 0x11;
		strDATA[5] = 0x58;
		strDATA[7] = (afterChargeData.avarage_Speed & 0xFF);
		strDATA[6] = (afterChargeData.avarage_Speed >> 8);
		//	strDATA[7] = (afterChargeData.avarage_Speed >> 16);
		//	strDATA[6] = (afterChargeData.avarage_Speed >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

// After Charge Economy
		strDATA[4] = 0x11;
		strDATA[5] = 0x56;
		strDATA[7] = (afterChargeData.economy & 0xFF);
		strDATA[6] = (afterChargeData.economy >> 8);
		//	strDATA[7] = (afterChargeData.economy >> 16);
		//	strDATA[6] = (afterChargeData.economy >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

// After charge Power
		strDATA[4] = 0x11;
		strDATA[5] = 0x60;
		strDATA[7] = (afterChargeData.power & 0xFF);
		strDATA[6] = (afterChargeData.power >> 8);
		//	strDATA[7] = (afterChargeData.power >> 16);
		//	strDATA[6] = (afterChargeData.power >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif
	}

	if (_Trip_Summary_Page) {
		_Trip_Summary_Page = false;
//Trip Economy -------VP
		strDATA[4] = 0x11;
		strDATA[5] = 0x50;
		strDATA[7] = (distance.trip_Economy & 0xFF);
		strDATA[6] = (distance.trip_Economy >> 8);
		//	strDATA[7] = (distance.trip_Economy >> 16);
		//	strDATA[6] = (distance.trip_Economy >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

//Trip Power----------VP

		strDATA[4] = 0x11;
		strDATA[5] = 0x54;
		strDATA[7] = (distance.trip_Power & 0xFF);
		strDATA[6] = (distance.trip_Power >> 8);
		//	strDATA[7] = (distance.trip_Power >> 16);
		//	strDATA[6] = (distance.trip_Power >> 24);
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif
#ifdef No_Queue
	Transmit_strDATA;
#endif

	}

	if (_Battery_Info_Page) {
		//SOH Battery Health
		strDATA[4] = 0x11;
		strDATA[5] = 0x66;
		strDATA[7] = (soh_value);
		strDATA[6] = 0;
#ifdef Queue
	SaveToUART_TxBuffer(strDATA,sizeof(strDATA));
#endif

#ifdef No_Queue
	Transmit_strDATA;
#endif


	}

	if (_Motor_Info_Page) {

	}

	if (_Inverter_Info_Page) {

	}





	//Battery Data
	//if (oneTime_counter == 10) {

//	switch (transferCount) {
//	case 1: //SOC - Battery Percentage
//		strDATA[4] = 0x11;
//		strDATA[5] = 0x10;
//		strDATA[7] = (soc_value);
//		strDATA[6] = 0;
//		Transmit_strDATA;
//		break;
//	case 2:  //Pack voltage
//		if (currentstate == 4) {
//			strDATA[4] = 0x12;
//			strDATA[5] = 0x10;
//		} else {
//			strDATA[4] = 0x12;
//			strDATA[5] = 0x10;
//		}
//		strDATA[7] = (pack_voltage & 0xFF);
//		strDATA[6] = (pack_voltage >> 8);
//		Transmit_strDATA;
//		break;
//	case 3:  //Lowest Cell Voltage
//		strDATA[4] = 0x12;
//		strDATA[5] = 0x20;
//		strDATA[7] = (lcell_voltage & 0xFF);
//		strDATA[6] = (lcell_voltage >> 8);
//		Transmit_strDATA;
//		break;
//	case 4:  //DC Current
//		if (currentstate == 4) {
//			strDATA[4] = 0x12;
//			strDATA[5] = 0x80;
//		} else {
//			strDATA[4] = 0x12;
//			strDATA[5] = 0x30;
//		}
//		strDATA[6] = (dc_current >> 8);
//		strDATA[7] = (dc_current & 0xFF);
//		Transmit_strDATA;
//		break;
//	case 5:  //Pack Temperature
//		strDATA[4] = 0x12;
//		strDATA[5] = 0x40;
//		strDATA[6] = (pack_temp >> 8);
//		strDATA[7] = (pack_temp & 0xFF);
//		Transmit_strDATA;
//		strDATA[4] = 0x11;
//		strDATA[5] = 0x68;
//		Transmit_strDATA;
//		break;
//	case 6:  //Highest Cell Voltage
//		strDATA[4] = 0x12;
//		strDATA[5] = 0x70;
//		strDATA[7] = (hcell_voltage & 0xFF);
//		strDATA[6] = (hcell_voltage >> 8);
//		Transmit_strDATA;
//		break;
//	case 7:  //SOH Battery Health
//		strDATA[4] = 0x11;
//		strDATA[5] = 0x66;
//		strDATA[7] = (soh_value);
//		strDATA[6] = 0;
//		Transmit_strDATA;
//		break;
//	case 8:  //Estimated Range
//		strDATA[4] = 0x11;
//		strDATA[5] = 0x30;
//		//strDATA[7] = uint32_t(distance.range);
//		//strDATA[6] = 0;
//		strDATA[7] = (distance.range & 0xFF);
//		strDATA[6] = (distance.range >> 8);
//		//strDATA[7] = (distance.range >> 16);
//		//strDATA[6] = (distance.range >> 24);
//		Transmit_strDATA;
//		break;
//	default:
//		break;
//	}

//	transferCount++;
//	if (transferCount >= 9) {
//		transferCount = 1;
//	}

}



void vehicleInfo_UI(uitype_t InfoUI) {
	switch (InfoUI) {
	case infobat:
		Battery_Info_Page;
		break;
	case infomot:
		Motor_Info_Page;
		break;
	case infoinv:
		Inverter_Info_Page;
		break;
	default:
		break;
	}
}

void charging_UI(uitype_t ChargeUI) {
	switch (ChargeUI) {
	case charging_ui:
		Charging_Page;
		break;
	case chargingcomp_ui:
		ChargeComplete_Page;
		break;
	case chargingerr_ui:
		Charge_Error_Page;
		//HAL_Delay(1000);
		if (charge_error) {
			Charge_Connection_Error_Popup_ON;
		}
		break;
	default:
		break;
	}
}

void settings_UI(uitype_t SettingsMenu, uint8_t selectedOption) {
	switch (SettingsMenu) {
	case vehicleMenu:
		General_Menu_Page;
		break;
	case systemMenu:
		System_Menu_Page;
		if(timeChanged)
		{
			timeChanged = false;
			timeSet[11] = timerSetValueH;
			timeSet[12] = timerSetValueMin;
			HAL_UART_Transmit(&huart3, timeSet, sizeof(timeSet), HAL_MAX_DELAY);
		}
		if(selectedOption == 0) {
			TimeSetting_Button;
			BrightnessSetting_Button_OFF;

			selectedOption = 10;
		}
		if(selectedOption == 1)
		{
			BrightnessSetting_Button;
			TimeSetting_Button_OFF;
			selectedOption = 10;
		}
		if (selectedOption == 4) {
			strDATA[4] = 0x13;
			strDATA[5] = 0x22;
			strDATA[6] = 0;
			strDATA[7] = (timerSetValueH);
			Transmit_strDATA;
		}
		if (selectedOption == 3) {
			strDATA[4] = 0x13;
			strDATA[5] = 0x21;
			strDATA[6] = 0;
			strDATA[7] = (timerSetValueMin);
			Transmit_strDATA;
		}

		break;
	case bluetoothMenu:
		Bluetooth_Menu_Page;
		break;
	case errorsMenu:
		//To get the error log from the EVCU
		errorRead = 1; //To get the error log from the EVCU
		//Set canTX bits to send current page is error log page
		////Debug///
//		if (byteIndex < 10) {
//			for (byteIndex; byteIndex < 10; byteIndex += 1) {
//				for (int j = 2; j < 8; j++) {
//					errLog[byteIndex][j] = canRX[j];
//				}
//			}
//		}
		////////////////////////
		Error_Menu_Page; //Display the Error Log
		break;
	default:
		break;
	}
}

void selection_UI(uitype_t SettingsMenu) {
	Vehicle_Settings_Page;
	switch (SettingsMenu) {
	case vehicleMenu:
		Vehicle_Button;
		break;
	case systemMenu:
		System_Button;
		break;
	case bluetoothMenu:
		Bluetooth_Button;
		break;
	case errorsMenu:
		Error_Button;
		break;
	default:
		NO_Button;
		break;
	}
}

void resetThings(void) {
	Trip_Reset;
	tripreset = false;
}

void timeStampSend(void) { //Add time interrupts to send data. Set Priority lower than canRX
	HAL_UART_Transmit_DMA(&huart3, readTime, sizeof(readTime));
	HAL_UART_Receive_DMA(&huart3, usartRX, sizeof(usartRX));

	t.tm_year = (usartRX[7] + 100); //Year
	t.tm_mon = (usartRX[8] - 1); //Month
	t.tm_mday = usartRX[9]; //Day
	t.tm_hour = usartRX[11]; //Hours
	t.tm_min = usartRX[12]; //Minutes
	t.tm_sec = usartRX[13]; //Seconds
	t.tm_isdst = -1; // DST-Daylight Saving Time -> 1 = Yes, 0 = No, -1 = Unknown
	t_of_day = mktime(&t); //Time of Day
}

void timeStampReceive(void) {
	ts = *localtime(&rawtime);
	strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S %Z", &ts); //Year-Month-Day-Hours-Minutes-Seconds
	return;
}

void errorIcon(void) {

	if (error_on == true) {
		Error_ON_Icon;
	} else {
		Error_OFF_Icon;
	}
	if (milderror_on == true) {
		Mild_Error_ON_Icon;
	} else {
		Mild_Error_OFF_Icon;
	}
	if (service_on == true) {
		Service_Error_ON_Icon;
	} else {
		Service_Error_OFF_Icon;
	}
	if (bat_temp_high == true) {
		Battery_High_Temp_Popup_ON;
	} else {
		Battery_High_Temp_Popup_OFF;
	}
	if (aux_low_on == true) {
		Battery_ON_Icon;
	} else {
		Battery_OFF_Icon;
	}
}

void errorPopup(void) {
	if (err_crit_mild == 1) {
		SystemError_Critical_Popup;

	} else {
		SystemError_Mild_Popup_Page;
	}
}

void errorCode(void) {

	strDATA[4] = 0x11; //System Error Mild
	strDATA[5] = 0x94;
	strDATA[6] = 0;
	strDATA[7] = (err_error);
	Transmit_strDATA;

	strDATA[4] = 0x11; //System Error Critical
	strDATA[5] = 0x97;
	Transmit_strDATA;

	strDATA[4] = 0x11; //System Error Mild
	strDATA[5] = 0x95;
	strDATA[6] = 0;
	strDATA[7] = (err_device);
	Transmit_strDATA;

	strDATA[4] = 0x11; //System Error Critical
	strDATA[5] = 0x98;
	Transmit_strDATA;

	strDATA[4] = 0x11; //System Error Mild
	strDATA[5] = 0x96;
	strDATA[6] = 0;
	strDATA[7] = (err_crit_mild);
	Transmit_strDATA;

	strDATA[4] = 0x11; //System Error Critical
	strDATA[5] = 0x99;
	Transmit_strDATA;

}

void modeSelection(uimode_t currentMode) {
//	if (!_modeChanged) {
//		drivePageSetter(currentPage);
//	}
	if (currentMode == modeCleared) {
		ModeClear_Icon;
		return;
	}
//	mode_count++;
//	//Mode set pop-up timer
//	if (mode_count > 15) {
//		rtn = true;
//		mode_count = 0;
//	}

	switch (currentMode) {
	case normalMode:
		if (modeIcon) {
			NormalMode_Icon;
			modeIcon = false;
		}
		//NormalMode_Popup;

		break;
	case ecoMode:
			//EcoMode_Popup;

		if (mode_evcu == 1) {
			PowerLimitON_Icon;
		} else {
			PowerLimitOFF_Icon;
		}

		if (modeIcon) {
			modeIcon = false;
			EcoMode_Icon;
		}
//		if (mode_override == 1) {
//						ModeChangeOFF_Page;
//						return;
//
//		}

		break;
	case sportMode:
		if (modeIcon) {
			modeIcon = false;
			SportMode_Icon;
		}
		if (_modeChanged) {
			//SportMode_Popup;
			_modeChanged = false;
		}
		break;
	default:
		break;
	}
}

void popUpHandler(void) {
	//Set popup priority Here

	switch (popUpNumber) {
	case 0:
		popUp_OFF;
		//Battery_High_Temp_Popup_OFF;
		inPopup = false;
		break;
	case 1:
		NormalMode_Popup;
		//Battery_High_Temp_Popup_ON;
		inPopup = true;
		break;
	case 2:
		EcoMode_Popup;
		//Battery_High_Temp_Popup_ON;
		inPopup = true;
		break;
	case 3:
		SportMode_Popup;
		//Battery_High_Temp_Popup_ON;
		inPopup = true;
		break;
	case 4:
		ModeChangeOFF_Page;
		inPopup = true;
		break;
	case 5:
		//ModeChangeOFF_Page;
#ifdef No_DMA
	HAL_UART_Transmit(&huart3, Tuk, sizeof(Tuk),
	HAL_MAX_DELAY);
#endif
#ifdef Queue
	SaveToUART_TxBuffer(Tuk, sizeof(Tuk));
#endif
		inPopup = true;
		break;

	default:
		break;
	}

}

//When Mode change unavailable
//void modeChangeUnavailable() {
//#ifdef No_DMA
//	HAL_UART_Transmit(&huart3, Tuk, sizeof(Tuk),
//	HAL_MAX_DELAY);
//#endif
//#ifdef Queue
//	SaveToUART_TxBuffer(Tuk, sizeof(Tuk));
//#endif
//}

void sideMenuPopup(void) {
	if (soh_value <= 800) {
		Battery_SOH_LOW_Popup_ON;
	} else {
		Battery_LOW_Charge_Popup_OFF;
	}

	if (pack_temp >= 45) {
		Battery_High_Temp_Popup_ON;
	} else {
		Battery_High_Temp_Popup_OFF;
	}

	if (soc_value <= 20) {
		Battery_LOW20_Popup_ON;
		if (okay == true) {
			okay = false;
			Battery_LOW20_Popup_OFF;
		}
	}
	if (soc_value <= 12) {
		EcoMode_Icon;
		if (okay == true) {
			okay = false;
			//HAL_UART_Transmit(&huart3, SportMenuOFF, sizeof(SportMenuOFF),
			//HAL_MAX_DELAY);
			//drivePageSetter(currentPage);
		}
	}
	if (soc_value <= 8) {
		Battery_LOW_Charge_Popup_ON;
		if (okay == true) {
			okay = false;
			Battery_LOW_Charge_Popup_OFF;
		}

	}
}



void batteryBar(void) {

//Battery Bar
	if (soc_value <= 5) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat0, sizeof(bat0));
		HAL_UART_Transmit_DMA(&huart3, BotRedON, sizeof(BotRedON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat0, sizeof(bat0), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotRedON, sizeof(BotRedON), HAL_MAX_DELAY);
#endif

	}
	if (6 <= soc_value && soc_value <= 10) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat5, sizeof(bat5));
		HAL_UART_Transmit_DMA(&huart3, BotRedON, sizeof(BotRedON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat5, sizeof(bat5), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotRedON, sizeof(BotRedON), HAL_MAX_DELAY);
#endif
	}
	if (11 <= soc_value && soc_value <= 15) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat10, sizeof(bat10));
		HAL_UART_Transmit_DMA(&huart3, BotRedON, sizeof(BotRedON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat10, sizeof(bat10), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotRedON, sizeof(BotRedON), HAL_MAX_DELAY);
#endif
	}
	if (16 <= soc_value && soc_value <= 20) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat15, sizeof(bat15));
		HAL_UART_Transmit_DMA(&huart3, BotRedON, sizeof(BotRedON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat15, sizeof(bat15), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotRedON, sizeof(BotRedON), HAL_MAX_DELAY);
#endif
	}
	if (21 <= soc_value && soc_value <= 25) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat20, sizeof(bat20));
		HAL_UART_Transmit_DMA(&huart3, BotOrangeON, sizeof(BotOrangeON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat20, sizeof(bat20), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotOrangeON, sizeof(BotOrangeON),
		HAL_MAX_DELAY);
#endif
	}
	if (26 <= soc_value && soc_value <= 30) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat25, sizeof(bat25));
		HAL_UART_Transmit_DMA(&huart3, BotOrangeON, sizeof(BotOrangeON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat25, sizeof(bat25), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotOrangeON, sizeof(BotOrangeON),
		HAL_MAX_DELAY);
#endif
	}
	if (31 <= soc_value && soc_value <= 35) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat30, sizeof(bat30));
		HAL_UART_Transmit_DMA(&huart3, BotOrangeON, sizeof(BotOrangeON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat30, sizeof(bat30), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotOrangeON, sizeof(BotOrangeON),
		HAL_MAX_DELAY);
#endif
	}
	if (36 <= soc_value && soc_value <= 40) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat35, sizeof(bat35));
		HAL_UART_Transmit_DMA(&huart3, BotOrangeON, sizeof(BotOrangeON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat35, sizeof(bat35), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotOrangeON, sizeof(BotOrangeON),
		HAL_MAX_DELAY);
#endif
	}
	if (41 <= soc_value && soc_value <= 45) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat40, sizeof(bat40));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat40, sizeof(bat40), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (46 <= soc_value && soc_value <= 50) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat45, sizeof(bat45));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat45, sizeof(bat45), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (51 <= soc_value && soc_value <= 55) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat50, sizeof(bat50));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat50, sizeof(bat50), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (56 <= soc_value && soc_value <= 60) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat55, sizeof(bat55));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat55, sizeof(bat55), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (61 <= soc_value && soc_value <= 65) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat60, sizeof(bat60));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat60, sizeof(bat60), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (66 <= soc_value && soc_value <= 70) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat65, sizeof(bat65));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat65, sizeof(bat65), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (71 <= soc_value && soc_value <= 75) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat70, sizeof(bat70));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat70, sizeof(bat70), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (76 <= soc_value && soc_value <= 80) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat75, sizeof(bat75));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat75, sizeof(bat75), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (81 <= soc_value && soc_value <= 85) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat80, sizeof(bat80));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat80, sizeof(bat80), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (86 <= soc_value && soc_value <= 90) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat85, sizeof(bat85));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat85, sizeof(bat85), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (91 <= soc_value && soc_value <= 95) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat90, sizeof(bat90));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat90, sizeof(bat90), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (96 <= soc_value && soc_value <= 99) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat90, sizeof(bat90));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat90, sizeof(bat90), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
	if (100 == soc_value) {
#ifdef DMA
		HAL_UART_Transmit_DMA(&huart3, bat100, sizeof(bat100));
		HAL_UART_Transmit_DMA(&huart3, BotGreenON, sizeof(BotGreenON));
#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, bat100, sizeof(bat100), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart3, BotGreenON, sizeof(BotGreenON),
		HAL_MAX_DELAY);
#endif
	}
}

void batteryBarQueue(void) {
	if (soc_value <= 5) {

		SaveToUART_TxBuffer(bat0, sizeof(bat0));
		SaveToUART_TxBuffer(BotRedON, sizeof(BotRedON));

	}
	if (6 <= soc_value && soc_value <= 10) {

		SaveToUART_TxBuffer(bat5, sizeof(bat5));
		SaveToUART_TxBuffer(BotRedON, sizeof(BotRedON));

	}
	if (11 <= soc_value && soc_value <= 15) {

		SaveToUART_TxBuffer(bat10, sizeof(bat10));
		SaveToUART_TxBuffer(BotRedON, sizeof(BotRedON));

	}
	if (16 <= soc_value && soc_value <= 20) {

		SaveToUART_TxBuffer(bat15, sizeof(bat15));
		SaveToUART_TxBuffer(BotRedON, sizeof(BotRedON));

	}
	if (21 <= soc_value && soc_value <= 25) {

		SaveToUART_TxBuffer(bat20, sizeof(bat20));
		SaveToUART_TxBuffer(BotOrangeON, sizeof(BotOrangeON));

	}
	if (26 <= soc_value && soc_value <= 30) {
		SaveToUART_TxBuffer(bat25, sizeof(bat25));
		SaveToUART_TxBuffer(BotOrangeON, sizeof(BotOrangeON));

	}
	if (31 <= soc_value && soc_value <= 35) {
		SaveToUART_TxBuffer(bat30, sizeof(bat30));
		SaveToUART_TxBuffer(BotOrangeON, sizeof(BotOrangeON));
	}
	if (36 <= soc_value && soc_value <= 40) {
		SaveToUART_TxBuffer(bat35, sizeof(bat35));
		SaveToUART_TxBuffer(BotOrangeON, sizeof(BotOrangeON));
	}
	if (41 <= soc_value && soc_value <= 45) {

		SaveToUART_TxBuffer(bat40, sizeof(bat40));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (46 <= soc_value && soc_value <= 50) {
		SaveToUART_TxBuffer(bat45, sizeof(bat45));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (51 <= soc_value && soc_value <= 55) {

		SaveToUART_TxBuffer(bat50, sizeof(bat50));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (56 <= soc_value && soc_value <= 60) {
		SaveToUART_TxBuffer(bat55, sizeof(bat55));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (61 <= soc_value && soc_value <= 65) {
		SaveToUART_TxBuffer(bat60, sizeof(bat60));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (66 <= soc_value && soc_value <= 70) {
		SaveToUART_TxBuffer(bat65, sizeof(bat65));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (71 <= soc_value && soc_value <= 75) {
		SaveToUART_TxBuffer(bat70, sizeof(bat70));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (76 <= soc_value && soc_value <= 80) {

		SaveToUART_TxBuffer(bat75, sizeof(bat75));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (81 <= soc_value && soc_value <= 85) {

		SaveToUART_TxBuffer(bat80, sizeof(bat80));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (86 <= soc_value && soc_value <= 90) {

		SaveToUART_TxBuffer(bat85, sizeof(bat85));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (91 <= soc_value && soc_value <= 95) {

		SaveToUART_TxBuffer(bat90, sizeof(bat90));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (96 <= soc_value && soc_value <= 99) {

		SaveToUART_TxBuffer(bat90, sizeof(bat90));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));
	}
	if (100 == soc_value) {

		SaveToUART_TxBuffer(bat100, sizeof(bat100));
		SaveToUART_TxBuffer(BotGreenON, sizeof(BotGreenON));

	}
}

void powerMeter(void) {

	if (rpm_meter == 0) {
#ifdef DMA
			HAL_UART_Transmit_DMA(&huart3, eco0, sizeof(eco0));
	#endif
#ifdef No_DMA
		HAL_UART_Transmit(&huart3, eco0, sizeof(eco0), HAL_MAX_DELAY);
#endif
	}

	if (rpm_meter >= 1) {

		if (power_90 <= power) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, power5, sizeof(power5));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, power5, sizeof(power5),
			HAL_MAX_DELAY);
#endif
		}

		if (power_80 <= power && power < power_90) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, power4, sizeof(power4));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, power4, sizeof(power4),
			HAL_MAX_DELAY);
#endif
		}

		if (power_70 <= power && power < power_80) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, power3, sizeof(power3));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, power3, sizeof(power3),
			HAL_MAX_DELAY);
#endif
		}

		if (power_60 <= power && power < power_70) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, power2, sizeof(power2));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, power2, sizeof(power2),
			HAL_MAX_DELAY);
#endif
		}

		if (eco_50 <= power && power < power_60) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, power1, sizeof(power1));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, power1, sizeof(power1),
			HAL_MAX_DELAY);
#endif
		}

		if (eco_40 <= power && power < eco_50) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, eco5, sizeof(eco5));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, eco5, sizeof(eco5),
			HAL_MAX_DELAY);
#endif
		}

		if (eco_30 <= power && power < eco_40) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, eco4, sizeof(eco4));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, eco4, sizeof(eco4),
			HAL_MAX_DELAY);
#endif
		}

		if (eco_20 <= power && power < eco_30) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, eco3, sizeof(eco3));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, eco3, sizeof(eco3),
			HAL_MAX_DELAY);
#endif
		}

		if (eco_10 <= power && power < eco_20) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, eco2, sizeof(eco2));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, eco2, sizeof(eco2),
			HAL_MAX_DELAY);
#endif
		}

		if (0 <= power && power < eco_10) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, eco1, sizeof(eco1));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, eco1, sizeof(eco1),
			HAL_MAX_DELAY);
#endif
		}

		if (-1 >= power && power >= -50) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, charge1, sizeof(charge1));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, charge1, sizeof(charge1),
			HAL_MAX_DELAY);
#endif
		}

		if (-51 >= power && power >= -101) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, charge2, sizeof(charge2));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, charge2, sizeof(charge2),
			HAL_MAX_DELAY);
#endif
		}

		if (-102 >= power && power >= -152) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, charge3, sizeof(charge3));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, charge3, sizeof(charge3),
			HAL_MAX_DELAY);
#endif
		}

		if (-153 >= power && power >= -203) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, charge4, sizeof(charge4));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, charge4, sizeof(charge4),
			HAL_MAX_DELAY);
#endif
		}

		if (-204 >= power) {
#ifdef DMA
				HAL_UART_Transmit_DMA(&huart3, charge5, sizeof(charge5));
#endif
#ifdef No_DMA
			HAL_UART_Transmit(&huart3, charge5, sizeof(charge5),
			HAL_MAX_DELAY);
#endif
		}
	}

}
void powerMeterQueue(void) {
	if (rpm_meter == 0) {

		SaveToUART_TxBuffer(eco0, sizeof(eco0));

	}

	if (rpm_meter >= 1) {

		if (power_90 <= power) {
			SaveToUART_TxBuffer(power5, sizeof(power5));
		}

		if (power_80 <= power && power < power_90) {
			SaveToUART_TxBuffer(power4, sizeof(power4));
		}

		if (power_70 <= power && power < power_80) {
			SaveToUART_TxBuffer(power3, sizeof(power3));
		}

		if (power_60 <= power && power < power_70) {
			SaveToUART_TxBuffer(power2, sizeof(power2));
		}
		if (eco_50 <= power && power < power_60) {
			SaveToUART_TxBuffer(power1, sizeof(power1));
		}

		if (eco_40 <= power && power < eco_50) {
			SaveToUART_TxBuffer(eco5, sizeof(eco5));
		}
		if (eco_30 <= power && power < eco_40) {
			SaveToUART_TxBuffer(eco4, sizeof(eco4));
		}

		if (eco_20 <= power && power < eco_30) {
			SaveToUART_TxBuffer(eco3, sizeof(eco3));
		}
		if (eco_10 <= power && power < eco_20) {
			SaveToUART_TxBuffer(eco2, sizeof(eco2));
		}

		if (0 <= power && power < eco_10) {
			SaveToUART_TxBuffer(eco1, sizeof(eco1));
		}

		if (-1 >= power && power >= -50) {
			SaveToUART_TxBuffer(charge1, sizeof(charge1));
		}

		if (-51 >= power && power >= -101) {
			SaveToUART_TxBuffer(charge2, sizeof(charge2));
		}

		if (-102 >= power && power >= -152) {
			SaveToUART_TxBuffer(charge3, sizeof(charge3));
		}

		if (-153 >= power && power >= -203) {
			SaveToUART_TxBuffer(charge4, sizeof(charge4));
		}

		if (-204 >= power) {
			SaveToUART_TxBuffer(charge5, sizeof(charge5));
		}
	}
}


void gearUpdate(void) {
	if (currentstate == 1) {
		Gear_Neutral_Icon;
	}

	if (currentstate == 2) {
		Gear_Drive_Icon;
	}

	if (currentstate == 3) {
		Gear_Reverse_Icon;
	}
	if (_gearCleared || currentstate == 0) {
		Gear_Clear_Icon;
		_gearCleared = false;
	}

}

void bootAnimation() {

	HAL_UART_Transmit(&huart3, SysCheck_lit_IconAll,
			sizeof(SysCheck_lit_IconAll),
			HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, eco1, sizeof(eco1),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart1, sizeof(chargestart1),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco2, sizeof(eco2),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco3, sizeof(eco3),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart2, sizeof(chargestart2),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco4, sizeof(eco4),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco5, sizeof(eco5),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart3, sizeof(chargestart3),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power1, sizeof(power1),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power2, sizeof(power2),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart4, sizeof(chargestart4),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power3, sizeof(power3),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power4, sizeof(power4),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart5, sizeof(chargestart5),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power5, sizeof(power5),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power4, sizeof(power4),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power3, sizeof(power3),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart4, sizeof(chargestart4),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power2, sizeof(power2),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, power1, sizeof(power1),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart3, sizeof(chargestart3),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco5, sizeof(eco5),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco4, sizeof(eco4),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart2, sizeof(chargestart2),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco3, sizeof(eco3),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco2, sizeof(eco2),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart1, sizeof(chargestart1),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco1, sizeof(eco1),
	HAL_MAX_DELAY);
	HAL_Delay(50);
	HAL_UART_Transmit(&huart3, eco0, sizeof(eco0),
	HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, chargestart0, sizeof(chargestart0),
	HAL_MAX_DELAY);
	HAL_Delay(50);

	HAL_UART_Transmit(&huart3, SysCheck_Okay_NoIcon,
			sizeof(SysCheck_Okay_NoIcon),
			HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart3, ReadytoDrive_Icon_ON,
			sizeof(ReadytoDrive_Icon_ON),
			HAL_MAX_DELAY);
	HAL_Delay(500);
}

void indicators() {
	if (_L_Signal) {
		L_Signal_ON_Icon;
	} else {
		L_Signal_OFF_Icon;
	}
	if (_R_Signal) {
		R_Signal_ON_Icon;
	} else {
		R_Signal_OFF_Icon;
	}
	if (_highBeam) {
		HighBeam_ON_Icon;
	} else {
		HighBeam_OFF_Icon;
	}
}

