#pragma once

#include <stdint.h>

enum SOIL_MOIST_sensortype {SOIL_MOIST};

struct SOIL_MOIST_obj{
	enum SOIL_MOIST_sensortype type;
	uint16_t *ADC_val;
};

void SOIL_MOIST_init(struct SOIL_MOIST_obj *obj, uint16_t *DMA_location);
uint16_t SOIL_MOIST_get_moisture_percent(struct SOIL_MOIST_obj *obj);
