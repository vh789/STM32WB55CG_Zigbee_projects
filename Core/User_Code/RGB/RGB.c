#include "RGB.h"
#include <math.h>
#include "../SHARED_HEADER.h"

extern TIM_HandleTypeDef htim2;

void setPWM_normal_timer(TIM_HandleTypeDef timer, uint32_t channel, uint16_t pulse);
uint16_t saturate_color(uint16_t in);
struct RGB_colors xy_to_RGB(uint16_t x, uint16_t y, uint8_t brightness);
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

struct RGB_colors xy_to_RGB(uint16_t x, uint16_t y, uint8_t brightness) {
    // Convert input to normalized float (0.0 – 1.0)
    float fx = (float)x / 65535.0f;
    float fy = (float)y / 65535.0f;
    float fbrightness = (float)brightness / 255.0f;

    // Avoid division by zero
    if (fy <= 0.00001f) {
        struct RGB_colors zero = {0, 0, 0};
        return zero;
    }

    // Compute XYZ
    float fz = 1.0f - fx - fy;
    float Y = fbrightness;
    float X = (Y / fy) * fx;
    float Z = (Y / fy) * fz;

    // Convert XYZ to linear RGB using sRGB D65 matrix
    float r =  3.2406f * X - 1.5372f * Y - 0.4986f * Z;
    float g = -0.9689f * X + 1.8758f * Y + 0.0415f * Z;
    float b =  0.0557f * X - 0.2040f * Y + 1.0570f * Z;

    // Clamp negative values
    if (r < 0.0f) r = 0.0f;
    if (g < 0.0f) g = 0.0f;
    if (b < 0.0f) b = 0.0f;

    // Apply gamma correction (sRGB)
    r = (r <= 0.0031308f) ? 12.92f * r : 1.055f * powf(r, 1.0f / 2.4f) - 0.055f;
    g = (g <= 0.0031308f) ? 12.92f * g : 1.055f * powf(g, 1.0f / 2.4f) - 0.055f;
    b = (b <= 0.0031308f) ? 12.92f * b : 1.055f * powf(b, 1.0f / 2.4f) - 0.055f;

    // Normalize if any component is > 1.0
    float max_val = fmaxf(fmaxf(r, g), b);
    if (max_val > 1.0f) {
        r /= max_val;
        g /= max_val;
        b /= max_val;
    }

    // Scale to 0–255 and round
    struct RGB_colors out = {
        .r = (uint8_t)(fminf(r * MAX_BRIGHTNESS, MAX_BRIGHTNESS)),
        .g = (uint8_t)(fminf(g * MAX_BRIGHTNESS, MAX_BRIGHTNESS)),
        .b = (uint8_t)(fminf(b * MAX_BRIGHTNESS, MAX_BRIGHTNESS))
    };

    return out;
}

void update_color_xy(struct RGB_obj *obj){
	struct RGB_colors RGB = xy_to_RGB(obj->XY_col.x, obj->XY_col.y, obj->XY_col.brightness);
#ifdef DEGBUG_PRINTF
    printf("x: %d, y: %d, Br: %d", obj->XY_col.x, obj->XY_col.y, obj->XY_col.brightness);
    printf("R: %d, G: %d, B: %d", RGB.r, RGB.g, RGB.b);
#endif
	RGB_set(obj, RGB);
}
