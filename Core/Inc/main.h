/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32wbxx_hal.h"
#include "app_conf.h"
#include "app_entry.h"
#include "app_common.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define led_g_Pin GPIO_PIN_0
#define led_g_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_1
#define BTN2_GPIO_Port GPIOA
#define led_r_Pin GPIO_PIN_2
#define led_r_GPIO_Port GPIOA
#define led_b_Pin GPIO_PIN_3
#define led_b_GPIO_Port GPIOA
#define sens1_Pin GPIO_PIN_4
#define sens1_GPIO_Port GPIOA
#define sens2_Pin GPIO_PIN_5
#define sens2_GPIO_Port GPIOA
#define sens3_Pin GPIO_PIN_6
#define sens3_GPIO_Port GPIOA
#define TEMP_HUMID_Pin GPIO_PIN_7
#define TEMP_HUMID_GPIO_Port GPIOA
#define BOARD_LED_Pin GPIO_PIN_4
#define BOARD_LED_GPIO_Port GPIOE
#define BTN1_Pin GPIO_PIN_7
#define BTN1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
