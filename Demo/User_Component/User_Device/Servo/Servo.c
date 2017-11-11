/*
 * Servo.c
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »ÝÆÕ
 */
#include "Servo.h"


LDD_TDeviceDataPtr myServo;
int16_t Servo_center=4370;
//4100	4750 //5400

void Servo_Init(void)
{
	myServo = PWMServo_Init(NULL);
}

void Servo_SetVal(int32_t Val)
{
	if(Val>5600)Val=5600;
	if(Val<4500)Val=4500;
	PWMServo_SetRatio16(myServo,SERVO_MAX - Val);
}

void Servo_Enable(void)
{
PWMServo_Enable(myServo);
}
