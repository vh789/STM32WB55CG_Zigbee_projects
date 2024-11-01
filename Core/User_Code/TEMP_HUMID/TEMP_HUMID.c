#include "TEMP_HUMID.h"

void TEMP_HUMID_init(struct TEMP_HUMID_obj *obj, TIM_HandleTypeDef *timer, GPIO_TypeDef* port, uint16_t pin){
	//make tim16 maybe to tim17
	init_dht11(&obj->dht11, timer, port, pin);
}

void TEMP_HUMID_read(struct TEMP_HUMID_obj *obj){
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

float TEMP_HUMID_get_temperature(struct TEMP_HUMID_obj *obj);

float TEMP_HUMID_get_moisture(struct TEMP_HUMID_obj *obj);
