#include "SOIL_MOIST.h"

#define OC_MEAS 2500U
#define WATER_MEAS 3570U

uint32_t saturate(uint32_t val);


void SOIL_MOIST_init(struct SOIL_MOIST_obj *obj, uint16_t *DMA_location){
	obj->type = SOIL_MOIST;
	obj->ADC_val = DMA_location;
}


uint16_t SOIL_MOIST_get_moisture_percent(struct SOIL_MOIST_obj *obj){
	uint32_t working_value = saturate(*obj->ADC_val);// saturate
	working_value = working_value - OC_MEAS;	// compensate lower offset
	working_value = 10000U*working_value/(WATER_MEAS - OC_MEAS);
	return (uint16_t)working_value;
}





// private FCT

uint32_t saturate(uint32_t val){
	if(val > WATER_MEAS){
		return WATER_MEAS;
	}else if(val < OC_MEAS){
		return val;
	}else{
		return val;
	}
}
