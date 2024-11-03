#include "isr.h"

#include "../TEMP_HUMID/TEMP_HUMID.h"
#include "../SOIL_MOIST/SOIL_MOIST.h"


extern struct TEMP_HUMID_obj OBJ_TEMP_HUMID;			// Object for temp/moist sensor
extern struct SOIL_MOIST_obj OBJ_SOIL_MOIST_sensor_1;	// Object for soil moisture sensor 1


void cyclic_routine(void){
	TEMP_HUMID_read(&OBJ_TEMP_HUMID);

#ifdef DEGBUG_PRINTF
	printf("Temperature: %d, Humidity: %d\n", OBJ_TEMP_HUMID.dht11.temperature, OBJ_TEMP_HUMID.dht11.humidty);
	printf("Soil Moisture: %d promille\n", SOIL_MOIST_get_moisture_percent(&OBJ_SOIL_MOIST_sensor_1));
#endif

	HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);


}
