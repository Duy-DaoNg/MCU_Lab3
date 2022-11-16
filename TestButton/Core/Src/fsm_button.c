/*
 * fsm_button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */




#include "fsm_button.h"

/* buttonState: buffer for saving buttons State*/
int buttonState[NO_OF_BUTTONS] = {NORMAL_BUTTON,NORMAL_BUTTON,NORMAL_BUTTON};
void fsm_button(){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		switch(buttonState[i]){
		case NORMAL_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 1){
					buttonState[i] = PRESS_BUTTON;
					setTimer1(BUTTON_DELAY_TIME*4);
				}
			}
			break;
		case PRESS_BUTTON:
			if(timer1Flag == 1){
				if(isButtonPressed(i) == 0){
					if(i == 0) {toSETTING = SETTING;}
					buttonState[i] = NORMAL_BUTTON;
					setTimer1(BUTTON_DELAY_TIME*4);
				}
			}
		default:
			break;
		}
	}
}
