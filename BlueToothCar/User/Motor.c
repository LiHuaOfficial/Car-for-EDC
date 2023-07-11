#include "Motor.h"

extern TIM_HandleTypeDef htim2;

void Motor_Init(void){
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);

    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,0);
}

void Motor_SetPWM(uint8_t pwmVal){
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,(uint32_t)pwmVal*10);
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint32_t)pwmVal*10);
}
