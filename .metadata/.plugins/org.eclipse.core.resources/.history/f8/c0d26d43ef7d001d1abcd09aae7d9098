#ifndef INC_TRANSMIT_H_
#define INC_TRANSMIT_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stm32f1xx_hal.h>
#include "data_structures.h"
#include "can_matrix.h"
#include "errLogging.h"
#include "transmitDefinitions.h"

extern void drivePageSetter(uitype_t page);

extern void charging_UI(uitype_t ChargeUI);
extern void vehicleInfo_UI(uitype_t InfoUI);
extern void settings_UI(uitype_t SettingsMenu,uint8_t selectedOption);
extern void selection_UI(uitype_t SettingsMenu);

extern void errorIcon(void);
extern void oneTimeData(void);
extern void realTimeData(void);
extern void speedUpdate(void);
extern void startingUp(void);
extern void gearUpdate(void);
extern void batteryBar(void);
extern void powerMeter(void);

extern void chargeState(void);
extern void driveState(void);
extern void resetThings(void);
extern void timeStampSend(void);
extern void timeStampReceive(void);

extern void errorCode(void);
extern void errorPopup(void);
extern void sideMenuPopup(void);
extern void popUpHandler(void);

extern void transmitTest(void);
//Mode Selection
extern void modeSelection(uimode_t currentMode);

extern void startupModeChange(void);
extern void transmit(void);
extern void bootAnimation(void);

extern void fireModePage(void);
extern void fireData(void);

extern void indicators(void);

//struct tm t;
//extern time_t t_of_day;
//time_t rawtime;
//struct tm ts;
//char timebuf[80];
//Debug//
extern uint8_t Errors[10];
extern uint8_t DisenKillSwitch[10];


#endif /* INC_TRANSMIT_H_ */
