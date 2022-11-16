/*
 * led_senven_seg.h
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#ifndef INC_DISPLAY_SEVEN_SEG_H_
#define INC_DISPLAY_SEVEN_SEG_H_

#include "main.h"
#include "fsm_full.h"

extern int led_buffer [4];
extern int index_led;
void display7SEG(int num);
void sweep7SEG(int index);
void updateBuffer7SEG();
void turnOnLedRow(int state);
void turnOnLedCol(int state);
void blinkLED(int state);
void turnOffLED();
#endif /* INC_DISPLAY_SEVEN_SEG_H_ */
