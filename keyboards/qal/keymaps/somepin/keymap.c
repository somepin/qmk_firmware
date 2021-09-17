#include "somepin.h"

/*
 * The `LAYOUT_qal_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_qal_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      K01,     K02,    K03,    K04,    K05,           K06,      K07,    K08,    K09,    K0A,   \
      K11,     K12,    K13,    K14,    K15,           K16,      K17,    K18,    K19,    K1A,   \
      K21,     K22,    K23,    K24,    K25,           K26,      K27,    K28,    K29,    K2A,   \
      KC_LCTL,                 KC_GES, LOWER,         RAISE,    KC_AEN,                 KC_CSL \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_qal_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        KC_SZ,   ___________C_ANGLE_MOD_L3_________, KC_SCLN,  KC_K,  KC_H,  KC_COMM,  KC_SDT
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _______, ___________Q_ANGLE_MOD_L3_________, _______,   KC_N,   KC_M,  _______,  _______
    ),

    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,   KC_Q,  KC_W,  KC_E,    KC_R,   KC_T,        KC_Y,    KC_UP,   KC_I,    KC_ESC,
        KC_TAB,   KC_A,  KC_S,  KC_D,    KC_F,   KC_G,        KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
        KC_LSFT,  KC_Z,  KC_X,  KC_C,    KC_V,   KC_B,        KC_N,    KC_M,    KC_COMM, KC_RSFT,
        KC_LCTL,                KC_LALT, KC_SPC, TG(_GAMING), KC_RGUI,                   KC_RCTL
    ),

    [_LOWER] = LAYOUT_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_RS_______________,
        _________________LOWER_L3__________________, _________________LOWER_R3_RS_______________,
        _______,                   _______, _______, _______, _______,                   _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________,
        _______,                   _______, _______, _______, _______,                   _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _________________ADJUST_R3_________________,
        _______,                   _______, _______, _______, _______,                   _______
    )
};
// clang-format on