#include "SOIL_MOIST.h"

#define MAX_ADC 0xFFF
#define WATER_MEAS 2500
#define VAL_RANGE (MAX_ADC-WATER_MEAS)

uint16_t saturate(uint16_t val);


void SOIL_MOIST_init(struct SOIL_MOIST_obj *obj, uint16_t *DMA_location){
	obj->type = SOIL_MOIST;
	obj->ADC_val = DMA_location;
}


int16_t SOIL_MOIST_get_moisture_percent(struct SOIL_MOIST_obj *obj){
	int32_t working_val = saturate(*obj->ADC_val) -  WATER_MEAS;	// saturated and offset compensated
	working_val = 1000 * working_val / VAL_RANGE;					// multiplication order is important to avoid overflow
	working_val = 1000 - working_val;								// invert, since high adc is low moisture
	int16_t shortened = (int16_t)(working_val);						// cast back to 16 bit
	return shortened;
}



// private FCT

uint16_t saturate(uint16_t val){
	if(val > MAX_ADC){
		return MAX_ADC;
	}else if(val < WATER_MEAS){
		return WATER_MEAS;
	}else{
		return val;
	}
}
