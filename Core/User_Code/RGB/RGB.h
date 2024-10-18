#pragma once

#include "stm32wbxx_hal.h"
#define MAX_BRIGHTNESS 100

struct RGB_t{
	uint16_t red;
	uint16_t green;
	uint16_t blue;
};

struct RGB_object_t{
	uint16_t color_x;
	uint16_t color_y;
	uint16_t brightness;
};

void update_RGB(struct RGB_object_t data);

void set_RGB(uint16_t red, uint16_t green, uint16_t blue);
void set_color_xy(float x, float y, float brightness);
