/*
 * fsm_button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_
#include "button.h"
#include "timer.h"
#include "fsm_full.h"
//Global
#define NORMAL_BUTTON 	101
#define PRESS_BUTTON 	102

extern int buttonState[NO_OF_BUTTONS];
////////////////
#define BUTTON_DELAY_TIME 5
void fsm_button();

#endif /* INC_FSM_BUTTON_H_ */
