#include <menu.h>


void navigation(void) {

	if (accessory == 1) {
		_navigation = true; // This will enable menu transmit
	} else {
		_navigation = false;
	}



	switch (currentPage) {
	case front:
		front_mainPage();
		if (currentStateSM == driving_state) {
			_realTimeData = true;
			_oneTimeData = true;
			//_testPage = true;
		}
		if (currentPage != previousPage) {
			previousPage = front;
			_setDriverPage = true;
			_realTimeData = false;
			_oneTimeData = false;
			if (currentStateSM == driving_state) {
				_transmit_Function = 4;
			}
			if (currentStateSM == startingup_state) {
				_transmit_Function = 1;
			}

		}
		break;
	case trip:
		_Trip_Summary_Page = true;
		trip_mainPage();
		if (currentStateSM == driving_state) {
			_realTimeData = true;
			_oneTimeData = true;
		}
		if (currentPage != previousPage) {
			previousPage = trip;
			_setDriverPage = true;
			_realTimeData = false;
			_oneTimeData = false;
			if (currentStateSM == driving_state) {
				_transmit_Function = 4;
			}
			if (currentStateSM == startingup_state) {
				_transmit_Function = 1;
			}
		}
		break;
	case after_charge:
		_After_Charge_Page = true;
		after_charge_mainPage();
		if (currentStateSM == driving_state) {
			_realTimeData = true;
			_oneTimeData = true;
		}
		if (currentPage != previousPage) {
			previousPage = after_charge;
			_setDriverPage = true;
			_realTimeData = false;
			_oneTimeData = false;
			if (currentStateSM == driving_state) {
				_transmit_Function = 4;
			}
			if (currentStateSM == startingup_state) {
				_transmit_Function = 1;
			}
		}
		break;
	case info:
		_Battery_Info_Page = true;
		_Motor_Info_Page = false;
		_Inverter_Info_Page = false;
		info_mainPage();
		if (currentStateSM == driving_state) {
			_realTimeData = true;
			_oneTimeData = true;
		}
		if (currentPage != previousPage) {
			previousPage = info;
			_setDriverPage = true;
			_realTimeData = false;
			_oneTimeData = false;
			if (currentStateSM == driving_state) {
				_transmit_Function = 4;
			}
			if (currentStateSM == startingup_state) {
				_transmit_Function = 1;
			}
		}
		break;
	case settings:
		settings_mainPage();
		if (currentStateSM == driving_state) {
			_realTimeData = true;
			_oneTimeData = true;
		}
		if (currentPage != previousPage) {
			previousPage = settings;
			_setDriverPage = true;
			_realTimeData = false;
			_oneTimeData = false;
			if (currentStateSM == driving_state) {
				_transmit_Function = 4;
			}
			if (currentStateSM == startingup_state) {
				_transmit_Function = 1;
			}
		}
		break;
	default:
		break;
	}

}

void front_mainPage(void) {
	if (page_entry) {
		page_entry = false;
		_modeSelection = true;
		_gearCleared = true;
		_gearChanged = true;
	}
	//drivePageSetter(front);
	_drivePageSet = front;
	_trasmitGlobal = Disengage_Page;

	//One time Run
//Run only if something has changed
	//

	if (forward == true) {
		currentPage = trip;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}

	if (backward == true) {
		backward = false;
		currentPage = settings;
		page_entry = true;
		forward = false;
		_menupage = 0;
		_trasmitGlobal = Disengage_Page;
		return;
	}
}

void trip_mainPage(void) {
	if (page_entry == true) {
		page_entry = false;
	}

	if (longpress == true) {
		tripreset = true;
		longpress = false;
	}
	//drivePageSetter(trip);
	_drivePageSet = trip;
	_trasmitGlobal = MainMenuPages;
	trip_reset();

	if (forward == true) {

		currentPage = after_charge;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}

	if (backward == true) {

		currentPage = front;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}
}

void after_charge_mainPage(void) {
	if (page_entry == true) {
		page_entry = false;
	}
	_drivePageSet = after_charge;
	//drivePageSetter(after_charge);
	_trasmitGlobal = MainMenuPages;

	if (forward == true) {

		currentPage = info;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}

	if (backward == true) {
		currentPage = trip;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}
}

