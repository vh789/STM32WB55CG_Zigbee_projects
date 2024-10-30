#include "TEMP_MOIST.h"

void TEMP_MOIST_init(struct temp_moist_obj *obj, GPIO_TypeDef* port, uint16_t pin){
	//make tim16 maybe to tim17
	init_dht11(&obj->dht11, &htim16, port, pin);
}

void TEMP_MOIST_read(struct temp_moist_obj *obj){
	switch (obj->type){
	case DHT11:
		readDHT11(&obj->dht11);
		obj->temperature_degC = (float)obj->dht11.temperature;
		obj->humidty_percent = (float)obj->dht11.humidty;
		break;
	case DHT22:

		break;
	default:
		obj->temperature_degC = 0;
		obj->humidty_percent = 0;
		break;
	}
}

float TEMP_MOIST_get_temperature(struct temp_moist_obj *obj);

float TEMP_MOIST_get_moisture(struct temp_moist_obj *obj);
