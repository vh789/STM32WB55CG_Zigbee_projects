#include "TEMP_HUMID.h"


void TEMP_HUMID_init(struct TEMP_HUMID_obj *obj, enum TEMP_HUMID_sensortype type, TIM_HandleTypeDef *timer, GPIO_TypeDef* port, uint16_t pin){
	obj->type = type;
	//make tim16 maybe to tim17
	switch(obj->type){
	case DHT11:
		init_dht11(&obj->dht11, timer, port, pin);
		break;
	case DHT22:
		DHT22_Init(port, pin);
		break;
	default:
		break;
	}
}

void TEMP_HUMID_read(struct TEMP_HUMID_obj *obj){
	switch (obj->type){
	case DHT11:
		readDHT11(&obj->dht11);
		obj->temperature_degC = (float)obj->dht11.temperature;
		obj->humidity_percent = (float)obj->dht11.humidty;
		break;
	case DHT22:
		DHT_DataTypedef data;
		bool fb = DHT_GetData(&data);
		if(fb){
			obj->temperature_degC = data.Temperature;
			obj->humidity_percent = data.Humidity;
		}
		break;
	default:
		obj->temperature_degC = 0.0f;
		obj->humidity_percent = 0.0f;
		break;
	}
}

int16_t TEMP_HUMID_get_temperature(struct TEMP_HUMID_obj *obj){
	float value_mul = obj->temperature_degC;
	if(obj->type == DHT11){
		value_mul = value_mul * 10.0f;
	}
	return ((int16_t)(value_mul));
}

int16_t TEMP_HUMID_get_humidity(struct TEMP_HUMID_obj *obj){
	float value_mul = obj->humidity_percent;
	if(obj->type == DHT11){
			value_mul = value_mul * 10.0f;
		}
	return ((int16_t)(value_mul));
}
