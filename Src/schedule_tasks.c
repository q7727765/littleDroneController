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

void taskUsartDebug(void)
{

	SendChar("rc_aux1_num:");
	SendInt(rc.value[rc_aux1_num]);
	_n();

	SendChar("rc_aux2_num:");
	SendInt(rc.value[rc_aux2_num]);
	_n();

	SendChar("rc_push_num:");
	SendInt(rc.value[rc_push_num]);
	_n();

//	SendChar("rc_adc1:");
//	SendInt(rc.adc_raw[rc_thr_num]);
//	_n();
//	SendChar("rc_adc2:");
//	SendInt(rc.adc_raw[rc_yaw_num]);
//	_n();
//	SendChar("rc_adc3:");
//	SendInt(rc.adc_raw[rc_pit_num]);
//	_n();
//	SendChar("rc_adc4:");
//	SendInt(rc.adc_raw[rc_rol_num]);
//	_n();
//
//	SendChar("rc_v1:");
//	SendInt(rc.value[rc_thr_num]);
//	_n();
//	SendChar("rc_v2:");
//	SendInt(rc.value[rc_yaw_num]);
//	_n();
//	SendChar("rc_v3:");
//	SendInt(rc.value[rc_pit_num]);
//	_n();
//	SendChar("rc_v4:");
//	SendInt(rc.value[rc_rol_num]);
//	_n();

#if 0
	SendChar("usart running...\r\n");
#endif
}
void taskRcTransmit(void)
{
	HAL_ADCEx_InjectedStart(&hadc1);

	rc.adc_raw[rc_thr_num] = HAL_ADCEx_InjectedGetValue(&hadc1,1);
	rc.adc_raw[rc_yaw_num] = HAL_ADCEx_InjectedGetValue(&hadc1,2);
	rc.adc_raw[rc_pit_num] = HAL_ADCEx_InjectedGetValue(&hadc1,3);
	rc.adc_raw[rc_rol_num] = HAL_ADCEx_InjectedGetValue(&hadc1,4);



	rc.value[rc_thr_num] =  -(rc.direct[rc_thr_num] - 1)/2  * 1000
						+ rc.direct[rc_thr_num] * (float)(rc.adc_raw[rc_thr_num] - rc.adc_min[rc_thr_num]) / (rc.adc_max[rc_thr_num]-rc.adc_min[rc_thr_num]) * 1000
						+ 1000 + rc.trim[rc_thr_num];

	rc.value[rc_yaw_num] = -(rc.direct[rc_yaw_num] - 1)/2 * 1000
						+ rc.direct[rc_yaw_num] * (float)(rc.adc_raw[rc_yaw_num] - rc.adc_min[rc_yaw_num]) / (rc.adc_max[rc_yaw_num]-rc.adc_min[rc_yaw_num]) * 1000
						+ 1000 + rc.trim[rc_yaw_num];

	rc.value[rc_pit_num] = -(rc.direct[rc_pit_num] - 1)/2 * 1000
						+ rc.direct[rc_pit_num] * (float)(rc.adc_raw[rc_pit_num] - rc.adc_min[rc_pit_num]) / (rc.adc_max[rc_pit_num]-rc.adc_min[rc_pit_num]) * 1000
						+ 1000 + rc.trim[rc_pit_num];

	rc.value[rc_rol_num] = -(rc.direct[rc_rol_num] - 1)/2 * 1000
						+ rc.direct[rc_rol_num] * (float)(rc.adc_raw[rc_rol_num] - rc.adc_min[rc_rol_num]) / (rc.adc_max[rc_rol_num]-rc.adc_min[rc_rol_num]) * 1000
						+ 1000 + rc.trim[rc_rol_num];

	rc.value[rc_aux1_num] = -(rc.direct[rc_aux1_num] - 1)/2 + rc.direct[rc_aux1_num] * HAL_GPIO_ReadPin(auxkey_l_GPIO_Port,auxkey_l_Pin);
	rc.value[rc_aux2_num] = -(rc.direct[rc_aux2_num] - 1)/2 + rc.direct[rc_aux2_num] * HAL_GPIO_ReadPin(auxkey_r_GPIO_Port,auxkey_r_Pin);
	rc.value[rc_push_num] = -(rc.direct[rc_push_num] - 1)/2 + rc.direct[rc_push_num] * HAL_GPIO_ReadPin(pushkey_GPIO_Port,pushkey_Pin);

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
