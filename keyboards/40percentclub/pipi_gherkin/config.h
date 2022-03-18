#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    40 Percent Club
#define PRODUCT         PiPi Gherkin

// #define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { GP8, GP9, GP10, GP11, GP12, GP16 }
#define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6, GP7, GP17 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader

#define I2C1_SCL_PIN GP15
#define I2C1_SDA_PIN GP14
#define I2C_DRIVER I2CD2

#ifdef HAPTIC_ENABLE 
#define FB_ERM_LRA 0
#define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define RATED_VOLTAGE 3
#define V_PEAK 5

#define DRV_GREETING lg_dblsharp_tick
#define DRV_MODE_DEFAULT strong_buzz
#endif
