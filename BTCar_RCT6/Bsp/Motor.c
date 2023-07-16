#include "Motor.h"
#include "main.h"
extern TIM_HandleTypeDef htim3;


void Motor_Init(void){

    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0); 
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,0);

    //TB6612 后轮
    HAL_GPIO_WritePin(GPIOA,BACKMOTOR_STBY_Pin,GPIO_PIN_SET);//STBY
    //TB6612 前轮
    HAL_GPIO_WritePin(GPIOA,FRONTMOTOR_STBY_Pin,GPIO_PIN_SET);//STBY

    
}

void Motor_SetMode(uint8_t towards){
    if(towards==MOTOR_TOWARD_FRONT){
      //后左
      HAL_GPIO_WritePin(GPIOC,MOTOR_1_IN1_Pin,GPIO_PIN_RESET);//AIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_1_IN2_Pin,GPIO_PIN_SET);
		  //后右
      HAL_GPIO_WritePin(GPIOC,MOTOR_2_IN1_Pin,GPIO_PIN_SET);//BIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_2_IN2_Pin,GPIO_PIN_RESET);
      //前左
      HAL_GPIO_WritePin(GPIOC,MOTOR_3_IN1_Pin,GPIO_PIN_RESET);//AIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_3_IN2_Pin,GPIO_PIN_SET);
      //前右
      HAL_GPIO_WritePin(GPIOC,MOTOR_4_IN1_Pin,GPIO_PIN_RESET);//BIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_4_IN2_Pin,GPIO_PIN_SET);
    }
    if(towards==MOTOR_TOWARD_BACK){
      HAL_GPIO_WritePin(GPIOC,MOTOR_1_IN1_Pin,GPIO_PIN_SET);//AIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_1_IN2_Pin,GPIO_PIN_RESET);
		  
      HAL_GPIO_WritePin(GPIOC,MOTOR_2_IN1_Pin,GPIO_PIN_RESET);//BIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_2_IN2_Pin,GPIO_PIN_SET);

      HAL_GPIO_WritePin(GPIOC,MOTOR_3_IN1_Pin,GPIO_PIN_SET);//AIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_3_IN2_Pin,GPIO_PIN_RESET);

      HAL_GPIO_WritePin(GPIOC,MOTOR_4_IN1_Pin,GPIO_PIN_SET);//BIN1
      HAL_GPIO_WritePin(GPIOC,MOTOR_4_IN2_Pin,GPIO_PIN_RESET);
    }
}
void Motor_SetPWM(int16_t pwmVal){
    //正转or反转
    if(pwmVal<0) {
      Motor_SetMode(MOTOR_TOWARD_BACK);
      pwmVal=-pwmVal;
    }
    else Motor_SetMode(MOTOR_TOWARD_FRONT);

    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,pwmVal*10);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,pwmVal*10);//不要减一，即便超过ARR就相当于PWM全有效
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,pwmVal*10);
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,pwmVal*10);
}
