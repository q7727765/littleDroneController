/*
 * schedule_tasks.c
 *
 *  Created on: 2016Äê12ÔÂ28ÈÕ
 *      Author: 50430
 */

#include "stm32f1xx_hal.h"
#include "delay.h"
#include "usart.h"
#include <stdint.h>
#include <stdbool.h>
#include "HAL.h"
#include "config_tasks.h"
#include "nrf24l01.h"
#include "stdio.h"
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
void taskUsartDebug(void)
{

//	uint16_t adc_dat;
//	adc_dat = (uint16_t)HAL_ADC_GetValue(&hadc2);
//
//	SendChar("\r\nadc:");
//	SendInt(adc_dat);
//	_n();


#if 1
	SendChar("usart running...\r\n");
#endif
}
void taskRcTransmit(void)
{

		  NRF24L01_TxPacket((u8*)rc.value);

}

void taskRUNLED(void)
{
	static char sta = 0;

	sta = !sta;//(sta+1)%2;

	if(sta)
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin , GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin , GPIO_PIN_RESET);

}
