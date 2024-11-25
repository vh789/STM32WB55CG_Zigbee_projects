#include "isr.h"

#include "../TEMP_HUMID/TEMP_HUMID.h"
#include "../SOIL_MOIST/SOIL_MOIST.h"
#include "app_zigbee.h"

extern struct TEMP_HUMID_obj OBJ_TEMP_HUMID;			// Object for temp/moist sensor
extern struct SOIL_MOIST_obj OBJ_SOIL_MOIST_sensor_1;	// Object for soil moisture sensor 1
extern struct SOIL_MOIST_obj OBJ_SOIL_MOIST_sensor_2;	// Object for soil moisture sensor 2

struct APP_ZIGBEE_cyclic_data data = {0};

float i=0;

void cyclic_routine(void){
//	TEMP_HUMID_read(&OBJ_TEMP_HUMID);
//	data.temperature = TEMP_HUMID_get_temperature(&OBJ_TEMP_HUMID)*10;
//	data.humidity = TEMP_HUMID_get_humidity(&OBJ_TEMP_HUMID)*10;
	data.soil_moisture_1 = SOIL_MOIST_get_moisture_percent(&OBJ_SOIL_MOIST_sensor_1);
	data.soil_moisture_2 = SOIL_MOIST_get_moisture_percent(&OBJ_SOIL_MOIST_sensor_2);
#ifdef DEGBUG_PRINTF
	printf("Temperature: %d, Humidity: %d\n", data.temperature, data.humidity);
	printf("Soil Moisture1: %d promille\n", data.soil_moisture_1);
#endif
	APP_ZIGBEE_cyclic_reporting(&data);
	HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);
}
