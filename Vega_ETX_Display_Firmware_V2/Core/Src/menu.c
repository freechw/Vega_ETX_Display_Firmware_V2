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
		_realTimeData = true;
		_oneTimeData = true;
		previousPage = front;
		break;
	case trip:
		trip_mainPage();
		_realTimeData = true;
		_oneTimeData = true;
		previousPage = trip;
		break;
	case after_charge:
		after_charge_mainPage();
		_realTimeData = true;
		_oneTimeData = true;
		previousPage = after_charge;
		break;
	case info:
		info_mainPage();
		_realTimeData = true;
		_oneTimeData = true;
		previousPage = info;
		break;
	case settings:
		settings_mainPage();
		_realTimeData = true;
		previousPage = settings;
		break;
	default:
		break;
	}

}

void front_mainPage(void) {
	if (page_entry) {
		page_entry = false;
		currentMode = modeCleared;
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

		currentPage = settings;
		page_entry = true;
		forward = false;
		_menupage = 0;
		backward = false;
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
			vehicleInfo_UI(currentMenu);
		}
		if (forward == true) {
			//currentMenu++;
			if (currentMenu == infoinv && previousMenuBack == infomot) {
				currentMenu = infobat;
				previousMenuBack = infoinv;
				previousMenuForward = infomot;
				forward = false;
				return;
			}

			if (currentMenu == infobat && previousMenuBack == infoinv) {
				currentMenu = infomot;
				previousMenuBack = infobat;
				previousMenuForward = infoinv;
				forward = false;
				return;
			}

			if (currentMenu == infomot && previousMenuBack == infobat) {
				currentMenu = infoinv;
				previousMenuBack = infomot;
				previousMenuForward = infobat;
				forward = false;
				return;
			}

		}

		if (backward == true) {
			//currentMenu--;
			if (currentMenu == infobat && previousMenuForward == infomot) {
				currentMenu = infoinv;
				previousMenuForward = infobat;
				previousMenuBack = infomot;
				backward = false;
				return;
			}

			if (currentMenu == infoinv && previousMenuForward == infobat) {
				currentMenu = infomot;
				previousMenuForward = infoinv;
				previousMenuBack = infobat;
				backward = false;
				return;
			}

			if (currentMenu == infomot && previousMenuForward == infoinv) {
				currentMenu = infobat;
				previousMenuForward = infomot;
				previousMenuBack = infoinv;
				backward = false;
				return;
			}

		}

		if (back == true) {
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

	selection_UI(front);
	//drivePageSetter(settings);
	_drivePageSet = settings;
	_trasmitGlobal = MainMenuPages;


	if (!(inSettings)) {
		if (okay == true) {
			inSettings = true;
			okay = false;
		}
	}

	else {
		if (page_entry == true) {
			currentMenu = vehicleMenu;
			page_entry = false;
		}

		if (!(menuAccess)) {
			selection_UI(currentMenu);

			if (forward == true) {
				currentMenu--;
				if (currentMenu <= 7) {
					currentMenu = errorsMenu;
				}
				forward = false;
				//return;
			}

			if (backward == true) {
				currentMenu++;
				if (currentMenu >= 12) {
					currentMenu = vehicleMenu;
				}
				backward = false;
				//return;

			}
		}
if (!inVehicleMenu || !inSystemMenu || !inErrorsMenu || !inBluetoothMenu) {

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

		if (back == true) {
			page_entry = true;
			inSettings = false;
			_menupage = 0;
			back = false;
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
	}

	if (backward == true) {
		currentPage = info;
		page_entry = true;
		forward = false;
		_menupage = 0;
		backward = false;
	}

}

void vehicle_page(void) {
	if (!(inVehicleMenu)) {
		if (okay == true) {
			menuAccess = true;
			inVehicleMenu = true;
			okay = false;
		}
	} else {
		settings_UI(vehicleMenu);

		if (back == true) {
			menuAccess = false;
			inVehicleMenu = false;
			back = false;
		}
	}
}
void system_page(void) {
	if (!(inSystemMenu)) {
		if (okay == true) {
			menuAccess = true;
			inSystemMenu = true;
			okay = false;
		}
	} else {
		settings_UI(systemMenu);
	}

	if (back == true) {
		menuAccess = false;
		inSystemMenu = false;
		back = false;

	}
}

void bluetooth_page(void) {
	if (!(inBluetoothMenu)) {
		if (okay == true) {
			menuAccess = true;
			inBluetoothMenu = true;
			okay = false;
		}
	} else {
		settings_UI(bluetoothMenu);

		if (back == true) {
			menuAccess = false;
			inBluetoothMenu = false;
			back = false;
		}
	}
}
void errors_page(void) {
	if (!(inErrorsMenu)) {
		if (okay == true) {
			menuAccess = true;
			inErrorsMenu = true;
			okay = false;
		}
	} else {
		settings_UI(errorsMenu);

		if (back == true) {
			menuAccess = false;
			inErrorsMenu = false;
			back = false;
		}
	}
}
