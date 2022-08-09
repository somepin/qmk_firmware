#include "somepin.h"

/*
 * The `LAYOUT_reviung41_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_reviung41(__VA_ARGS__)
#define LAYOUT_reviung41_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      KC_TAB,         K01,    K02,    K03,    K04,    K05,           K06,    K07,    K08,    K09,    K0A,    KC_BSPC,          \
      LCTL_T(KC_ESC), K11,    K12,    K13,    K14,    K15,           K16,    K17,    K18,    K19,    K1A,    RCTL_T(KC_SCLN),  \
      KC_LSFT,        K21,    K22,    K23,    K24,    K25,           K26,    K27,    K28,    K29,    K2A,    RSFT_T(KC_ENT),   \
                              LT(_NAV, KC_ESC),  LOWER,   TT(_NUMPD),  RAISE,  LT(_NAV, KC_ENT)                                \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_reviung41_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_DH_HRM_L2____________, ______________COLEMAK_DH_HRM_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_GAMING] = LAYOUT_wrapper(
        KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, _______,
        KC_LSFT, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, _______,
        KC_LCTL, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, _______,
                                           KC_ESC, KC_SPC, LOWER, RAISE, _______
    ),

    [_NAV] = LAYOUT_base_wrapper(
        XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, 
        KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, ______________NAV_1_______________, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX
    ),

    [_NUMPD] = LAYOUT_wrapper(
        XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_BSPC, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NLCK,
        XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PEQL,
        XXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PENT, KC_TAB,
                                        _______, _______, _______, KC_P0, KC_PDOT 
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_CS_______________,
        _________________LOWER_L3__________________, _________________LOWER_R3_CS_______________
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________
    ),

    [_ADJUST] = LAYOUT_base_wrapper(
        _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _________________ADJUST_R3_________________
    )
};
// clang-format on
