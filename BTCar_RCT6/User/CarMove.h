#ifndef _CARMOVE_H_
#define _CARMOVE_H_

#include "Motor.h"
#include "Servo.h"

#define CARMOVE_SPEED_PRCISE 25

/*
速度范围
-100-100
*/

///速度增加
void CarMove_Ahead(void);
///速度减少
void CarMove_Back(void);

///未实现
void CarMove_Left(void);
void CarMove_Right(void);

//自动转向,每次调用的间隔最好为20ms
void CarMove_FindLine(void);

#endif 
