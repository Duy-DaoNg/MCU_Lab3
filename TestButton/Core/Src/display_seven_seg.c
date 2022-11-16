/*
 * led_seven_seg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "display_seven_seg.h"
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};
void turnOnLedCol(int state){
	switch(state){
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, SET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, SET);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, SET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, SET);
		break;
	case AUTO_AMBER:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, SET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, SET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, RESET);
		break;
	}
}
void turnOnLedRow(int state){
	switch(state){
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, SET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, SET);
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, SET);
		break;
	case AUTO_AMBER:
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, SET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, RESET);
		break;
	}
}
void blinkLED(int state){
	switch(state){
	case BLINK_RED:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, SET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, SET);
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, SET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, SET);
		break;
	case BLINK_GREEN:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, SET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, SET);
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, SET);
		break;
	case BLINK_AMBER:
		HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, SET);
		HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, SET);
		HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, RESET);
		HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, SET);
		HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, RESET);
		break;
	}
}
void turnOffLED(){
	HAL_GPIO_WritePin(RED_COL_GPIO_Port, RED_COL_Pin, SET);
	HAL_GPIO_WritePin(GREEN_COL_GPIO_Port,GREEN_COL_Pin, SET);
	HAL_GPIO_WritePin(AMBER_COL_GPIO_Port, AMBER_COL_Pin, SET);
	HAL_GPIO_WritePin(RED_ROW_GPIO_Port, RED_ROW_Pin, SET);
	HAL_GPIO_WritePin(GREEN_ROW_GPIO_Port,GREEN_ROW_Pin, SET);
	HAL_GPIO_WritePin(AMBER_ROW_GPIO_Port, AMBER_ROW_Pin, SET);
}

void display7SEG(int num){
	  if(num == 0){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 1){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, SET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 2){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, SET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 3){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 4){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, SET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 5){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, SET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 6){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, SET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 7){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, SET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, SET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, SET);
	  }
	  if(num == 8){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
	  if(num == 9){
		  HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, SET);
		  HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, RESET);
		  HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, RESET);
	  }
}
void sweep7SEG(int index){
	index = index % MAX_LED;
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[1]);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[2]);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEG(led_buffer[3]);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		break;
	default:
		index = 0;
		break;
	}
}
void updateBuffer7SEG(){
	if(state_row == AUTO_RED ||
			state_row == AUTO_GREEN ||
			state_row == AUTO_AMBER){
		/*NORMAL mode display countDownTime*/
		led_buffer[0] = countDownTimeRow/10;
		led_buffer[1] = countDownTimeRow%10;
		led_buffer[2] = countDownTimeCol/10;
		led_buffer[3] = countDownTimeCol%10;
	}
	else {
		/*SETTING mode display register value and mode number*/
		led_buffer[0] = registerTimeForChange/10;
		led_buffer[1] = registerTimeForChange%10;
		switch(state_row){
		case BLINK_RED:
			led_buffer[2] = 0;
			led_buffer[3] = 2;
			break;
		case BLINK_GREEN:
			led_buffer[2] = 0;
			led_buffer[3] = 4;
			break;
		case BLINK_AMBER:
			led_buffer[2] = 0;
			led_buffer[3] = 3;
			break;
		}
	}
}
