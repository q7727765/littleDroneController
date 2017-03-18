/*
 * filter.c
 *
 *  Created on: 2017Äê3ÔÂ17ÈÕ
 *      Author: 50430
 */
#include <rc_filter.h>
#include "stm32f1xx_hal.h"

#define QUE_LENTH 10

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

uint16_t q_thr_adc[QUE_LENTH];
uint16_t q_yaw_adc[QUE_LENTH];
uint16_t q_pit_adc[QUE_LENTH];
uint16_t q_rol_adc[QUE_LENTH];

uint16_t rc_get_thr_smooth_adc(void)
{
	static uint8_t index = 0;
	uint32_t sum = 0;
	uint16_t temp = 0;

	temp = HAL_ADCEx_InjectedGetValue(&hadc1,1);

	q_thr_adc[index] = temp;

	index = (index + 1) % QUE_LENTH;

	for(int i = 0;i < QUE_LENTH;i++){

		sum += q_thr_adc[i];
	}

	sum = sum / QUE_LENTH;

	return (uint16_t)sum;
}

uint16_t rc_get_yaw_smooth_adc(void)
{
	static uint8_t index = 0;
	uint32_t sum = 0;
	uint16_t temp = 0;

	temp = HAL_ADCEx_InjectedGetValue(&hadc1,2);

	q_yaw_adc[index] = temp;

	index = (index + 1) % QUE_LENTH;

	for(int i = 0;i < QUE_LENTH;i++){

		sum += q_yaw_adc[i];
	}

	sum = sum / QUE_LENTH;

	return (uint16_t)sum;
}

uint16_t rc_get_pit_smooth_adc(void)
{
	static uint8_t index = 0;
	uint32_t sum = 0;
	uint16_t temp = 0;

	temp = HAL_ADCEx_InjectedGetValue(&hadc1,3);

	q_pit_adc[index] = temp;

	index = (index + 1) % QUE_LENTH;

	for(int i = 0;i < QUE_LENTH;i++){

		sum += q_pit_adc[i];
	}

	sum = sum / QUE_LENTH;

	return (uint16_t)sum;
}

uint16_t rc_get_rol_smooth_adc(void)
{
	static uint8_t index = 0;
	uint32_t sum = 0;
	uint16_t temp = 0;

	temp = HAL_ADCEx_InjectedGetValue(&hadc1,4);

	q_rol_adc[index] = temp;

	index = (index + 1) % QUE_LENTH;

	for(int i = 0;i < QUE_LENTH;i++){

		sum += q_rol_adc[i];
	}

	sum = sum / QUE_LENTH;

	return (uint16_t)sum;
}
