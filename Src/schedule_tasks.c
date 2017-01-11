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

battery_t battery;
extern DMA_HandleTypeDef hdma_adc1;

uint16_t rc_adc[4];
void taskUsartDebug(void)
{

	//HAL_ADCEx_InjectedStart(&hadc1);

	rc_adc[0] = HAL_ADCEx_InjectedGetValue(&hadc1,1);
	rc_adc[1] = HAL_ADCEx_InjectedGetValue(&hadc1,2);
	rc_adc[2] = HAL_ADCEx_InjectedGetValue(&hadc1,3);
	rc_adc[3] = HAL_ADCEx_InjectedGetValue(&hadc1,4);

	SendChar("rc_adc1:");
	SendInt(rc_adc[0]);
	_n();
	SendChar("rc_adc2:");
	SendInt(rc_adc[1]);
	_n();
	SendChar("rc_adc3:");
	SendInt(rc_adc[2]);
	_n();
	SendChar("rc_adc4:");
	SendInt(rc_adc[3]);
	_n();

#if 0
	SendChar("usart running...\r\n");
#endif
}
void taskRcTransmit(void)
{

		  NRF24L01_TxPacket((u8*)rc.value);

}

void taskBatteryMoniter(void)
{

//	battery.scale = 2.053;
//	battery.raw_data = (uint16_t)HAL_ADC_GetValue(&hadc2);
//	battery.voltage = ((float)battery.raw_data/4096)*battery.scale*3.33;
//	SendChar("\r\nadc:");
//
//	SendDouble(battery.voltage);
//	_n();

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
