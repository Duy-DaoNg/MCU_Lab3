/*
 * timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#define TICK	1
int timer1Counter;
int timer1Flag;
int timer2Counter;
int timer2Flag;
int timer3Counter;
int timer3Flag;


void timerRun();
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

#endif /* INC_TIMER_H_ */
