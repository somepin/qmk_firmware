#define COMBO_DICT_COLEMAK_DH

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL 11
#undef  RGBLED_NUM
#undef  RGBLIGHT_HUE_STEP
#undef  RGBLIGHT_SAT_STEP
#undef  RGBLIGHT_VAL_STEP
#undef  RGBLIGHT_LIMIT_VAL
#undef  RGBLIGHT_SLEEP
#undef  RGBLIGHT_ANIMATIONS
#endif

#ifdef RGBLIGHT_ENABLE
#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

#define NO_ACTION_ONESHOT

#ifdef HAPTIC_ENABLE
#define FB_ERM_LRA 0
#define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
#define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */

/* Please refer to your datasheet for the optimal setting for your specific motor. */
#define RATED_VOLTAGE 3
#define V_PEAK 5
#endif