void info_mainPage(void) {
//	if (page_entry == true) {
//		page_entry = false;
//	}
	_drivePageSet = info;
	_trasmitGlobal = MainMenuPages;
	//drivePageSetter(info);

	if (!(inInfoBat)) {
		if (okay == true) {
			inInfoBat = true;
			okay = false;
		}
	} else {	// When okay is pressed
		if (page_entry == true) {
			currentMenu = infobat;
			previousMenuBack = infoinv;
			previousMenuForward = infomot;
			page_entry = false;
			vehicleInfo_UI(infobat);
		} else {
			if (buttonPressed) {
				vehicleInfo_UI(currentMenu);
				buttonPressed = false;
			}
		}
		if (forward == true) {
			buttonPressed = true;
			if (currentMenu == infoinv && previousMenuBack == infomot) {
				_Battery_Info_Page = true;
				_Motor_Info_Page = false;
				_Inverter_Info_Page = false;

				currentMenu = infobat;
				previousMenuBack = infoinv;
				previousMenuForward = infomot;
				forward = false;
				return;
			}

			if (currentMenu == infobat && previousMenuBack == infoinv) {
				_Battery_Info_Page = false;
				_Motor_Info_Page = true;
				_Inverter_Info_Page = false;

				currentMenu = infomot;
				previousMenuBack = infobat;
				previousMenuForward = infoinv;
				forward = false;
				return;
			}

			if (currentMenu == infomot && previousMenuBack == infobat) {
				_Battery_Info_Page = false;
				_Motor_Info_Page = false;
				_Inverter_Info_Page = true;

				currentMenu = infoinv;
				previousMenuBack = infomot;
				previousMenuForward = infobat;
				forward = false;
				return;
			}

		}

		if (backward == true) {
			buttonPressed = true;
			if (currentMenu == infobat && previousMenuForward == infomot) {
				_Battery_Info_Page = false;
				_Motor_Info_Page = false;
				_Inverter_Info_Page = true;

				currentMenu = infoinv;
				previousMenuForward = infobat;
				previousMenuBack = infomot;
				backward = false;
				return;
			}

			if (currentMenu == infoinv && previousMenuForward == infobat) {
				_Battery_Info_Page = false;
				_Motor_Info_Page = true;
				_Inverter_Info_Page = false;

				currentMenu = infomot;
				previousMenuForward = infoinv;
				previousMenuBack = infobat;
				backward = false;
				return;
			}

			if (currentMenu == infomot && previousMenuForward == infoinv) {
				_Battery_Info_Page = true;
				_Motor_Info_Page = false;
				_Inverter_Info_Page = false;

				currentMenu = infobat;
				previousMenuForward = infomot;
				previousMenuBack = infoinv;
				backward = false;
				return;
			}
		}

		if (back == true) {
			_Battery_Info_Page = true;
			_Motor_Info_Page = false;
			_Inverter_Info_Page = false;

			page_entry = true;
			inInfoBat = false;
			back = false;
			_menupage = 0;
		}
		return;
	}

	if (forward == true) {
		currentPage = settings;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}

	if (backward == true) {
		currentPage = after_charge;
		page_entry = true;
		forward = false;
		backward = false;
		_menupage = 0;
		return;
	}
}

