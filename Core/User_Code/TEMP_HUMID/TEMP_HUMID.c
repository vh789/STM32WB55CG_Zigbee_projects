#include "TEMP_HUMID.h"


void TEMP_HUMID_init(struct TEMP_HUMID_obj *obj, enum TEMP_HUMID_sensortype type, TIM_HandleTypeDef *timer, GPIO_TypeDef* port, uint16_t pin){
	obj->type = type;
	//make tim16 maybe to tim17
	switch(obj->type){
	case DHT11:
		//init_dht11(&obj->dht11, timer, port, pin);
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
		DHT_GetData(&data);
//		DHT22_GetTemp_Humidity(&obj->temperature_degC, &obj->humidity_percent);
		obj->temperature_degC = data.Temperature;
		obj->humidity_percent = data.Humidity;
		printf("temperature: %d\n", (int16_t)(obj->temperature_degC));

		break;
	default:
		obj->temperature_degC = 0;
		obj->humidity_percent = 0;
		break;
	}
}

long long TEMP_HUMID_get_temperature(struct TEMP_HUMID_obj *obj){
	float value_mul = obj->temperature_degC * 10.0f;
	return ((long long)(value_mul));
}

long long TEMP_HUMID_get_humidity(struct TEMP_HUMID_obj *obj){
	float value_mul = obj->humidity_percent * 10.0f;
	return ((long long)(value_mul));
}
