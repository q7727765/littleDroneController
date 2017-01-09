/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define BEEP_Pin GPIO_PIN_15
#define BEEP_GPIO_Port GPIOC
#define ADC_THR_Pin GPIO_PIN_0
#define ADC_THR_GPIO_Port GPIOA
#define ADC_YAW_Pin GPIO_PIN_1
#define ADC_YAW_GPIO_Port GPIOA
#define ADC_PITCH_Pin GPIO_PIN_2
#define ADC_PITCH_GPIO_Port GPIOA
#define ADC_ROLL_Pin GPIO_PIN_3
#define ADC_ROLL_GPIO_Port GPIOA
#define ADC_POWER_Pin GPIO_PIN_4
#define ADC_POWER_GPIO_Port GPIOA
#define W_CE_Pin GPIO_PIN_0
#define W_CE_GPIO_Port GPIOB
#define W_IRQ_Pin GPIO_PIN_1
#define W_IRQ_GPIO_Port GPIOB
#define W_CSN_Pin GPIO_PIN_12
#define W_CSN_GPIO_Port GPIOB
#define W_SCK_Pin GPIO_PIN_13
#define W_SCK_GPIO_Port GPIOB
#define W_MISO_Pin GPIO_PIN_14
#define W_MISO_GPIO_Port GPIOB
#define W_MOSI_Pin GPIO_PIN_15
#define W_MOSI_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_11
#define SDA_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_12
#define SCL_GPIO_Port GPIOA
#define auxkey_r_Pin GPIO_PIN_3
#define auxkey_r_GPIO_Port GPIOB
#define ballkey_pin1_Pin GPIO_PIN_4
#define ballkey_pin1_GPIO_Port GPIOB
#define ballkey_pin2_Pin GPIO_PIN_5
#define ballkey_pin2_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_7
#define LED_GPIO_Port GPIOB
#define pushkey_Pin GPIO_PIN_8
#define pushkey_GPIO_Port GPIOB
#define auxkey_l_Pin GPIO_PIN_9
#define auxkey_l_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
