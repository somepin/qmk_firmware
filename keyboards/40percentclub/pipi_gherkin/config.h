#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    40 Percent Club
#define PRODUCT         PiPi Gherkin

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { GP12, GP11, GP10, GP9, GP8 }
#define MATRIX_COL_PINS { GP7, GP6, GP5, GP4, GP3, GP2 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5
#define ONESHOT_MOD_ENABLE
