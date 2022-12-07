//#include <string.h>
//#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stm32f1xx_hal.h>
//#include <stm32f1xx_hal_uart.h>
//#include <usart.h>
//
//#define eco_10 101
//#define eco_20 201
//#define eco_30 301
//#define eco_40 401
//#define eco_50 501
//#define power_60 581
//#define power_70 662
//#define power_80 743
//#define power_90 821
//#define power_100 821
//
////TIME SET 5A A5 0B 82 00 9C 5A A5 12 06 1B 0D 08 00
//// 											H  M  S
//
////extern uint8_t realTime_counter = 0;
////extern uint8_t oneTime_counter = 0;
////extern uint8_t _transmit_Function = 0;
////extern uint8_t txTest = 0;
//
//extern uint8_t DisenKillSwitch[10]; //Page
//extern uint8_t PressBrake[10]; //Page
//
//extern uint8_t firePage[10]; //Page
//
//extern uint8_t GearErr[10]; //Page
//
//extern uint8_t SysCheck_lit_IconAll[10]; //Page
//extern uint8_t SysCheck_Okay_NoIcon[10]; //Page
//
//extern uint8_t ReadytoDrive[10]; //Page
//
//extern uint8_t TripSum[10]; //Page
//extern uint8_t AfterRecharge[10]; //Page
//
////System Info Menu
//extern uint8_t VehicleInfo[10]; //Page
//
//////With Press Back Button to Main Menu
//extern uint8_t VehicleInfoBat[10]; //Page
//
//extern uint8_t VehicleInfoMot[10]; //Page
//extern uint8_t VehicleInfoInv[10]; //Page
//
////Settings Pages
//extern uint8_t Settings[10]; //Page
//
//extern uint8_t Vehicle[10]; //Page
//
//extern uint8_t System[10]; //Page
//
//extern uint8_t Bluetooth[10]; //Page
//
//extern uint8_t Errors[10]; //Page
//
////////////////Error_Pages//////////////////////////////////////////////////
//extern uint8_t SysError_shutdown[10]; //Page
//extern uint8_t SysError_SafeStop[10]; //Page
//extern uint8_t ChargeError_Code[10]; //Page
//////////////////////////////////////////////////////////////////////////////////////
//extern uint8_t Tuk[10]; //Page
//
//extern uint8_t Charging[10]; //Page
//
//extern uint8_t ChargingComp[10]; //Page
//extern uint8_t ChargingErr[10]; //Page
////////////////////////////////////////////////////////////////////////////////////
//extern uint8_t SysErrMild[10]; //Page
//extern uint8_t SysErrCritical[10]; //Page
///////////////////////////////////////////////////////Test will be removed///////////////////////
//extern uint8_t Test[10]; //Page
//
////Indicators//
////Warning Lights
//extern uint8_t BatteryON[8];
//extern uint8_t BatteryOFF[8];
//
//extern uint8_t BatterySOHLowON[8];
//extern uint8_t BatterySOHLowOFF[8];
//
//extern uint8_t ErrorON[8];
//extern uint8_t ErrorOFF[8];
//
//extern uint8_t ServiceON[8];
//extern uint8_t ServiceOFF[8];
//
//extern uint8_t MildErrorON[8];
//extern uint8_t MildErrorOFF[8];
//
//extern uint8_t BatTempHighON[8]; //Not_Used
//extern uint8_t BatTempHighOFF[8]; //Not_Used
//
//extern uint8_t HandBrakeON[8]; //Icon
//extern uint8_t HandBrakeOFF[8]; //Icon
//
//extern uint8_t TemperatureMotCritON[8];
//extern uint8_t TemperatureMotCritOFF[8];
//
//extern uint8_t TemperatureMotHighON[8];
//extern uint8_t TemperatureMotHighOFF[8];
//
//extern uint8_t TemperatureMotMildON[8];
//extern uint8_t TemperatureMotMildOFF[8];
//
////Indicators//
//extern uint8_t TailgateOpenON[8];
//extern uint8_t TailgateOpenOFF[8];
//
//extern uint8_t HighBeamON[8];
//extern uint8_t HighBeamOFF[8];
//
//extern uint8_t SeatBeltON[8];
//extern uint8_t SeatBeltOFF[8];
//
//extern uint8_t LowBeamON[8];
//extern uint8_t LowBeamOFF[8];
//
//extern uint8_t LeftSignalON[8];
//extern uint8_t LeftSignalOFF[8];
//
//extern uint8_t RightSignalON[8];
//extern uint8_t RightSignalOFF[8];
////////////////////////////////////////
//extern uint8_t PowerLimitedON[8];
//extern uint8_t PowerLimitedOFF[8];
//
//extern uint8_t ReadytoDrive_Icon_ON[8];
//extern uint8_t ReadytoDrive_Icon_OFF[8];
//
//extern uint8_t BluetoothON[8];
//extern uint8_t BluetoothOFF[8];
//
//extern uint8_t DeviceConnON[8];
//extern uint8_t DeviceConneOFF[8];
///////////////////
////Gear Selection
//extern uint8_t ReverseON[8];
//extern uint8_t NeutralON[8];
//extern uint8_t DriveON[8];
//extern uint8_t GearClear[8];
//
////Drive Mode
//extern uint8_t EcoON[8];
//extern uint8_t NormalON[8];
//extern uint8_t SportON[8];
//extern uint8_t modeClear[8];
//
////Drive Unit
//extern uint8_t DriveUnitOFF[8];
//extern uint8_t DriveUnitON[8];
//
////Range Indicator
//extern uint8_t BotGreenON[8];
//extern uint8_t BotOrangeON[8];
//extern uint8_t BotRedON[8];
//
////Settings Menu
//extern uint8_t UI_Button_Vehicle[8];
//extern uint8_t UI_Button_System[8];
//extern uint8_t UI_Button_Bluetooth[8];
//extern uint8_t UI_Button_Errors[8];
//extern uint8_t UI_Button_Non[8];
//
////Bluetooth Menu
//extern uint8_t BluetoothONNoLit[8];
//extern uint8_t BluetoothONLit[8];
//
//extern uint8_t BluetoothOFFNoLit[8];
//extern uint8_t BluetoothOFFLit[8];
//
////System Menu
//extern uint8_t TimeSelect[8];
//extern uint8_t BrightnessSelect[8];
//
////Charging Menu
//extern uint8_t SlowCharging[8];
//extern uint8_t FastCharging[8];
//
////Side Menu
//extern uint8_t HighBatTemp[8];
//extern uint8_t LowBat[8];
//extern uint8_t LowBatCharge[8];
//extern uint8_t BatMenuOFF[8];
//
//extern uint8_t TailgateOpen[8];
//extern uint8_t TailgateClose[8];
//
////Mode Pages
//extern uint8_t Eco[10]; //Page
//
//extern uint8_t Normal[10]; //Page
//
//extern uint8_t Sport[10]; //Page
//
//extern uint8_t modeChange_Lock[10]; //Page
//
///////////////////////////////////////////////////////////
//
//extern uint8_t ChargerConnErrON[8];
//extern uint8_t ChargerConnErrOFF[8];
//
//extern uint8_t EmergencyPressed[8];
//extern uint8_t EmergencyPressedOFF[8];
//
//extern uint8_t HighMotTempMild[8];
//extern uint8_t HighMotTempCrit[8];
//extern uint8_t HighMotTempOFF[8];
//
//extern uint8_t DriveModeErr[8];
//extern uint8_t DriveModeErrOFF[8];
//
//extern uint8_t RegenBrakeErr[8];
//extern uint8_t RegenBrakeErrOFF[8];
//
//extern uint8_t ChargerErr[8];
//extern uint8_t ChargerErrOFF[8];
//
////Others
//extern uint8_t usartRX[15];
//extern uint8_t TripReset[8];
//extern uint8_t readTime[7];
//
////struct tm t;
////extern time_t t_of_day;
////
////time_t rawtime = 3056441880;
////struct tm ts;
////char timebuf[80];
//
////Battery Bar
//extern uint8_t bat0[8];
//extern uint8_t bat5[8];
//extern uint8_t bat10[8];
//extern uint8_t bat15[8];
//extern uint8_t bat20[8];
//extern uint8_t bat25[8];
//extern uint8_t bat30[8];
//extern uint8_t bat35[8];
//extern uint8_t bat40[8];
//extern uint8_t bat45[8];
//extern uint8_t bat50[8];
//extern uint8_t bat55[8];
//extern uint8_t bat60[8];
//extern uint8_t bat65[8];
//extern uint8_t bat70[8];
//extern uint8_t bat75[8];
//extern uint8_t bat80[8];
//extern uint8_t bat85[8];
//extern uint8_t bat90[8];
//extern uint8_t bat100[8];
//
////Power Bar
//extern uint8_t eco0[8];
//extern uint8_t eco1[8];
//extern uint8_t eco2[8];
//extern uint8_t eco3[8];
//extern uint8_t eco4[8];
//extern uint8_t eco5[8];
//
//extern uint8_t ecooff1[8];
//extern uint8_t ecooff2[8];
//extern uint8_t ecooff3[8];
//extern uint8_t ecooff4[8];
//extern uint8_t ecooff5[8];
//
//extern uint8_t power1[8];
//extern uint8_t power2[8];
//extern uint8_t power3[8];
//extern uint8_t power4[8];
//extern uint8_t power5[8];
//
//extern uint8_t poweroff1[8];
//extern uint8_t poweroff2[8];
//extern uint8_t poweroff3[8];
//extern uint8_t poweroff4[8];
//extern uint8_t poweroff5[8];
//
//extern uint8_t charge1[8];
//extern uint8_t charge2[8];
//extern uint8_t charge3[8];
//extern uint8_t charge4[8];
//extern uint8_t charge5[8];
//
//extern uint8_t chargestart0[8];
//extern uint8_t chargestart1[8];
//extern uint8_t chargestart2[8];
//extern uint8_t chargestart3[8];
//extern uint8_t chargestart4[8];
//extern uint8_t chargestart5[8];
//
//extern uint8_t chargestartoff1[8];
//extern uint8_t chargestartoff2[8];
//extern uint8_t chargestartoff3[8];
//extern uint8_t chargestartoff4[8];
//extern uint8_t chargestartoff5[8];
//
////Brightness Bar
//extern uint8_t bright0[8];
//extern uint8_t bright1[8];
//extern uint8_t bright2[8];
//extern uint8_t bright3[8];
//extern uint8_t bright4[8];
//extern uint8_t bright5[8];
//extern uint8_t bright6[8];
//
//extern void transmitPageHandler(uint8_t* page,uint8_t pageSize);
//
////#define VEGA_TX
////#define DMA
////#define No_DMA
//
//#ifdef VEGA_TX
//#define Transmit_strDATA transmitPageHandler(strDATA, sizeof(strDATA));
//#define Transmit_strDATA2 transmitPageHandler(strDATA2, sizeof(strDATA2));
//
//#define Tuk_Page transmitPageHandler( Tuk,sizeof(Tuk))
//
//#define Disengage_KillSwitch_Page transmitPageHandler( DisenKillSwitch,sizeof(DisenKillSwitch))
//#define Press_Brake_Page transmitPageHandler( PressBrake, sizeof(PressBrake))
//#define Gear_Error_Page transmitPageHandler( GearErr, sizeof(GearErr))
//
//#define Gear_Neutral_Icon transmitPageHandler( NeutralON, sizeof(NeutralON))
//#define Gear_Drive_Icon transmitPageHandler( DriveON, sizeof(DriveON))
//#define Gear_Reverse_Icon transmitPageHandler( ReverseON, sizeof(ReverseON))
//#define Gear_Clear_Icon transmitPageHandler( GearClear, sizeof(GearClear))
//
//#define System_Check_Okay_No_Icon_Page transmitPageHandler( SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon))
//#define System_Check_All_Icon_Page transmitPageHandler( SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll))
//
//#define Vehicle_Button transmitPageHandler( UI_Button_Vehicle, sizeof(UI_Button_Vehicle))
//#define System_Button transmitPageHandler( UI_Button_System, sizeof(UI_Button_System))
//#define Bluetooth_Button transmitPageHandler( UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth))
//#define Error_Button transmitPageHandler( UI_Button_Errors, sizeof(UI_Button_Errors))
//#define NO_Button transmitPageHandler( UI_Button_Non, sizeof(UI_Button_Non))
//
//#define After_Charge_Page transmitPageHandler( AfterRecharge, sizeof(AfterRecharge))
//
//#define Vehicle_Settings_Page transmitPageHandler( Settings, sizeof(Settings))
//#define Trip_Summary_Page transmitPageHandler( TripSum, sizeof(TripSum))
//#define Vehicle_Info_Page transmitPageHandler( VehicleInfo, sizeof(VehicleInfo))
//
//#define General_Menu_Page transmitPageHandler( Vehicle, sizeof(Vehicle))
//#define System_Menu_Page transmitPageHandler( System, sizeof(System))
//#define Bluetooth_Menu_Page transmitPageHandler( Bluetooth, sizeof(Bluetooth))
//#define Error_Menu_Page transmitPageHandler( Errors, sizeof(Errors))
//
//#define Battery_Info_Page transmitPageHandler( VehicleInfoBat, sizeof(VehicleInfoBat))
//#define Motor_Info_Page transmitPageHandler( VehicleInfoMot, sizeof(VehicleInfoMot))
//#define Inverter_Info_Page transmitPageHandler( VehicleInfoInv, sizeof(VehicleInfoInv))
//
//#define Charging_Page transmitPageHandler( Charging, sizeof(Charging))
//#define ChargeComplete_Page transmitPageHandler( ChargingComp, sizeof(ChargingComp))
//#define Charge_Error_Page transmitPageHandler( ChargingErr, sizeof(ChargingErr))
//
//#define Charge_Error_WithPopup_Page transmitPageHandler( ChargeError_Code,sizeof(ChargeError_Code))
//
//#define Charge_Connection_Error_Popup_ON transmitPageHandler( ChargerConnErrON,sizeof(ChargerConnErrON))
//#define Charge_Connection_Error_Popup_OFF transmitPageHandler( ChargerConnErrOFF,sizeof(ChargerConnErrOFF))
/////LIT
//
//////////
//
//#define Trip_Reset transmitPageHandler( TripReset, sizeof(TripReset))
//
//#define DriveUnit_ON_Icon transmitPageHandler( DriveUnitON, sizeof(DriveUnitON))
//#define DriveUnit_OFF_Icon transmitPageHandler( DriveUnitOFF, sizeof(DriveUnitOFF))
//
//#define ReadytoDrive_ON_Icon transmitPageHandler( ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON))
//#define ReadytoDrive_OFF_Icon transmitPageHandler( ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF))
//#define ReadytoDrive_Page transmitPageHandler(ReadytoDrive,10)
//
//#define PowerLimitON_Icon transmitPageHandler(PowerLimitedON, sizeof(PowerLimitedON))
//#define PowerLimitOFF_Icon transmitPageHandler(PowerLimitedOFF,sizeof(PowerLimitedOFF))
//
//#define HandBrake_ON_Icon transmitPageHandler(HandBrakeON,sizeof(HandBrakeON))
//#define HandBrake_OFF_Icon transmitPageHandler(HandBrakeOFF,sizeof(HandBrakeOFF))
//
//#define Motor_Critical_Temp_ON_Icon transmitPageHandler(TemperatureMotCritON,sizeof(TemperatureMotCritON))
//#define Motor_Critical_Temp_OFF_Icon transmitPageHandler(TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF))
//
//#define Motor_Temp_ON_Icon transmitPageHandler(TemperatureMotHighON,sizeof(TemperatureMotHighON))
//#define Motor_Temp_OFF_Icon transmitPageHandler(TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF))
//
//#define Motor_Mild_Temp_ON_Icon transmitPageHandler( TemperatureMotMildON,sizeof(TemperatureMotMildON))
//#define Motor_Mild_Temp_OFF_Icon transmitPageHandler( TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF))
//
//#define Tailgate_Opened_Icon transmitPageHandler( TailgateOpenON,sizeof(TailgateOpenON))
//#define Tailgate_Closed_Icon transmitPageHandler( TailgateOpenOFF,sizeof(TailgateOpenOFF))
//
////BluetoothON
////BluetoothOFF
////
////BluetoothONNoLit
////BluetoothOFFNoLit
////
////BluetoothONLit
////BluetoothOFFLit
//
//#define Highbeam_ON_Icon transmitPageHandler(HighBeamON,sizeof(HighBeamON))
//#define Highbeam_OFF_Icon transmitPageHandler(HighBeamOFF,sizeof(HighBeamOFF))
//
//#define Seatbelt_ON_Icon transmitPageHandler(SeatBeltON,sizeof(SeatBeltON))
//#define Seatbelt_OFF_Icon transmitPageHandler(SeatBeltOFF,sizeof(SeatBeltOFF))
//
//#define Lowbeam_ON_Icon transmitPageHandler(LowBeamON,sizeof(LowBeamON))
//#define Lowbeam_OFF_Icon transmitPageHandler(LowBeamOFF,sizeof(LowBeamOFF))
//
//#define Error_ON_Icon transmitPageHandler( ErrorON, sizeof(ErrorON))
//#define Error_OFF_Icon transmitPageHandler( ErrorOFF, sizeof(ErrorOFF))
//
//#define Mild_Error_ON_Icon transmitPageHandler( MildErrorON, sizeof(MildErrorON))
//#define Mild_Error_OFF_Icon transmitPageHandler( MildErrorOFF, sizeof(MildErrorOFF))
//
//#define Service_Error_ON_Icon transmitPageHandler( ServiceON, sizeof(ServiceON))
//#define Service_Error_OFF_Icon transmitPageHandler( ServiceOFF, sizeof(ServiceOFF))
//
//#define Battery_SOH_LOW_Popup_ON transmitPageHandler( BatterySOHLowON, sizeof(BatterySOHLowON))
//#define Battery_SOH_LOW_Popup_OFF transmitPageHandler( BatterySOHLowOFF, sizeof(BatterySOHLowOFF))
//#define Battery_High_Temp_Popup_ON transmitPageHandler( HighBatTemp, sizeof(HighBatTemp))
//#define Battery_High_Temp_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_LOW20_Popup_ON	transmitPageHandler( LowBat, sizeof(LowBat))
//#define Battery_LOW20_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_LOW_Charge_Popup_ON transmitPageHandler( LowBatCharge, sizeof(LowBatCharge))
//#define Battery_LOW_Charge_Popup_OFF transmitPageHandler( BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_Temp_High_Icon transmitPageHandler( BatTempHighON, sizeof(BatTempHighON))
//#define Battery_Temp_OK_Icon transmitPageHandler( BatTempHighOFF, sizeof(BatTempHighOFF))
//#define Battery_ON_Icon transmitPageHandler( BatteryON, sizeof(BatteryON))
//#define Battery_OFF_Icon transmitPageHandler( BatteryOFF, sizeof(BatteryOFF))
//
//#define SystemError_Critical_Popup transmitPageHandler( SysErrCritical, sizeof(SysErrCritical))
//#define SystemError_Mild_Popup_Page transmitPageHandler( SysErrMild, sizeof(SysErrMild))
//#define SysError_Shutdown_Page transmitPageHandler( SysError_shutdown,sizeof(SysError_shutdown))
//#define ModeChangeOFF_Page transmitPageHandler( modeChange_Lock,sizeof(modeChange_Lock))
//#define SysError_StopDrive_Page transmitPageHandler( SysError_SafeStop,sizeof(SysError_SafeStop))
//
//#define NormalMode_Popup transmitPageHandler( Normal, sizeof(Normal))
//#define NormalMode_Icon transmitPageHandler( NormalON, sizeof(NormalON))
//#define EcoMode_Popup transmitPageHandler( Eco, sizeof(Eco))
//#define EcoMode_Icon transmitPageHandler( EcoON, sizeof(EcoON))
//#define SportMode_Popup transmitPageHandler( Sport, sizeof(Sport))
//#define SportMode_Icon transmitPageHandler( SportON, sizeof(SportON))
//#define ModeClear_Icon transmitPageHandler( modeClear, sizeof(modeClear))
//
//#define L_Signal_ON_Icon transmitPageHandler( LeftSignalON, sizeof(LeftSignalON))
//#define L_Signal_OFF_Icon transmitPageHandler( LeftSignalOFF, sizeof(LeftSignalOFF))
//#define R_Signal_ON_Icon transmitPageHandler( RightSignalON, sizeof(RightSignalON))
//#define R_Signal_OFF_Icon transmitPageHandler( RightSignalOFF, sizeof(RightSignalOFF))
//
//#define HighBeam_ON_Icon transmitPageHandler( HighBeamON, sizeof(HighBeamON))
//#define HighBeam_OFF_Icon transmitPageHandler( HighBeamOFF, sizeof(HighBeamOFF))
//#endif
//
//
//
//#ifdef No_DMA
//#define Transmit_strDATA HAL_UART_Transmit(&huart3, strDATA, sizeof(strDATA), HAL_MAX_DELAY);
//#define Transmit_strDATA2 HAL_UART_Transmit(&huart3, strDATA2, sizeof(strDATA2), HAL_MAX_DELAY);
//
//#define Tuk_Page HAL_UART_Transmit(&huart3, Tuk,sizeof(Tuk),HAL_MAX_DELAY)
//
//#define Disengage_KillSwitch_Page HAL_UART_Transmit(&huart3, DisenKillSwitch,sizeof(DisenKillSwitch),HAL_MAX_DELAY)
//#define Press_Brake_Page HAL_UART_Transmit(&huart3, PressBrake, sizeof(PressBrake),HAL_MAX_DELAY)
//#define Gear_Error_Page HAL_UART_Transmit(&huart3, GearErr, sizeof(GearErr),HAL_MAX_DELAY)
//
//#define Gear_Neutral_Icon HAL_UART_Transmit(&huart3, NeutralON, sizeof(NeutralON),HAL_MAX_DELAY)
//#define Gear_Drive_Icon HAL_UART_Transmit(&huart3, DriveON, sizeof(DriveON), HAL_MAX_DELAY)
//#define Gear_Reverse_Icon HAL_UART_Transmit(&huart3, ReverseON, sizeof(ReverseON),HAL_MAX_DELAY)
//#define Gear_Clear_Icon HAL_UART_Transmit(&huart3, GearClear, sizeof(GearClear),HAL_MAX_DELAY)
//
//#define System_Check_Okay_No_Icon_Page HAL_UART_Transmit(&huart3, SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon),HAL_MAX_DELAY)
//#define System_Check_All_Icon_Page HAL_UART_Transmit(&huart3, SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll),HAL_MAX_DELAY)
//
//#define Vehicle_Button HAL_UART_Transmit(&huart3, UI_Button_Vehicle, sizeof(UI_Button_Vehicle),HAL_MAX_DELAY)
//#define System_Button HAL_UART_Transmit(&huart3, UI_Button_System, sizeof(UI_Button_System),HAL_MAX_DELAY)
//#define Bluetooth_Button HAL_UART_Transmit(&huart3, UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth),HAL_MAX_DELAY)
//#define Error_Button HAL_UART_Transmit(&huart3, UI_Button_Errors, sizeof(UI_Button_Errors), HAL_MAX_DELAY)
//#define NO_Button HAL_UART_Transmit(&huart3, UI_Button_Non, sizeof(UI_Button_Non),HAL_MAX_DELAY)
//
//#define After_Charge_Page HAL_UART_Transmit(&huart3, AfterRecharge, sizeof(AfterRecharge),HAL_MAX_DELAY)
//
//#define Vehicle_Settings_Page HAL_UART_Transmit(&huart3, Settings, sizeof(Settings), HAL_MAX_DELAY)
//#define Trip_Summary_Page HAL_UART_Transmit(&huart3, TripSum, sizeof(TripSum), HAL_MAX_DELAY)
//#define Vehicle_Info_Page HAL_UART_Transmit(&huart3, VehicleInfo, sizeof(VehicleInfo),HAL_MAX_DELAY)
//
//#define General_Menu_Page HAL_UART_Transmit(&huart3, Vehicle, sizeof(Vehicle), HAL_MAX_DELAY)
//#define System_Menu_Page HAL_UART_Transmit(&huart3, System, sizeof(System), HAL_MAX_DELAY)
//#define Bluetooth_Menu_Page HAL_UART_Transmit(&huart3, Bluetooth, sizeof(Bluetooth),HAL_MAX_DELAY)
//#define Error_Menu_Page HAL_UART_Transmit(&huart3, Errors, sizeof(Errors), HAL_MAX_DELAY)
//
//#define Battery_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoBat, sizeof(VehicleInfoBat),HAL_MAX_DELAY)
//#define Motor_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoMot, sizeof(VehicleInfoMot),HAL_MAX_DELAY)
//#define Inverter_Info_Page HAL_UART_Transmit(&huart3, VehicleInfoInv, sizeof(VehicleInfoInv),HAL_MAX_DELAY)
//
//#define Charging_Page HAL_UART_Transmit(&huart3, Charging, sizeof(Charging),HAL_MAX_DELAY)
//#define ChargeComplete_Page HAL_UART_Transmit(&huart3, ChargingComp, sizeof(ChargingComp),HAL_MAX_DELAY)
//#define Charge_Error_Page HAL_UART_Transmit(&huart3, ChargingErr, sizeof(ChargingErr),HAL_MAX_DELAY)
//
//#define Charge_Error_WithPopup_Page HAL_UART_Transmit(&huart3, ChargeError_Code,sizeof(ChargeError_Code),HAL_MAX_DELAY)
//
//#define Charge_Connection_Error_Popup_ON HAL_UART_Transmit(&huart3, ChargerConnErrON,sizeof(ChargerConnErrON), HAL_MAX_DELAY)
//#define Charge_Connection_Error_Popup_OFF HAL_UART_Transmit(&huart3, ChargerConnErrOFF,sizeof(ChargerConnErrOFF), HAL_MAX_DELAY)
/////LIT
//
//////////
//
//#define Trip_Reset HAL_UART_Transmit(&huart3, TripReset, sizeof(TripReset), HAL_MAX_DELAY)
//
//#define DriveUnit_ON_Icon HAL_UART_Transmit(&huart3, DriveUnitON, sizeof(DriveUnitON),HAL_MAX_DELAY)
//#define DriveUnit_OFF_Icon HAL_UART_Transmit(&huart3, DriveUnitOFF, sizeof(DriveUnitOFF),HAL_MAX_DELAY)
//
//#define ReadytoDrive_ON_Icon HAL_UART_Transmit(&huart3, ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON),HAL_MAX_DELAY)
//#define ReadytoDrive_OFF_Icon HAL_UART_Transmit(&huart3, ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF),HAL_MAX_DELAY)
//#define ReadytoDrive_Page HAL_UART_Transmit(&huart3, ReadytoDrive, sizeof(ReadytoDrive),HAL_MAX_DELAY)
//
//#define PowerLimitON_Icon HAL_UART_Transmit(&huart3, PowerLimitedON, sizeof(PowerLimitedON),HAL_MAX_DELAY)
//#define PowerLimitOFF_Icon HAL_UART_Transmit(&huart3, PowerLimitedOFF,sizeof(PowerLimitedOFF),HAL_MAX_DELAY)
//
//#define HandBrake_ON_Icon HAL_UART_Transmit(&huart3, HandBrakeON,sizeof(HandBrakeON),HAL_MAX_DELAY)
//#define HandBrake_OFF_Icon HAL_UART_Transmit(&huart3, HandBrakeOFF,sizeof(HandBrakeOFF),HAL_MAX_DELAY)
//
//#define Motor_Critical_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotCritON,sizeof(TemperatureMotCritON),HAL_MAX_DELAY)
//#define Motor_Critical_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF),HAL_MAX_DELAY)
//
//#define Motor_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotHighON,sizeof(TemperatureMotHighON),HAL_MAX_DELAY)
//#define Motor_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF),HAL_MAX_DELAY)
//
//#define Motor_Mild_Temp_ON_Icon HAL_UART_Transmit(&huart3, TemperatureMotMildON,sizeof(TemperatureMotMildON),HAL_MAX_DELAY)
//#define Motor_Mild_Temp_OFF_Icon HAL_UART_Transmit(&huart3, TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF),HAL_MAX_DELAY)
//
//#define Tailgate_Opened_Icon HAL_UART_Transmit(&huart3, TailgateOpenON,sizeof(TailgateOpenON),HAL_MAX_DELAY)
//#define Tailgate_Closed_Icon HAL_UART_Transmit(&huart3, TailgateOpenOFF,sizeof(TailgateOpenOFF),HAL_MAX_DELAY)
//
////BluetoothON
////BluetoothOFF
////
////BluetoothONNoLit
////BluetoothOFFNoLit
////
////BluetoothONLit
////BluetoothOFFLit
//
//#define Highbeam_ON_Icon HAL_UART_Transmit(&huart3, HighBeamON,sizeof(HighBeamON),HAL_MAX_DELAY)
//#define Highbeam_OFF_Icon HAL_UART_Transmit(&huart3, HighBeamOFF,sizeof(HighBeamOFF),HAL_MAX_DELAY)
//
//#define Seatbelt_ON_Icon HAL_UART_Transmit(&huart3, SeatBeltON,sizeof(SeatBeltON),HAL_MAX_DELAY)
//#define Seatbelt_OFF_Icon HAL_UART_Transmit(&huart3, SeatBeltOFF,sizeof(SeatBeltOFF),HAL_MAX_DELAY)
//
//#define Lowbeam_ON_Icon HAL_UART_Transmit(&huart3, LowBeamON,sizeof(LowBeamON),HAL_MAX_DELAY)
//#define Lowbeam_OFF_Icon HAL_UART_Transmit(&huart3, LowBeamOFF,sizeof(LowBeamOFF),HAL_MAX_DELAY)
//
//#define Error_ON_Icon HAL_UART_Transmit(&huart3, ErrorON, sizeof(ErrorON),HAL_MAX_DELAY)
//#define Error_OFF_Icon HAL_UART_Transmit(&huart3, ErrorOFF, sizeof(ErrorOFF),HAL_MAX_DELAY)
//
//#define Mild_Error_ON_Icon HAL_UART_Transmit(&huart3, MildErrorON, sizeof(MildErrorON),HAL_MAX_DELAY)
//#define Mild_Error_OFF_Icon HAL_UART_Transmit(&huart3, MildErrorOFF, sizeof(MildErrorOFF),HAL_MAX_DELAY)
//
//#define Service_Error_ON_Icon HAL_UART_Transmit(&huart3, ServiceON, sizeof(ServiceON),HAL_MAX_DELAY)
//#define Service_Error_OFF_Icon HAL_UART_Transmit(&huart3, ServiceOFF, sizeof(ServiceOFF),HAL_MAX_DELAY)
//
//#define Battery_SOH_LOW_Popup_ON HAL_UART_Transmit(&huart3, BatterySOHLowON, sizeof(BatterySOHLowON),HAL_MAX_DELAY)
//#define Battery_SOH_LOW_Popup_OFF HAL_UART_Transmit(&huart3, BatterySOHLowOFF, sizeof(BatterySOHLowOFF),HAL_MAX_DELAY)
//#define Battery_High_Temp_Popup_ON HAL_UART_Transmit(&huart3, HighBatTemp, sizeof(HighBatTemp),HAL_MAX_DELAY)
//#define Battery_High_Temp_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
//#define Battery_LOW20_Popup_ON	HAL_UART_Transmit(&huart3, LowBat, sizeof(LowBat),HAL_MAX_DELAY)
//#define Battery_LOW20_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
//#define Battery_LOW_Charge_Popup_ON HAL_UART_Transmit(&huart3, LowBatCharge, sizeof(LowBatCharge),HAL_MAX_DELAY)
//#define Battery_LOW_Charge_Popup_OFF HAL_UART_Transmit(&huart3, BatMenuOFF, sizeof(HighBatTemp),HAL_MAX_DELAY)
//#define Battery_Temp_High_Icon HAL_UART_Transmit(&huart3, BatTempHighON, sizeof(BatTempHighON),HAL_MAX_DELAY)
//#define Battery_Temp_OK_Icon HAL_UART_Transmit(&huart3, BatTempHighOFF, sizeof(BatTempHighOFF),HAL_MAX_DELAY)
//#define Battery_ON_Icon HAL_UART_Transmit(&huart3, BatteryON, sizeof(BatteryON),HAL_MAX_DELAY)
//#define Battery_OFF_Icon HAL_UART_Transmit(&huart3, BatteryOFF, sizeof(BatteryOFF),HAL_MAX_DELAY)
//
//#define SystemError_Critical_Popup HAL_UART_Transmit(&huart3, SysErrCritical, sizeof(SysErrCritical),HAL_MAX_DELAY)
//#define SystemError_Mild_Popup_Page HAL_UART_Transmit(&huart3, SysErrMild, sizeof(SysErrMild),HAL_MAX_DELAY)
//#define SysError_Shutdown_Page HAL_UART_Transmit(&huart3, SysError_shutdown,sizeof(SysError_shutdown),HAL_MAX_DELAY)
//#define ModeChangeOFF_Page HAL_UART_Transmit(&huart3, modeChange_Lock,sizeof(modeChange_Lock),HAL_MAX_DELAY)
//#define SysError_StopDrive_Page HAL_UART_Transmit(&huart3, SysError_SafeStop,sizeof(SysError_SafeStop),HAL_MAX_DELAY)
//
//#define NormalMode_Popup HAL_UART_Transmit(&huart3, Normal, sizeof(Normal),HAL_MAX_DELAY)
//#define NormalMode_Icon HAL_UART_Transmit(&huart3, NormalON, sizeof(NormalON), HAL_MAX_DELAY)
//#define EcoMode_Popup HAL_UART_Transmit(&huart3, Eco, sizeof(Eco), HAL_MAX_DELAY)
//#define EcoMode_Icon HAL_UART_Transmit(&huart3, EcoON, sizeof(EcoON), HAL_MAX_DELAY)
//#define SportMode_Popup HAL_UART_Transmit(&huart3, Sport, sizeof(Sport), HAL_MAX_DELAY)
//#define SportMode_Icon HAL_UART_Transmit(&huart3, SportON, sizeof(SportON), HAL_MAX_DELAY)
//#define ModeClear_Icon HAL_UART_Transmit(&huart3, modeClear, sizeof(modeClear),HAL_MAX_DELAY)
//
//#define L_Signal_ON_Icon HAL_UART_Transmit(&huart3, LeftSignalON, sizeof(LeftSignalON),HAL_MAX_DELAY)
//#define L_Signal_OFF_Icon HAL_UART_Transmit(&huart3, LeftSignalOFF, sizeof(LeftSignalOFF),HAL_MAX_DELAY)
//#define R_Signal_ON_Icon HAL_UART_Transmit(&huart3, RightSignalON, sizeof(RightSignalON),HAL_MAX_DELAY)
//#define R_Signal_OFF_Icon HAL_UART_Transmit(&huart3, RightSignalOFF, sizeof(RightSignalOFF),HAL_MAX_DELAY)
//
//#define HighBeam_ON_Icon HAL_UART_Transmit(&huart3, HighBeamON, sizeof(HighBeamON),HAL_MAX_DELAY)
//#define HighBeam_OFF_Icon HAL_UART_Transmit(&huart3, HighBeamOFF, sizeof(HighBeamOFF),HAL_MAX_DELAY)
//#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////DMA Defines
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#ifdef DMA
//#define Transmit_strDATA HAL_UART_Transmit_DMA(&huart3, strDATA, sizeof(strDATA));
//#define Transmit_strDATA2 HAL_UART_Transmit_DMA(&huart3, strDATA2, sizeof(strDATA2));
//
//#define Tuk_Page HAL_UART_Transmit_DMA(&huart3, Tuk,sizeof(Tuk))
//
//#define Fire_Page HAL_UART_Transmit_DMA(&huart3, firePage, sizeof(firePage))
//
//#define Disengage_KillSwitch_Page HAL_UART_Transmit_DMA(&huart3, DisenKillSwitch,sizeof(DisenKillSwitch))
//#define Press_Brake_Page HAL_UART_Transmit_DMA(&huart3, PressBrake, sizeof(PressBrake))
//
//#define Gear_Error_Page HAL_UART_Transmit_DMA(&huart3, GearErr, sizeof(GearErr))
//
//#define Gear_Neutral_Icon HAL_UART_Transmit_DMA(&huart3, NeutralON, sizeof(NeutralON))
//#define Gear_Drive_Icon HAL_UART_Transmit_DMA(&huart3, DriveON, sizeof(DriveON))
//#define Gear_Reverse_Icon HAL_UART_Transmit_DMA(&huart3, ReverseON, sizeof(ReverseON))
//#define Gear_Clear_Icon HAL_UART_Transmit_DMA(&huart3, GearClear, sizeof(GearClear))
//
//#define System_Check_Okay_No_Icon_Page HAL_UART_Transmit_DMA(&huart3, SysCheck_Okay_NoIcon, sizeof(SysCheck_Okay_NoIcon))
//#define System_Check_All_Icon_Page HAL_UART_Transmit_DMA(&huart3, SysCheck_lit_IconAll, sizeof(SysCheck_lit_IconAll))
//
//#define Vehicle_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Vehicle, sizeof(UI_Button_Vehicle))
//#define System_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_System, sizeof(UI_Button_System))
//#define Bluetooth_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Bluetooth, sizeof(UI_Button_Bluetooth))
//#define Error_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Errors, sizeof(UI_Button_Errors))
//#define NO_Button HAL_UART_Transmit_DMA(&huart3, UI_Button_Non, sizeof(UI_Button_Non))
//
//#define After_Charge_Page HAL_UART_Transmit_DMA(&huart3, AfterRecharge, sizeof(AfterRecharge))
//
//#define Vehicle_Settings_Page HAL_UART_Transmit_DMA(&huart3, Settings, sizeof(Settings))
//#define Trip_Summary_Page HAL_UART_Transmit_DMA(&huart3, TripSum, sizeof(TripSum))
//#define Vehicle_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfo, sizeof(VehicleInfo))
//
//#define General_Menu_Page HAL_UART_Transmit_DMA(&huart3, Vehicle, sizeof(Vehicle))
//#define System_Menu_Page HAL_UART_Transmit_DMA(&huart3, System, sizeof(System))
//#define Bluetooth_Menu_Page HAL_UART_Transmit_DMA(&huart3, Bluetooth, sizeof(Bluetooth))
//#define Error_Menu_Page HAL_UART_Transmit_DMA(&huart3, Errors, sizeof(Errors))
//
//#define Battery_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoBat, sizeof(VehicleInfoBat))
//#define Motor_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoMot, sizeof(VehicleInfoMot))
//#define Inverter_Info_Page HAL_UART_Transmit_DMA(&huart3, VehicleInfoInv, sizeof(VehicleInfoInv))
//
//#define Charging_Page HAL_UART_Transmit_DMA(&huart3, Charging, sizeof(Charging))
//#define ChargeComplete_Page HAL_UART_Transmit_DMA(&huart3, ChargingComp, sizeof(ChargingComp))
//#define Charge_Error_Page HAL_UART_Transmit_DMA(&huart3, ChargingErr, sizeof(ChargingErr))
//
//#define Charge_Error_WithPopup_Page HAL_UART_Transmit_DMA(&huart3, ChargeError_Code,sizeof(ChargeError_Code))
//
//#define Charge_Connection_Error_Popup_ON HAL_UART_Transmit_DMA(&huart3, ChargerConnErrON,sizeof(ChargerConnErrON))
//#define Charge_Connection_Error_Popup_OFF HAL_UART_Transmit_DMA(&huart3, ChargerConnErrOFF,sizeof(ChargerConnErrOFF))
/////LIT
//
//////////
//
//#define Trip_Reset HAL_UART_Transmit_DMA(&huart3, TripReset, sizeof(TripReset))
//
//#define DriveUnit_ON_Icon HAL_UART_Transmit_DMA(&huart3, DriveUnitON, sizeof(DriveUnitON))
//#define DriveUnit_OFF_Icon HAL_UART_Transmit_DMA(&huart3, DriveUnitOFF, sizeof(DriveUnitOFF))
//
//#define ReadytoDrive_ON_Icon HAL_UART_Transmit_DMA(&huart3, ReadytoDrive_Icon_ON, sizeof(ReadytoDrive_Icon_ON))
//#define ReadytoDrive_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ReadytoDrive_Icon_OFF,sizeof(ReadytoDrive_Icon_OFF))
//#define ReadytoDrive_Page HAL_UART_Transmit_DMA(&huart3, ReadytoDrive, sizeof(ReadytoDrive))
//
//#define PowerLimitON_Icon HAL_UART_Transmit_DMA(&huart3, PowerLimitedON, sizeof(PowerLimitedON))
//#define PowerLimitOFF_Icon HAL_UART_Transmit_DMA(&huart3, PowerLimitedOFF,sizeof(PowerLimitedOFF))
//
//#define HandBrake_ON_Icon HAL_UART_Transmit_DMA(&huart3, HandBrakeON,sizeof(HandBrakeON))
//#define HandBrake_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HandBrakeOFF,sizeof(HandBrakeOFF))
//
//#define Motor_Critical_Temp_ON_Icon HAL_UART_Transmit_DMA_DMA(&huart3, TemperatureMotCritON,sizeof(TemperatureMotCritON))
//#define Motor_Critical_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotCritOFF,sizeof(TemperatureMotCritOFF))
//
//#define Motor_Temp_ON_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotHighON,sizeof(TemperatureMotHighON))
//#define Motor_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotHighOFF,sizeof(TemperatureMotHighOFF))
//
//#define Motor_Mild_Temp_ON_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotMildON,sizeof(TemperatureMotMildON))
//#define Motor_Mild_Temp_OFF_Icon HAL_UART_Transmit_DMA(&huart3, TemperatureMotMildOFF,sizeof(TemperatureMotMildOFF))
//
//#define Tailgate_Opened_Icon HAL_UART_Transmit_DMA(&huart3, TailgateOpenON,sizeof(TailgateOpenON))
//#define Tailgate_Closed_Icon HAL_UART_Transmit_DMA(&huart3, TailgateOpenOFF,sizeof(TailgateOpenOFF))
//
////BluetoothON
////BluetoothOFF
////
////BluetoothONNoLit
////BluetoothOFFNoLit
////
////BluetoothONLit
////BluetoothOFFLit
//
//#define Highbeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamON,sizeof(HighBeamON))
//#define Highbeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamOFF,sizeof(HighBeamOFF))
//
//#define Seatbelt_ON_Icon HAL_UART_Transmit_DMA(&huart3, SeatBeltON,sizeof(SeatBeltON))
//#define Seatbelt_OFF_Icon HAL_UART_Transmit_DMA(&huart3, SeatBeltOFF,sizeof(SeatBeltOFF))
//
//#define Lowbeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, LowBeamON,sizeof(LowBeamON))
//#define Lowbeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, LowBeamOFF,sizeof(LowBeamOFF))
//
//#define Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, ErrorON, sizeof(ErrorON))
//#define Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ErrorOFF, sizeof(ErrorOFF))
//
//#define Mild_Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, MildErrorON, sizeof(MildErrorON))
//#define Mild_Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, MildErrorOFF, sizeof(MildErrorOFF))
//
//#define Service_Error_ON_Icon HAL_UART_Transmit_DMA(&huart3, ServiceON, sizeof(ServiceON))
//#define Service_Error_OFF_Icon HAL_UART_Transmit_DMA(&huart3, ServiceOFF, sizeof(ServiceOFF))
//
//#define Battery_SOH_LOW_Popup_ON HAL_UART_Transmit_DMA(&huart3, BatterySOHLowON, sizeof(BatterySOHLowON))
//#define Battery_SOH_LOW_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatterySOHLowOFF, sizeof(BatterySOHLowOFF))
//#define Battery_High_Temp_Popup_ON HAL_UART_Transmit_DMA(&huart3, HighBatTemp, sizeof(HighBatTemp))
//#define Battery_High_Temp_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_LOW20_Popup_ON	HAL_UART_Transmit_DMA(&huart3, LowBat, sizeof(LowBat))
//#define Battery_LOW20_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_LOW_Charge_Popup_ON HAL_UART_Transmit_DMA(&huart3, LowBatCharge, sizeof(LowBatCharge))
//#define Battery_LOW_Charge_Popup_OFF HAL_UART_Transmit_DMA(&huart3, BatMenuOFF, sizeof(HighBatTemp))
//#define Battery_Temp_High_Icon HAL_UART_Transmit_DMA(&huart3, BatTempHighON, sizeof(BatTempHighON))
//#define Battery_Temp_OK_Icon HAL_UART_Transmit_DMA(&huart3, BatTempHighOFF, sizeof(BatTempHighOFF))
//#define Battery_ON_Icon HAL_UART_Transmit_DMA(&huart3, BatteryON, sizeof(BatteryON))
//#define Battery_OFF_Icon HAL_UART_Transmit_DMA(&huart3, BatteryOFF, sizeof(BatteryOFF))
//
//#define SystemError_Critical_Popup HAL_UART_Transmit_DMA(&huart3, SysErrCritical, sizeof(SysErrCritical))
//#define SystemError_Mild_Popup_Page HAL_UART_Transmit_DMA(&huart3, SysErrMild, sizeof(SysErrMild))
//#define SysError_Shutdown_Page HAL_UART_Transmit_DMA(&huart3, SysError_shutdown,sizeof(SysError_shutdown))
//#define ModeChangeOFF_Page HAL_UART_Transmit_DMA(&huart3, modeChange_Lock,sizeof(modeChange_Lock))
//#define SysError_StopDrive_Page HAL_UART_Transmit_DMA(&huart3, SysError_SafeStop,sizeof(SysError_SafeStop))
//
//#define NormalMode_Popup HAL_UART_Transmit_DMA(&huart3, NormalON, sizeof(NormalON))
//#define NormalMode_Icon HAL_UART_Transmit_DMA(&huart3, Normal, sizeof(Normal))
//#define EcoMode_Popup HAL_UART_Transmit_DMA(&huart3, EcoON, sizeof(EcoON))
//#define EcoMode_Icon HAL_UART_Transmit_DMA(&huart3, Eco, sizeof(Eco))
//#define SportMode_Popup HAL_UART_Transmit_DMA(&huart3, SportON, sizeof(SportON))
//#define SportMode_Icon HAL_UART_Transmit_DMA(&huart3, Sport, sizeof(Sport))
//#define ModeClear_Icon HAL_UART_Transmit_DMA(&huart3, modeClear, sizeof(modeClear))
//
//#define L_Signal_ON_Icon HAL_UART_Transmit_DMA(&huart3, LeftSignalON, sizeof(LeftSignalON))
//#define L_Signal_OFF_Icon HAL_UART_Transmit_DMA(&huart3, LeftSignalOFF, sizeof(LeftSignalOFF))
//#define R_Signal_ON_Icon HAL_UART_Transmit_DMA(&huart3, RightSignalON, sizeof(RightSignalON))
//#define R_Signal_OFF_Icon HAL_UART_Transmit_DMA(&huart3, RightSignalOFF, sizeof(RightSignalOFF))
//
//#define HighBeam_ON_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamON, sizeof(HighBeamON))
//#define HighBeam_OFF_Icon HAL_UART_Transmit_DMA(&huart3, HighBeamOFF, sizeof(HighBeamOFF))
//#endif
