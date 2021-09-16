#pragma once

#define IGNORE_MOD_TAP_INTERRUPT

#ifdef COMBO_ENABLE
#define COMBO_VARIABLE_LEN
#define COMBO_TERM 50
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 20000
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif