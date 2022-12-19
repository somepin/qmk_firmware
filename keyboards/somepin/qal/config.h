/* Copyright 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

/* USB Device descriptor parameter */
// #define VENDOR_ID       0x7370
// #define PRODUCT_ID      0x6969
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    somepin
// #define PRODUCT         qal

// /* key matrix size */
// #define MATRIX_ROWS 4
// #define MATRIX_COLS 10

// #define DIODE_DIRECTION COL2ROW

// // #define MATRIX_COL_PINS { A1, A2, A3, A4, A5, A6, A7, A8, A10, B7 }
// #define MATRIX_COL_PINS { B7, A10, A8, A7, A6, A5, A4, A3, A2, A1 }
// #define MATRIX_ROW_PINS { B6, B5, B4, B3 }

// #define STM32_BOOTLOADER_ADDRESS 0x1FFF0000

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE    5

// #define TAPPING_TERM 200

// #define USB_SUSPEND_WAKEUP_DELAY 200

// #define RGB_DI_PIN B9

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 24
#define RGB_DISABLE_WHEN_USB_SUSPENDED 
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_BAND_SAT
#    define ENABLE_RGB_MATRIX_BAND_VAL
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define ENABLE_RGB_MATRIX_CYCLE_ALL
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
#    define ENABLE_RGB_MATRIX_HUE_WAVE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#endif
