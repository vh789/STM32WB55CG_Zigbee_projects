#pragma once

#include "stm32wbxx_hal.h"
#include <stdint.h>
#include <stdbool.h>

#define MAX_BRIGHTNESS 100

struct XY_colors{
	uint16_t x;
	uint16_t y;
	uint16_t brightness;
};

struct RGB_colors{
	uint16_t r;
	uint16_t g;
	uint16_t b;
};

struct RGB_obj{
	TIM_HandleTypeDef *timer;
	uint32_t channel_red;
	uint32_t channel_green;
	uint32_t channel_blue;
	struct XY_colors XY_col;
	bool on_status;
};

void RGB_init(struct RGB_obj *obj, TIM_HandleTypeDef *timer, uint32_t channel_red, uint32_t channel_green, uint32_t channel_blue);
void RGB_set(struct RGB_obj *obj, struct RGB_colors color);
void RGB_set_xy(struct RGB_obj *obj, uint16_t x, uint16_t y);
void RGB_set_brightness(struct RGB_obj *obj, uint16_t brightness);
void RGB_turn_off(struct RGB_obj *obj);
void RGB_turn_on(struct RGB_obj *obj);
