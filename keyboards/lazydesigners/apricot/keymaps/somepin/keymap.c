#include "somepin.h"

// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {250, 200, 150};

/*
 * The `LAYOUT_apricot_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_wkl_smolbar(__VA_ARGS__)
#define LAYOUT_apricot_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K2A       \
  ) \
  LAYOUT_wrapper( \
      K01,    K02,    K03,    K04,    K05,    K06,    K07,    K08,    K09,    K0A,  \
      K11,    K12,    K13,    K14,    K15,    K16,    K17,    K18,    K19,    K1A,  \
      K21,    K22,    K23,    K24,    K25,    K26,    K27,    K28,    KC_NO,  K2A,  \
      KC_LCTL, KC_NO, LGUI_T(KC_ESC), KC_NO, LT(_LOWER, KC_SPC), RALT_T(KC_ENT), KC_NO, RCTL_T(KC_SLSH)  \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_apricot_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        HM_AC,  HM_RC, HM_SC, HM_TC,  LT(_RAISE, KC_G), ______________COLEMAK_DH_HRM_R2____________,
        ___________C_ANGLE_MOD_L3_________,    KC_Z, KC_K,  KC_H,  KC_COMM, KC_DOT
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        HM_AQ,  HM_SQ, HM_DQ, HM_FQ,  LT(_RAISE, KC_G), _______________QWERTY_HRM_R2_______________,
        KC_Z,    ___________Q_ANGLE_MOD_L3_________, KC_N,  KC_M,  KC_COMM, KC_DOT
    ),

    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,    KC_UP,   KC_I,    KC_ESC,
        KC_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
        KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,    KC_M,    KC_NO,   KC_RSFT,
        KC_LCTL,  KC_NO,    KC_LALT, KC_NO, KC_SPC,  TG(_GAMING), KC_NO,   KC_RCTL
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_RS_______________,
        KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  RGB_TOG, TG(_GAMING),     KC_F1,  KC_F2,  KC_F3,  KC_F4,
        ______________MOD_LEFT____________, RGB_M_P, TG(_QWERTY), KC_F5,  KC_F6,  KC_F7,  KC_F8,
        RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, RGB_SPI, KC_F9,       KC_F10, KC_F11, KC_F12
    )
};
// clang-format on
