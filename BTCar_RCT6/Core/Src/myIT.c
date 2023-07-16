#include "stm32f1xx.h"
#include "gpio.h"
#include "CarMove.h"
#include "OpticalSensor.h"
#include <stdio.h>

extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart1;
extern uint8_t findLineStart;

uint8_t pData;

void commandStatusMachine(uint8_t currentCmd);

//定时器中断的回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIM_PeriodElapsedCallback could be implemented in the user file
   */
  if(htim->Instance==TIM6){
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
  }
}

//串口中断的回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
	{
		HAL_UART_Transmit(&huart1,&pData,1,0xFFFF);
        commandStatusMachine(pData);
        HAL_UART_Receive_IT(&huart1,&pData,1);      
	}
}

//接收命令的状态机
void commandStatusMachine(uint8_t currentCmd){
    static uint8_t currentStatus=0;
    static uint8_t currentTarget=0;
    switch (currentStatus)
    {
    case 0:
      if(currentCmd=='@') {
        currentTarget=0;//清零

        currentStatus=1;
      }
      else currentStatus=0;
      break;
    
    case 1:
      if(currentCmd=='M' || currentCmd=='A'){
        currentTarget=currentCmd;
        
        currentStatus=2;
      }
      else currentStatus=0;
      break;
    case 2:
      if(currentCmd=='L'){
        if(currentTarget=='M') CarMove_Left();
        if(currentTarget=='A') Servo_ChangeAngle(-25);
        
      }
      if(currentCmd=='R'){
        if(currentTarget=='M') CarMove_Right();
        if(currentTarget=='A') Servo_ChangeAngle(25);
        
      }
      if(currentCmd=='U'){
        CarMove_Ahead();
      }
      if(currentCmd=='D'){
        CarMove_Back();
      }

      //测试
      if(currentCmd=='T'){
        findLineStart=!findLineStart;
        if(findLineStart) printf("start to find line\n");
      }
      if(currentCmd=='F'){
        OpticalSensor_CheckAll();
      }

      //�????????后还是清�????????
      currentStatus=0;
      break;
    default:
      break;
    }
}
