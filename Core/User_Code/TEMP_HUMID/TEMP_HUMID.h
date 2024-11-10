#pragma once
#include "../DHT11/mk_dht11.h"
#include "../DHT22/DHT22.h"
#include "../DHT/DHT.h"


enum TEMP_HUMID_sensortype {DHT11, DHT22};

struct TEMP_HUMID_obj{
	enum TEMP_HUMID_sensortype type;
	float temperature_degC;
	float humidity_percent;
	struct _dht11_t dht11;
};

void TEMP_HUMID_init(struct TEMP_HUMID_obj *obj, enum TEMP_HUMID_sensortype type, TIM_HandleTypeDef *timer, GPIO_TypeDef* port, uint16_t pin);

void TEMP_HUMID_read(struct TEMP_HUMID_obj *obj);

long long TEMP_HUMID_get_temperature(struct TEMP_HUMID_obj *obj);

long long TEMP_HUMID_get_humidity(struct TEMP_HUMID_obj *obj);
