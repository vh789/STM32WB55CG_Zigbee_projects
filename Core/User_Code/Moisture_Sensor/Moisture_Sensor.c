#include "Moisture_Sensor.h"

#define OC_MEAS 2500U
#define WATER_MEAS 3570U

uint32_t saturate(uint32_t val);


uint16_t ADC_to_moisture_percent(uint16_t ADC_read){
	uint32_t working_value = saturate(ADC_read);// saturate
	working_value = working_value - OC_MEAS;	// compensate lower offset
	working_value = 10000U*working_value/(WATER_MEAS - OC_MEAS);
	return (uint16_t)working_value;
}

uint32_t saturate(uint32_t val){
	if(val > WATER_MEAS){
		return WATER_MEAS;
	}else if(val < OC_MEAS){
		return val;
	}else{
		return val;
	}
}
