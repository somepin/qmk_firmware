#pragma once

#include "config_common.h"

#define VENDOR_ID 0xA8F8
#define PRODUCT_ID 0x1830
#define DEVICE_VER 0x0000
#define MANUFACTURER Bastard Keyboards
#define PRODUCT Skeletyl

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// dactyl manuform pins
#define DIODE_DIRECTION COL2ROW
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { F7, B1, B3, B2 }

// use an actual pin connecting D1 to GND on right hand side to indicate that it is right, no pin on the left controller makes it the master
#define SPLIT_HAND_PIN D1

#define USE_SERIAL
#define SOFT_SERIAL_PIN D0

#define DEBOUNCE 5

#define TAPPING_TERM 220

#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4
#define BOOTMAGIC_LITE_ROW_LEFT 4
#define BOOTMAGIC_LITE_COLUMN_LEFT 4

#define RGB_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 32
#define RGB_MATRIX_SPLIT { 16, 16 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 128
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 32
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 16, 16 }
#define RGBLIGHT_LIMIT_VAL 128
#define RGBLIGHT_SLEEP
/* Enable RGB animations */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_TWINKLE
#endif
