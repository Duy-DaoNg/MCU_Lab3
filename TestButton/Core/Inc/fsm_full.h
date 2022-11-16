/*
 * fsm_full.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef INC_FSM_FULL_H_
#define INC_FSM_FULL_H_

#include "button.h"
#include "fsm_button.h"
#include "timer.h"
#include "display_seven_seg.h"
#include "main.h"

//uint16_t stateOf_FSM_FULL[2];
int state_row;
int state_col;
int countDownTimeRow;
int countDownTimeCol;
#define SETTING_TIME	1000
#define COUNT_DOWN 		911
#define SETTING 		119

#define INIT			199
#define AUTO_RED 		200
#define AUTO_GREEN 		201
#define AUTO_AMBER 		202
#define BLINK_RED 		203
#define BLINK_GREEN 	204
#define BLINK_AMBER 	205

int redTime;
int greenTime;
int amberTime;
int registerTimeForChange;
int toSETTING;
//int countDownTime[2];

void fsm_full_row();
void fsm_full_col();
void fsm_full_task_row();

#endif /* INC_FSM_FULL_H_ */
