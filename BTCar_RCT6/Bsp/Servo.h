#ifndef _SERVO_H_
#define _SERVO_H_

#include "stm32f1xx.h"


/// @brief 打开定时器
/// @param  
void Servo_Init(void);

/// @category private
/// @brief 设置pwm波形 
/// @param pwmVal ARR=1800 但按照舵机的范围应该为45-225  
//void Servo_SetPWM(uint8_t pwmVal);

/// @brief 改变舵机角度
/// @param angle 
void Servo_SetAngle(int16_t angle);

/// @brief 改变角度，函数将自动判定改动合法与否
/// @param x 为改变值，-128-127之间 
void Servo_ChangeAngle(int16_t x);
#endif