void settings_mainPage(void) {

	//selection_UI(front);
	//drivePageSetter(settings);
	_drivePageSet = settings;
	_trasmitGlobal = MainMenuPages;

	if (!(inSettings)) {
		selection_UI(front);
		if (okay == true) {
			inSettings = true;
			okay = false;
		}
	} else {
		if (page_entry == true) {
			currentMenu = vehicleMenu;
			previousMenuForward = errorsMenu;
			previousMenuBack = systemMenu;
			_menuChanged = true;
			page_entry = false;
		}
		if(menuCounter>2)
		{
			if (_menuChanged) {
				_menuChanged = false;
				selection_UI(currentMenu);
			}
			menuCounter = 0;
		}


		if (!(menuAccess)) {
			menuCounter++;
			if (forward == true) {
//				currentMenu--;
//				if (currentMenu <= 7) {
//					currentMenu = errorsMenu;
//				}
				if (currentMenu == errorsMenu && previousMenuBack == vehicleMenu) {
					currentMenu = bluetoothMenu;
					previousMenuForward = systemMenu;
					previousMenuBack = errorsMenu;
					_menuChanged = true;
					forward = false;
					return;
				}
				if (currentMenu == vehicleMenu && previousMenuBack == systemMenu) {
					currentMenu = errorsMenu;
					previousMenuForward = bluetoothMenu;
					previousMenuBack = vehicleMenu;
					_menuChanged = true;
					forward = false;
					return;
				}
				if (currentMenu == systemMenu && previousMenuBack == bluetoothMenu) {
					currentMenu = vehicleMenu;
					previousMenuForward = errorsMenu;
					previousMenuBack = systemMenu;
					_menuChanged = true;
					forward = false;
					return;
				}
				if (currentMenu == bluetoothMenu && previousMenuBack == errorsMenu) {
					currentMenu = systemMenu;
					previousMenuForward = vehicleMenu;
					previousMenuBack = bluetoothMenu;
					_menuChanged = true;
					forward = false;
					return;
				}
			}

			if (backward == true) {
//				currentMenu++;
//				if (currentMenu >= 12) {
//					currentMenu = vehicleMenu;
//				}
				if (currentMenu == vehicleMenu && previousMenuForward == errorsMenu) {
					currentMenu = systemMenu;
					previousMenuForward = vehicleMenu;

					previousMenuBack = bluetoothMenu;
					_menuChanged = true;
					backward = false;
					return;
				}
				if (currentMenu == errorsMenu && previousMenuForward == bluetoothMenu) {
					currentMenu = vehicleMenu;
					previousMenuForward = errorsMenu;

					previousMenuBack = systemMenu;
					_menuChanged = true;
					backward = false;
					return;
				}
				if (currentMenu == bluetoothMenu && previousMenuForward == systemMenu) {
					currentMenu = errorsMenu;
					previousMenuForward = bluetoothMenu;

					previousMenuBack = vehicleMenu;
					_menuChanged = true;
					backward = false;
					return;
				}
				if (currentMenu == systemMenu && previousMenuForward == vehicleMenu) {
					currentMenu = bluetoothMenu;
					previousMenuForward = systemMenu;

					previousMenuBack = errorsMenu;
					_menuChanged = true;
					backward = false;
					return;
				}

			}
			if (back == true) {
				page_entry = true;
				inSettings = false;
				selection_UI(front);
				_menupage = 0;
				back = false;
			}


		}
		switch (currentMenu) {
		case vehicleMenu:
			vehicle_page();
			break;
		case systemMenu:
			system_page();
			break;
		case bluetoothMenu:
			bluetooth_page();
			break;
		case errorsMenu:
			errors_page();
			break;
		default:
			break;
		}


		return;
	}

	if (forward == true) {
		currentPage = front;
		page_entry = true;
		forward = false;
		_menupage = 0;
		_trasmitGlobal = Disengage_Page;
		backward = false;
		return;
	}

	if (backward == true) {
		currentPage = info;
		page_entry = true;
		forward = false;
		_menupage = 0;
		backward = false;
		return;
	}

}

