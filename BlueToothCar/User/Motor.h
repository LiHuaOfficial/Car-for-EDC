#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "stm32f1xx.h"

/// @brief 打开定时器，设置占空比为0
///（pwm mode 1即为小于ccr为有效电平）
void Motor_Init(void);

/// @brief 修改PWM占空比
/// @param pwmVal 传入的PWM占空比 1~100
void Motor_SetPWM(uint8_t pwmVal);


#endif
