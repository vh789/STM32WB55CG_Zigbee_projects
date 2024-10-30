#pragma once
#include "../DHT11/mk_dht11.h"

enum sensortype {DHT11, DHT22};

struct temp_moist_obj{
	enum sensortype type;
	float temperature_degC;
	float humidty_percent;
	struct _dht11_t dht11;
};

void TEMP_MOIST_init(struct temp_moist_obj *obj, GPIO_TypeDef* port, uint16_t pin);

void TEMP_MOIST_read(struct temp_moist_obj *obj);

float TEMP_MOIST_get_temperature(struct temp_moist_obj *obj);

float TEMP_MOIST_get_moisture(struct temp_moist_obj *obj);
