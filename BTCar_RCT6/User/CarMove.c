#include "CarMove.h"
#include <stdio.h>
#include "OpticalSensor.h"

int8_t currentSpeed=0;
uint8_t findLineStart=0;
extern TIM_HandleTypeDef htim3;

void CarMove_Ahead(){
    if(currentSpeed+CARMOVE_SPEED_PRCISE<=100){
        currentSpeed+=CARMOVE_SPEED_PRCISE;
        Motor_SetPWM(currentSpeed);
    }
    printf("Car Move Ahead speed:%d\n",currentSpeed);
    printf("CCR :%d\n",__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1));
}   

void CarMove_Back(){
    if(currentSpeed-CARMOVE_SPEED_PRCISE>=-100){
        currentSpeed-=CARMOVE_SPEED_PRCISE;
        Motor_SetPWM(currentSpeed);
    }
    printf("Car Move Back speed:%d\n",currentSpeed);
    printf("CCR :%d\n",__HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_1));
}  

void CarMove_Left(){
    printf("Car Move Left\n");
}  

void CarMove_Right(){
    printf("Car Move Right\n");
}

void CarMove_FindLine(){
    if(findLineStart){//默认不开始，防止损坏
            static uint8_t now_area=0,last_area=0;
    //复制的，后续调整
    unsigned char SENSOR0, SENSOR1, SENSOR2, SENSOR3;
	
    SENSOR0 = OpticalSensor_getLevel(OPTICAL_PIN_X2);
    SENSOR1 = OpticalSensor_getLevel(OPTICAL_PIN_X1);   
    SENSOR2 = OpticalSensor_getLevel(OPTICAL_PIN_X3);
    SENSOR3 = OpticalSensor_getLevel(OPTICAL_PIN_X4);  
    //在黑线上时返回0
    //Area 0,车身完全偏离跑道 向左打大角
    if (!SENSOR0 && SENSOR1 && SENSOR2 && SENSOR3)
    {
        now_area = 0;
        Servo_SetAngle(40);
    }
    //Area 2,传感器检测到左小弯，舵机向左打小角
    else if (SENSOR0 && !SENSOR1 && SENSOR2 && SENSOR3)
    {
        now_area = 2;
        Servo_SetAngle(65);
    }
    //Area 3,传感器检测到直线
    else if (SENSOR0 && !SENSOR1 && !SENSOR2 && SENSOR3)
    {
        now_area = 3;
        Servo_SetAngle(90);
    }
    //Area 4,传感器检测到右小弯，舵机向右打小角
    else if (SENSOR0 && SENSOR1 && !SENSOR2 && SENSOR3)
    {
        now_area = 4;
        Servo_SetAngle(115);
    }
    //Area 6,车身完全偏离跑到， 向右打大角
    else if (SENSOR0 && SENSOR1 && SENSOR2 && !SENSOR3)
    {
        now_area = 6;
        Servo_SetAngle(140);
    }
    else if (SENSOR0 && SENSOR1 && SENSOR2 && SENSOR3)
    {
        //Area 1,传感器检测到左大弯，向左打大角
        if (last_area == 2)
        {
            now_area = 1;
            Servo_SetAngle(40);
        }
        //Area 5,传感器检测到右大弯，向右打大角
        else if (last_area == 4)
        {
            now_area = 5;
            Servo_SetAngle(140);
        }
    }
    last_area = now_area;
    }
}
