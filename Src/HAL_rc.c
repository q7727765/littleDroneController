#include "HAL.h"
#include "nrf24l01.h"

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

rc_t rc;
uint8_t rc_calib_pass = 1;

void rc_init()
{
	NRF24L01_Init();

	rc.adc_min[rc_thr_num] = 2024;	rc.adc_max[rc_thr_num] = 4095;
	rc.adc_min[rc_yaw_num] = 2127;	rc.adc_max[rc_yaw_num] = 4095;
	rc.adc_min[rc_pit_num] = 2085;	rc.adc_max[rc_pit_num] = 4095;
	rc.adc_min[rc_rol_num] = 2184;	rc.adc_max[rc_rol_num] = 4092;

	rc.trim[rc_thr_num] = 0;
	rc.trim[rc_yaw_num] = -3;
	rc.trim[rc_pit_num] = -30;
	rc.trim[rc_rol_num] = 2;

	rc.direct[rc_thr_num] = 1;
	rc.direct[rc_yaw_num] = 1;
	rc.direct[rc_pit_num] = 1;
	rc.direct[rc_rol_num] = 1;
	rc.direct[rc_aux1_num] = 1;
	rc.direct[rc_aux2_num] = -1;
	rc.direct[rc_push_num] = 1;

	rc.value[rc_check_pin1] = '@';
	rc.value[rc_check_pin2] = '#';

	rc.adc_trim[rc_thr_num] = 2046;
	rc.adc_trim[rc_yaw_num] = 2046 + 1024;
	rc.adc_trim[rc_pit_num] = 2046 + 1024;
	rc.adc_trim[rc_rol_num] = 2046 + 1024;

}

void rc_calib(void)
{
	//调用校准前，要将thr，yaw，pit，roll摇杆分别打到最低，居中，居中，居中
	rc.adc_trim[rc_thr_num] = HAL_ADCEx_InjectedGetValue(&hadc1,1);
	rc.adc_trim[rc_yaw_num] = HAL_ADCEx_InjectedGetValue(&hadc1,2);
	rc.adc_trim[rc_pit_num] = HAL_ADCEx_InjectedGetValue(&hadc1,3);
	rc.adc_trim[rc_rol_num] = HAL_ADCEx_InjectedGetValue(&hadc1,4);
}

