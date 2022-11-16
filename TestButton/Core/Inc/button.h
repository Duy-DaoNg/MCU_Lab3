/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

// Global
#define NO_OF_BUTTONS		3
////////////////
#define BUTTON_PRESSED		0
#define BUTTON_RELEASED 	1
#define BUTTON_PORT			GPIOB
uint16_t INPUT_BUTTON[NO_OF_BUTTONS];


void button_reading(void);
int isButtonPressed(int buttonNumber);

#endif /* INC_BUTTON_H_ */
