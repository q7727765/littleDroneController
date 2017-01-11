#include "HAL.h"
#include "nrf24l01.h"

rc_t rc;

void rc_init()
{
	NRF24L01_Init();

	rc.adc_min[rc_thr_num] = 2024;	rc.adc_max[rc_thr_num] = 4095;
	rc.adc_min[rc_yaw_num] = 2127;	rc.adc_max[rc_yaw_num] = 4095;
	rc.adc_min[rc_pit_num] = 2085;	rc.adc_max[rc_pit_num] = 4095;
	rc.adc_min[rc_rol_num] = 2184;	rc.adc_max[rc_rol_num] = 4092;

	rc.trim[rc_thr_num] = 0;
	rc.trim[rc_yaw_num] = 6;
	rc.trim[rc_pit_num] = 10;
	rc.trim[rc_rol_num] = -2;

	rc.direct[rc_thr_num] = 1;
	rc.direct[rc_yaw_num] = 1;
	rc.direct[rc_pit_num] = 1;
	rc.direct[rc_rol_num] = 1;
	rc.direct[rc_aux1_num] = 1;
	rc.direct[rc_aux2_num] = 1;
	rc.direct[rc_push_num] = 1;
}