void vehicle_page(void) {
	if (!(inVehicleMenu)) {
		if (okay == true) {
			menuAccess = true;
			inVehicleMenu = true;
			inTheMenu = true;
			okay = false;
			return;
		}
	} else {
		if (subMenuCounter>2) {
			if (inTheMenu) {
				inTheMenu = false;
				//settings_UI(vehicleMenu);
			}
			subMenuCounter = 0;
		}
		settings_UI(vehicleMenu,10);


		if (back == true) {
			menuAccess = false;
			inVehicleMenu = false;
			_menuChanged = true;
			back = false;
		}
	}
}
void system_page(void) {
	if (!(inSystemMenu)) {
		if (okay == true) {
			menuAccess = true;
			inSystemMenu = true;
			inTheMenu = true;
			okay = false;
			currentSubMenu = 0;
			previousSubMenuBack = 1;
			previousSubMenuForward = 1;
			return;
		}
	} else {
		if (subMenuCounter>2) {
			if (inTheMenu) {
				inTheMenu = false;
				//settings_UI(systemMenu);
			}
			subMenuCounter = 0;
		}
		settings_UI(systemMenu,currentSubMenu);
		//Time Settings Menu
		if (!inTimeSettings) {
			if (forward == true) {

				if (currentSubMenu == 0 && previousSubMenuBack == 1) {
					currentSubMenu = 1;
					previousSubMenuForward = 0;
					previousSubMenuBack = 0;
					//_menuChanged = true;
					forward = false;
					return;
				}
				if (currentSubMenu == 1 && previousSubMenuBack == 0) {
					currentSubMenu = 0;
					previousSubMenuForward = 1;
					previousSubMenuBack = 1;
					//_menuChanged = true;
					forward = false;
					return;
				}
			}
			if (backward == true) {
				if (currentSubMenu == 0 && previousSubMenuForward == 1) {
					currentSubMenu = 1;
					previousSubMenuForward = 0;

					previousSubMenuBack = 0;
					//_menuChanged = true;
					backward = false;
					return;
				}
				if (currentSubMenu == 1 && previousSubMenuForward == 0) {
					currentSubMenu = 0;
					previousSubMenuForward = 1;

					previousSubMenuBack = 1;
					//_menuChanged = true;
					backward = false;
					return;
				}

			}
			if (okay) {
				inTimeSettings = true;
				okay = false;
				return;
			}

		}
		else
		{
			if (okay) {
				okay = false;
				if (vpCounter == 3) {
					currentSubMenu = vpCounter;
					vpCounter = 4;
					return;
				}
				if (vpCounter == 4) {
					currentSubMenu = vpCounter;
					vpCounter = 3;
					return;
				}
			}
			if (forward) {
			forward = false;
				if (vpCounter == 3) {
					timerSetValueH++;
				}
				if (vpCounter == 4) {
					timerSetValueMin++;
				}
			}

			if (backward) {
			backward = false;
			if (vpCounter == 3) {
				timerSetValueH--;
			}
			if (vpCounter == 4) {
				timerSetValueMin--;
			}

				if (timerSetValueH == 0) {
					timerSetValueH = 23;
				}
				if (timerSetValueMin == 0) {
					timerSetValueMin = 59;
				}
			}

			if (timerSetValueH > 24) {
				timerSetValueH = 0;
			}

			if (timerSetValueMin > 60) {
				timerSetValueMin = 0;
			}


			if (back) {
				inTimeSettings = false;
				//Trasmit time
				currentSubMenu = 0;
				previousSubMenuForward = 1;
				previousSubMenuBack = 1;
				timeChanged = true;
				back = false;
			}


		}

//		if (!(inSystemSubMenu)) {
//			if (okay == true) {
//				inSystemSubMenu = true;
//				okay = false;
//			}
//		} else {
//
//		}
	}

	if (back == true) {
		menuAccess = false;
		inSystemMenu = false;
		_menuChanged = true;
		back = false;

	}
}

void bluetooth_page(void) {
	if (!(inBluetoothMenu)) {
		if (okay == true) {
			menuAccess = true;
			inBluetoothMenu = true;
			inTheMenu = true;
			okay = false;
		}
	} else {
		if (subMenuCounter>2) {
			if (inTheMenu) {
				inTheMenu = false;
				//settings_UI(bluetoothMenu);
			}
			subMenuCounter = 0;
		}
		settings_UI(bluetoothMenu,10);



		if (back == true) {
			menuAccess = false;
			inBluetoothMenu = false;
			_menuChanged = true;
			back = false;
		}
	}
}
void errors_page(void) {
	if (!(inErrorsMenu)) {
		if (okay == true) {
			menuAccess = true;
			inErrorsMenu = true;
			inTheMenu = true;
			okay = false;
		}
	} else {
		if (subMenuCounter>2) {
			if (inTheMenu) {
				inTheMenu = false;
				//settings_UI(errorsMenu);
			}
			subMenuCounter = 0;
		}
		settings_UI(errorsMenu,10);



		if (back == true) {
			menuAccess = false;
			inErrorsMenu = false;
			_menuChanged = true;
			back = false;
		}
	}
}

