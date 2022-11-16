/*
 * fsm_full.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "fsm_full.h"

int CountSecondForBlink = 7;
/*Defaul counter for timer 3*/
#define TIMER3_COUNTER_INIT 25
/*State of row traffic light*/
int state_row = AUTO_RED;
/*State of col traffic light*/
int state_col = AUTO_GREEN;
/*Ratio to scale counter timer 3, 8x25 = 200 ~ 2s*/
int ratio_for_blink = 8;
/*to SETTING mode flag*/
int toSETTING = 0;
/*Value display on 7seg in NORMAL_MODE*/
int countDownTimeCol = 0;
int countDownTimeRow = 5;
/*Time for traffic light*/
int redTime = 5;
int greenTime = 3;
int amberTime = 2;
/*register to store value when SET button is pressed*/
int registerTimeForChange;
/*Change value of register above*/
void changeNum(){
	registerTimeForChange++;
	if(registerTimeForChange >= 100) registerTimeForChange = 1;
}
/*Display led 7seg, set timer,... */
void fsm_full_task_row(){
	  /*Set timer2 ~ 1s*/
	  if(timer2Flag == 1){
		  setTimer2(100);
	  }
	  /*Check state and display Traffic light leds*/
	  if(state_row != BLINK_RED &&
			  state_row != BLINK_GREEN &&
			  state_row != BLINK_AMBER){
		  turnOnLedCol(state_col);
		  turnOnLedRow(state_row);
	  }
	  /*Update value for Buffer 7 seg*/
	  updateBuffer7SEG();
	  if(timer3Flag == 1){
		  /*Sweep 4 7seg led with Sweeping Frequence = 1Hz*/
		  sweep7SEG(index_led++);
		  CountSecondForBlink++;
		  CountSecondForBlink %= ratio_for_blink;
		  /*Turn on traffic light leds in 1s */
		  if(CountSecondForBlink >= (ratio_for_blink/2)){
			  blinkLED(state_row);
		  }
		  /*Turn off traffic light leds in 1s*/
		  else if(state_row == BLINK_AMBER ||
				  state_row == BLINK_RED ||
				  state_row == BLINK_GREEN){
					  turnOffLED();
		  }
		  setTimer3(TIMER3_COUNTER_INIT);
	  }
}
/*fsm for row*/
void fsm_full_row(){
	switch(state_row){
	case AUTO_RED:
		if(toSETTING == 0){
			if(timer2Flag == 1){
				countDownTimeRow--;
				countDownTimeCol--;
				/*Time out move to next state*/
				if(countDownTimeRow <= 0){
					state_row = AUTO_GREEN;
					countDownTimeRow = greenTime;
				}
			}
		}
		else{
			/*If button Mode is pressed (toSETTING == 1), move to BLINK_RED mode*/
			state_row = BLINK_RED;
			state_col = BLINK_RED;
			/*assign redTime value to register*/
			registerTimeForChange = redTime;
			toSETTING = 0;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		break;
	case AUTO_GREEN:
		if(toSETTING == 0){
			if(timer2Flag == 1){
				countDownTimeRow--;
				countDownTimeCol--;
				/*Time out move to next state*/
				if(countDownTimeRow <= 0){
					state_row = AUTO_AMBER;
					countDownTimeRow = amberTime;
				}
			}
		}
		else{
			/*If button Mode is pressed (toSETTING == 1), move to BLINK_RED mode*/
			state_row = BLINK_RED;
			state_col = BLINK_RED;
			/*assign redTime value to register*/
			registerTimeForChange = redTime;
			toSETTING = 0;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		break;
	case AUTO_AMBER:
		if(toSETTING == 0){
			if(timer2Flag == 1){
				countDownTimeRow--;
				countDownTimeCol--;
				/*Time out move to next state*/
				if(countDownTimeRow <= 0){
					state_row = AUTO_RED;
					countDownTimeRow = redTime;
				}
			}
		}
		else{
			/*If button Mode is pressed (toSETTING == 1), move to BLINK_RED mode*/
			state_row = BLINK_RED;
			state_col = BLINK_RED;
			/*assign redTime value to register*/
			registerTimeForChange = redTime;
			toSETTING = 0;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		break;
	case BLINK_RED:
		if(buttonState[0] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			setTimer1(BUTTON_DELAY_TIME*10);
			buttonState[0] = NORMAL_BUTTON;
			/*Move to BLINK_AMBER mode*/
			state_row = BLINK_AMBER;
			state_col = BLINK_AMBER;
			/*assign amberTime value to register*/
			registerTimeForChange = amberTime;
			toSETTING = 0;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(buttonState[1] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[1] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Increase value in register*/
			changeNum();
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(buttonState[2] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[2] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Assign value on register to traffic light time to SAVE*/
			redTime = registerTimeForChange;
			setTimer2(SETTING_TIME);
		}
		if(timer2Flag == 1){
			/*Time out, move to default state: AUTO_RED (row), AUTO_GREEN (col)*/
			state_row = AUTO_RED;
			state_col = AUTO_GREEN;
			countDownTimeRow = redTime;
			countDownTimeCol = greenTime;
		}
		break;
	case BLINK_AMBER:
		if(buttonState[0] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			setTimer1(BUTTON_DELAY_TIME*10);
			buttonState[0] = NORMAL_BUTTON;
			/*Move to BLINK_GREEN mode*/
			state_row = BLINK_GREEN;
			state_col = BLINK_GREEN;
			/*assign greenTime value to register*/
			registerTimeForChange = greenTime;
			toSETTING = 0;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(buttonState[1] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[1] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Increase value in register*/
			changeNum();
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(buttonState[2] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.1s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[2] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Assign value on register to traffic light time to SAVE*/
			amberTime = registerTimeForChange;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(timer2Flag == 1){
			/*Time out, move to default state: AUTO_RED (row), AUTO_GREEN (col)*/
			state_row = AUTO_RED;
			state_col = AUTO_GREEN;
			countDownTimeRow = redTime;
			countDownTimeCol = greenTime;
		}
		break;
	case BLINK_GREEN:
		if(buttonState[0] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			setTimer1(BUTTON_DELAY_TIME*20);
			buttonState[0] = NORMAL_BUTTON;
			state_row = AUTO_RED;
			state_col = AUTO_GREEN;
			/*assign redTime value to register*/
			registerTimeForChange = redTime;
			/*reset Count Down Time to default*/
			countDownTimeRow = redTime;
			countDownTimeCol = greenTime;
			toSETTING = 0;
			/*Set timer2 to 100 ~ 1s*/
			index_led = 0;
			setTimer3(1);
			setTimer2(100);
		}
		if(buttonState[1] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[1] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Increase value in register*/
			changeNum();
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(buttonState[2] == PRESS_BUTTON){
			/*set Timer1 50 ~ 0.5s,button will press every 0.5s if long-press, and reset button state to NORMAL*/
			buttonState[2] = NORMAL_BUTTON;
			setTimer1(BUTTON_DELAY_TIME*10);
			/*Assign value on register to traffic light time to SAVE*/
			greenTime = registerTimeForChange;
			/*Set timer2 to 1000 ~ 10s*/
			setTimer2(SETTING_TIME);
		}
		if(timer2Flag == 1){
			/*Time out, move to default state: AUTO_RED (row), AUTO_GREEN (col)*/
			state_row = AUTO_RED;
			state_col = AUTO_GREEN;
			countDownTimeRow = redTime;
			countDownTimeCol = greenTime;
		}
		break;
	default:
		state_row= AUTO_RED;
		state_row = AUTO_GREEN;
		break;
	}
	fsm_full_task_row();
}
void fsm_full_col(){
	switch(state_col){
	case AUTO_RED:
		if(countDownTimeCol <= 0){
			state_col = AUTO_GREEN;
			countDownTimeCol = greenTime;
		}
		break;
	case AUTO_GREEN:
		if(countDownTimeCol <= 0){
			state_col = AUTO_AMBER;
			countDownTimeCol = amberTime;
		}
		break;
	case AUTO_AMBER:
		if(countDownTimeCol <= 0){
			state_col = AUTO_RED;
			countDownTimeCol = redTime;
		}
		break;
		/*Below states depend on Row*/
	case BLINK_RED:
		break;
	case BLINK_AMBER:
		break;
	case BLINK_GREEN:
		break;
	default:
		break;
	}
}



