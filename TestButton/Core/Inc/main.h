/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define RED_ROW_Pin GPIO_PIN_1
#define RED_ROW_GPIO_Port GPIOA
#define GREEN_ROW_Pin GPIO_PIN_2
#define GREEN_ROW_GPIO_Port GPIOA
#define AMBER_ROW_Pin GPIO_PIN_3
#define AMBER_ROW_GPIO_Port GPIOA
#define RED_COL_Pin GPIO_PIN_4
#define RED_COL_GPIO_Port GPIOA
#define GREEN_COL_Pin GPIO_PIN_5
#define GREEN_COL_GPIO_Port GPIOA
#define AMBER_COL_Pin GPIO_PIN_6
#define AMBER_COL_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_7
#define EN0_GPIO_Port GPIOA
#define SEG_a_Pin GPIO_PIN_0
#define SEG_a_GPIO_Port GPIOB
#define SEG_b_Pin GPIO_PIN_1
#define SEG_b_GPIO_Port GPIOB
#define SEG_c_Pin GPIO_PIN_2
#define SEG_c_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_12
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_13
#define BUTTON2_GPIO_Port GPIOB
#define BUTTON3_Pin GPIO_PIN_14
#define BUTTON3_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_8
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_9
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_10
#define EN3_GPIO_Port GPIOA
#define SEG_d_Pin GPIO_PIN_3
#define SEG_d_GPIO_Port GPIOB
#define SEG_e_Pin GPIO_PIN_4
#define SEG_e_GPIO_Port GPIOB
#define SEG_f_Pin GPIO_PIN_5
#define SEG_f_GPIO_Port GPIOB
#define SEG_g_Pin GPIO_PIN_6
#define SEG_g_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
