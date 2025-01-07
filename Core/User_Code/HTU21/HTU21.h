#pragma once
#include "main.h"

struct HTU21_obj{
	I2C_HandleTypeDef *hi2c;
	float temperature_degC;
	float humidity_percent;
};

void HTU21_init(struct HTU21_obj *obj, I2C_HandleTypeDef *hi2c);
void HTU21_measure_temperature(struct HTU21_obj *obj);
void HTU21_measure_humidity(struct HTU21_obj *obj);
int16_t HTU21_get_temperature(struct HTU21_obj *obj);
int16_t HTU21_get_humidity(struct HTU21_obj *obj);
