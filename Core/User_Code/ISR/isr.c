#include "isr.h"

#include "../HTU21/HTU21.h"
#include "../SOIL_MOIST/SOIL_MOIST.h"
#include "app_zigbee.h"

extern struct HTU21_obj OBJ_HTU21;						// Object for temp/moist sensor
extern struct SOIL_MOIST_obj OBJ_SOIL_MOIST_sensor_1;	// Object for soil moisture sensor 1
extern struct SOIL_MOIST_obj OBJ_SOIL_MOIST_sensor_2;	// Object for soil moisture sensor 2

struct APP_ZIGBEE_cyclic_data data = {0};


void cyclic_routine(void){
	HTU21_measure_temperature(&OBJ_HTU21);
	HTU21_measure_humidity(&OBJ_HTU21);
	data.temperature = HTU21_get_temperature(&OBJ_HTU21);
	data.humidity = HTU21_get_humidity(&OBJ_HTU21);
	data.soil_moisture_1 = SOIL_MOIST_get_moisture_percent(&OBJ_SOIL_MOIST_sensor_1);
	data.soil_moisture_2 = SOIL_MOIST_get_moisture_percent(&OBJ_SOIL_MOIST_sensor_2);
#ifdef DEGBUG_PRINTF
	printf("Temperature: %d, Humidity: %d\n", data.temperature, data.humidity);
	printf("Soil Moisture1: %d promille\n", data.soil_moisture_1);
#endif
	APP_ZIGBEE_cyclic_reporting(&data);
	HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);
}
