#include "../HTU21/HTU21.h"

#define HTU21D_Adress 0x80
#define HTU21_RESET 0xFE
#define HTU21_MEAS_TEMP 0xE3
#define HTU21_MEAS_HUMID 0xE5

static uint16_t HTU21_measure_and_read(I2C_HandleTypeDef *hi2c, uint8_t command);
static float HTU21_result_conversion(uint16_t raw, float factor, float offset);


void HTU21_init(struct HTU21_obj *obj, I2C_HandleTypeDef *hi2c){
	obj->hi2c = hi2c;
	uint8_t txdata[] = {HTU21_RESET, 0};
	HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(obj->hi2c, HTU21D_Adress, txdata, 1, 100);
}

void HTU21_measure_temperature(struct HTU21_obj *obj){
	uint16_t raw = HTU21_measure_and_read(obj->hi2c, HTU21_MEAS_TEMP);
	obj->temperature_degC = HTU21_result_conversion(raw, 175.72f, -46.85f);
}

void HTU21_measure_humidity(struct HTU21_obj *obj){
	uint16_t raw = HTU21_measure_and_read(obj->hi2c, HTU21_MEAS_HUMID);
	obj->humidity_percent = HTU21_result_conversion(raw, 125.0f, 6.0f);
}

int16_t HTU21_get_temperature(struct HTU21_obj *obj){
	return ((int16_t)(obj->temperature_degC*10));
}

int16_t HTU21_get_humidity(struct HTU21_obj *obj){
	return ((int16_t)(obj->humidity_percent*10));
}


static uint16_t HTU21_measure_and_read(I2C_HandleTypeDef *hi2c, uint8_t command){
	uint8_t data[] = {command, 0};
	HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(hi2c, HTU21D_Adress, data, 1, 100); 	// send measure command
	status = HAL_I2C_Master_Receive(hi2c, HTU21D_Adress, data, 2, 100);						// receive data
	uint16_t result = data[1] + ((uint16_t)(data[0])<<8);										// combine both result bytes
	return result;
}

static float HTU21_result_conversion(uint16_t raw, float factor, float offset){
	float measurement = (float)(raw);
	return (raw/65536.0f*factor + offset);
}
