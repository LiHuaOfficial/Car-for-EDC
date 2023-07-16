/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_4_IN1_Pin GPIO_PIN_13
#define MOTOR_4_IN1_GPIO_Port GPIOC
#define MOTOR_4_IN2_Pin GPIO_PIN_14
#define MOTOR_4_IN2_GPIO_Port GPIOC
#define MOTOR_1_IN1_Pin GPIO_PIN_0
#define MOTOR_1_IN1_GPIO_Port GPIOC
#define MOTOR_1_IN2_Pin GPIO_PIN_1
#define MOTOR_1_IN2_GPIO_Port GPIOC
#define MOTOR_2_IN1_Pin GPIO_PIN_2
#define MOTOR_2_IN1_GPIO_Port GPIOC
#define MOTOR_2_IN2_Pin GPIO_PIN_3
#define MOTOR_2_IN2_GPIO_Port GPIOC
#define FRONTMOTOR_STBY_Pin GPIO_PIN_4
#define FRONTMOTOR_STBY_GPIO_Port GPIOA
#define BACKMOTOR_STBY_Pin GPIO_PIN_5
#define BACKMOTOR_STBY_GPIO_Port GPIOA
#define SERVO_IN_Pin GPIO_PIN_6
#define SERVO_IN_GPIO_Port GPIOA
#define MOTOR_3_IN1_Pin GPIO_PIN_4
#define MOTOR_3_IN1_GPIO_Port GPIOC
#define MOTOR_3_IN2_Pin GPIO_PIN_5
#define MOTOR_3_IN2_GPIO_Port GPIOC
#define LED_Pin GPIO_PIN_2
#define LED_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
