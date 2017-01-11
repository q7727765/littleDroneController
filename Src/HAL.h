/*
 * HAL.c
 *
 *  Created on: 2017年1月3日
 *      Author: 50430
 */

#pragma once

#include "stdint.h"
//#include "sensor.h"

//typedef struct gyro_s {
//    sensorGyroInitFuncPtr init;                             // initialize function
//    sensorReadFuncPtr read;                                 // read 3 axis data function
//    sensorReadFuncPtr temperature;                          // read temperature if available
//    sensorIsDataReadyFuncPtr isDataReady;                   // check if sensor has new readings
//    float scale;                                            // scalefactor
//} gyro_t;
//
//typedef struct acc_s {
//	sensorAccInitFuncPtr init;                             // initialize function
//    sensorReadFuncPtr read;                                 // read 3 axis data function
//    uint16_t acc_1G;
//    char revisionCode;                                      // a revision code for the sensor, if known
//} acc_t;
//
//typedef struct mag_s {
//    sensorInitFuncPtr init;                                 // initialize function
//    sensorReadFuncPtr read;                                 // read 3 axis data function
//} mag_t;
//
//typedef struct baro_s {
//    uint16_t ut_delay;
//    uint16_t up_delay;
//    baroOpFuncPtr start_ut;
//    baroOpFuncPtr get_ut;
//    baroOpFuncPtr start_up;
//    baroOpFuncPtr get_up;
//    baroCalculateFuncPtr calculate;
//} baro_t;
//
//typedef struct motor_s {
//	volatile uint32_t *value[4];
//}motor_t;

//typedef struct attitude_s {
//	float pitch;
//	float roll;
//	float yaw;
//}attitude_t;


enum rc_e{
	rc_roll_num		= 0,
	rc_pitch_num 	,
	rc_throttle_num	,
	rc_yaw_num		,
	rc_aux1_num		,
	rc_aux2_num		,
	rc_aux3_num		,
	rc_aux4_num
};

typedef struct rc_s {
	uint16_t value[8];
	uint8_t	 direct[8];

}rc_t;


/*
 * \brief 电池管理结构体
 *
 * \para  raw_data : 12位ad读出来的原始数据
 *        voltage  : 转换后的真正电压值
 *        vol_alarm: 报警电压
 *        scale    : raw_data转换为voltage时的比例系数
 * \addition 公式: 	voltage = ((float)raw_data/4096)*3.33*scale;
 * */
typedef struct battery_s{
	uint16_t raw_data;
	float voltage;
	float vol_alarm;
	float scale;
}battery_t;

//extern acc_t acc;
//extern gyro_t gyro;
//extern mag_t mag;
//extern baro_t baro;
//extern motor_t motor;
extern rc_t rc;
extern battery_t battery;

//void motor_init();
//void motor_out(u16 m1,u16 m2,u16 m3,u16 m4);
//extern void detectAcc();
//extern void detectGyro();
//extern void detectMag();
//extern void detectBaro();
//extern uint32_t recalculateBarometerTotal(uint8_t baroSampleCount, uint32_t pressureTotal, int32_t newPressureReading);
