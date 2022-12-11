#ifndef INC_MENU_H_
#define INC_MENU_H_

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"
#include "vehicleControl.h"
#include "transmit.h"

void navigation(void);
void front_mainPage(void);
void trip_mainPage(void);
void after_charge_mainPage(void);
void info_mainPage(void);
void settings_mainPage(void);

//void drive_UI(uitype_t UI);
//void charging_UI(uitype_t ChargeUI);
//void vehicleInfo_UI(uitype_t InfoUI);
//void settings_UI(uitype_t SettingsMenu);
//void selection_UI(uitype_t SettingsMenu);

void usartReceive(void);


void vehicle_page(void);
void system_page(void);
void bluetooth_page(void);
void errors_page(void);


#endif /* INC_MENU_H_ */
