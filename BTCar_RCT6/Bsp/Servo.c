#include "Servo.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim2;
int16_t currentAngle=0;

void Servo_Init(void){
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);

    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);

    currentAngle=90;
    Servo_SetAngle(currentAngle);
}

void Servo_SetPWM(int16_t pwmVal){
    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,pwmVal);
}

void Servo_SetAngle(int16_t angle){
    currentAngle=angle;
    Servo_SetPWM(angle+45);
}

void Servo_ChangeAngle(int16_t x){
    printf("ready to change angle\n");
    
    //轮子最大角度，再大会损坏小车
    if((currentAngle+x) <= 140 && (currentAngle+x)>=40){
        currentAngle+=x;
        Servo_SetAngle(currentAngle);
        printf("set angle complete currentAngle:%d\n",currentAngle);
    }
}
