#ifndef _OpticalSenor_H_
#define _OpticalSenor_H_

#include "stm32f1xx.h"
#include<stdio.h>

//最左边是X4
#define OPTICAL_PIN_PORT GPIOC
#define OPTICAL_PIN_X1 GPIO_PIN_6
#define OPTICAL_PIN_X2 GPIO_PIN_7
#define OPTICAL_PIN_X3 GPIO_PIN_8
#define OPTICAL_PIN_X4 GPIO_PIN_9

/// @brief 获取循迹传感器的值
/// @param OPTICAL_PIN 指定具体是哪个PIN
/// @return 0/1 在黑线上时返回0
uint8_t OpticalSensor_getLevel(uint16_t OPTICAL_PIN);

void OpticalSensor_CheckAll(void);

#endif
