#include "servo.h"
#include "main.h"
#include <stdint.h>

extern TIM_HandleTypeDef htim3;

void servo_move(uint8_t angle) {
    if (angle > 180) angle = 180;

    uint32_t pulse = 1000 + ((uint32_t)angle * 1000 / 180);

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pulse);
}

