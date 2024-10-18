#include "RGB.h"
#include <math.h>

extern TIM_HandleTypeDef htim2;

void setPWM_normal_timer(TIM_HandleTypeDef timer, uint32_t channel, uint16_t pulse);
uint16_t saturate_color(uint16_t in);
struct RGB_t xy_to_RGB(float x, float y, float brightness);


void update_RGB(struct RGB_object_t data){
	float x = 1.0f*data.color_x/0xFFFF;
	float y = 1.0f*data.color_y/0xFFFF;
	float brightness = 1.0f*data.brightness/0xFF;
	set_color_xy(x, y, brightness);
}




void set_RGB(uint16_t red, uint16_t green, uint16_t blue){
	setPWM_normal_timer(htim2, TIM_CHANNEL_4, blue);					// normal timer
	setPWM_normal_timer(htim2, TIM_CHANNEL_3, green);		// negative timer
	setPWM_normal_timer(htim2, TIM_CHANNEL_1, red);					// normal timer
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
struct RGB_t xy_to_RGB(float x, float y, float brightness){
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

	struct RGB_t out = {
		.red = MAX_BRIGHTNESS*r,
		.green = MAX_BRIGHTNESS*g,
		.blue = MAX_BRIGHTNESS*b
	};
	return out;
}

void set_color_xy(float x, float y, float brightness){
	struct RGB_t RGB = xy_to_RGB(x, y, brightness);
    printf("R: %d, G: %d, B: %d", RGB.red, RGB.green, RGB.blue);

	set_RGB(RGB.red, RGB.green, RGB.blue);
}
