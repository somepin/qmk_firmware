#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x7370
#define PRODUCT_ID 0x7177
#define DEVICE_VER 0x0001
#define MANUFACTURER somepin
#define PRODUCT ChipQAZ

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

#define MATRIX_ROW_PINS { F7, D3, D4, D7 }
#define MATRIX_COL_PINS { F6, F5, F4, F1, F0, D2, E6, B5, B6, B7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define TAPPING_TERM 200