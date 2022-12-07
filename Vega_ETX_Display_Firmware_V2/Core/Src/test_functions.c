/*
 * test_functions.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Akila
 */
#include"test_function.h"


#define LED_1_ON HAL_GPIO_WritePin(GPIOC, LED_1_Pin, GPIO_PIN_SET)
#define LED_1_OFF HAL_GPIO_WritePin(GPIOC, LED_1_Pin, GPIO_PIN_RESET)
#define LED_2_ON HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET)
#define LED_2_OFF HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_RESET)

#define TEST_DELAY HAL_Delay(500);

uint8_t message = 0;

void buttonTest(void) {
	setInputs();

	if (nav_SW1) {
		nav_SW1 = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (nav_SW2) {
		nav_SW2 = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (nav_SW3) {
		nav_SW3 = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (nav_SW4) {
		nav_SW4 = false;
		LED_2_ON;
		TEST_DELAY
		;
		LED_2_OFF;
	}
	if (nav_SW5) {
		nav_SW5 = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}

	if (hand_Break) {
		hand_Break = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (door) {
		door = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (turn_L) {
		turn_L = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (turn_R) {
		turn_R = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (high_Beam) {
		high_Beam = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}
	if (park) {
		park = false;
		LED_1_ON;
		TEST_DELAY
		;
		LED_1_OFF;
	}

}

void canTest(void) {
		currentstate = 1;
		accessory = 0;
		readytodrive = 1;
		start = 1;
		buzzer = 0;
		trip_ack = 0;
		mode_override = 0;
		mode_evcu = 1;
		chargerconn = 0;
		shutdown = 0;

		//ID 0
		power = 10;
		test_speed = 50;
		rpm_meter = 1500;
}

void uartTest(void) {

}
