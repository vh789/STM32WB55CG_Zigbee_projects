#include "RGB.h"
#include <math.h>
#include "../SHARED_HEADER.h"

extern TIM_HandleTypeDef htim2;

void setPWM_normal_timer(TIM_HandleTypeDef timer, uint32_t channel, uint16_t pulse);
uint16_t saturate_color(uint16_t in);
struct RGB_colors xy_to_RGB(float x, float y, float brightness);
void update_color_xy(struct RGB_obj *obj);

void RGB_init(struct RGB_obj *obj, TIM_HandleTypeDef *timer, uint32_t channel_red, uint32_t channel_green, uint32_t channel_blue){
	struct RGB_colors zero_col = {0};
	obj->timer = timer;
	obj->channel_red = channel_red;
	obj->channel_green = channel_green;
	obj->channel_blue = channel_blue;
	obj->XY_col.x = 0;
	obj->XY_col.y = 0,
	obj->XY_col.brightness = 0xFF,
	obj->on_status = false;
	RGB_set(obj, zero_col);
}

void RGB_set_xy(struct RGB_obj *obj, uint16_t x, uint16_t y){
	obj->XY_col.x = x;
	obj->XY_col.y = y;
	update_color_xy(obj);
}

void RGB_set_brightness(struct RGB_obj *obj, uint16_t brightness){
	obj->XY_col.brightness = brightness;
	update_color_xy(obj);
}

void RGB_set(struct RGB_obj *obj, struct RGB_colors color){
	setPWM_normal_timer(*obj->timer, obj->channel_blue, color.b);
	setPWM_normal_timer(*obj->timer, obj->channel_green, color.g);
	setPWM_normal_timer(*obj->timer, obj->channel_red, color.r);
}

void RGB_turn_off(struct RGB_obj *obj){
	struct RGB_colors zero_col = {0};
	obj->on_status = false;
	RGB_set(obj, zero_col);
}

void RGB_turn_on(struct RGB_obj *obj){
	obj->on_status = true;
	update_color_xy(obj);
}

void setPWM_normal_timer(TIM_HandleTypeDef timer, uint32_t channel, uint16_t pulse) {
	HAL_TIM_PWM_Stop(&timer, channel); 								// stop generation of pwm
	TIM_OC_InitTypeDef sConfigOC;
	timer.Init.Period = MAX_BRIGHTNESS; 							// set the period duration
	HAL_TIM_PWM_Init(&timer); 										// re-inititialize with new period value
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = saturate_color(pulse); 										// set the pulse duration
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);
	HAL_TIM_PWM_Start(&timer, channel); // start pwm generation
	HAL_TIMEx_PWMN_Start(&timer, channel);
}

uint16_t saturate_color(uint16_t in){
	if(in > MAX_BRIGHTNESS){
		return MAX_BRIGHTNESS;
	}else{
		return in;
	}
}

//https://gist.github.com/popcorn245/30afa0f98eea1c2fd34d
struct RGB_colors xy_to_RGB(float x, float y, float brightness){
	float z = 1.0f - x - y;
	float Y = brightness; // The given brightness value
	float X = (Y / y) * x;
	float Z = (Y / y) * z;
	float r = X * 1.656492 - Y * 0.354851 - Z * 0.255038;
	float g = -X * 0.707196 + Y * 1.655397 + Z * 0.036152;
	float b = X * 0.051713 - Y * 0.121364 + Z * 1.011530;
	float max = 0.0f;
	r = r <= 0.0031308f ? 12.92f * r : (1.0f + 0.055f) * pow(r, (1.0f / 2.4f)) - 0.055f;
	g = g <= 0.0031308f ? 12.92f * g : (1.0f + 0.055f) * pow(g, (1.0f / 2.4f)) - 0.055f;
	b = b <= 0.0031308f ? 12.92f * b : (1.0f + 0.055f) * pow(b, (1.0f / 2.4f)) - 0.055f;

	if(r>g){
		max = r;
	}else{
		max = g;
	}
	if(b>max){
		max = b;
	}
	if(max>1.0f){
	r = r/max;
	g = g/max;
	b = b/max;
	}

	struct RGB_colors out = {
		.r = MAX_BRIGHTNESS*r,
		.g = MAX_BRIGHTNESS*g,
		.b = MAX_BRIGHTNESS*b
	};
	return out;
}

void update_color_xy(struct RGB_obj *obj){
	float x = 1.0f*obj->XY_col.x/0xFFFF;
	float y = 1.0f*obj->XY_col.x/0xFFFF;
	float brightness = 1.0f*obj->XY_col.brightness/0xFF;
	struct RGB_colors RGB = xy_to_RGB(x, y, brightness);
#ifdef DEGBUG_PRINTF
    printf("R: %d, G: %d, B: %d", RGB.r, RGB.g, RGB.b);
#endif
	RGB_set(obj, RGB);
}
