#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x7370
#define PRODUCT_ID 0x6371
#define DEVICE_VER 0x0001
#define MANUFACTURER somepin
#define PRODUCT ChipQAZ

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

#define MATRIX_ROW_PINS { F7, D3, D4, D7 }
#define MATRIX_COL_PINS { F6, F5, F4, F1, F0, D2, E6, B5, B6, B7 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_TERM 200

#define COMBO_ONLY_FROM_LAYER 0