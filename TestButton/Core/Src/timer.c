/*
 * timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */

#include "timer.h"
int timer1Counter = 0;
int timer1Flag = 0;
int timer2Counter = 0;
int timer2Flag = 0;
int timer3Counter = 0;
int timer3Flag = 0;
void setTimer1(int duration){
	timer1Counter = duration/TICK;
	timer1Flag = 0;
}
void setTimer2(int duration){
	timer2Counter = duration/TICK;
	timer2Flag = 0;
}
void setTimer3(int duration){
	timer3Counter = duration/TICK;
	timer3Flag = 0;
}
void timerRun(){
	if(timer1Counter > 0){
		timer1Counter--;
		if(timer1Counter <= 0){
			timer1Flag = 1;
		}
	}
	if(timer2Counter > 0){
		timer2Counter--;
		if(timer2Counter <= 0){
			timer2Flag = 1;
		}
	}
	if(timer3Counter > 0){
		timer3Counter--;
		if(timer3Counter <= 0){
			timer3Flag = 1;
		}
	}
}
