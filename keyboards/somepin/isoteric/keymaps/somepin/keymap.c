#include "somepin.h"

/*
 * The `LAYOUT_isoteric_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_default(__VA_ARGS__)
#define LAYOUT_isoteric_base( \
    K00,   K10,   K01,   K11,   K02,   K12,   K03,   K13,   K04,          \
    K20,   K31,   K21,   K32,   K22,   K33,   K23,   K34,   K24,  K14,    \
    K40,   K51,   K41,   K52,   K42,   K53,   K43,   K54                  \
  ) \
  LAYOUT_wrapper( \
    K00,   K10,   K01,   K11,   K02,   K12,   K03,   K13,   K04,          \
    K20,   K31,   K21,   K32,   K22,   K33,   K23,   K34,   K24,  K14,    \
    K40,   K51,   K41,   K52,   K42,   K53,   K43,   K54,                 \
                KC_LGUI,    LT(_LOWER, KC_SPC),     KC_RALT               \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_isoteric_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, KC_J, KC_L, KC_U, KC_Y,
        HM_AC,  HM_RC, HM_SC, HM_TC,  LT(_RAISE, KC_G), ______________COLEMAK_DH_HRM_R2____________,
        KC_X,    KC_C,    KC_D,    KC_V,   KC_K,   KC_H,   KC_COMM,   KC_DOT
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, KC_6,    KC_7,    KC_8,    KC_9,
        LGUI_T(KC_MINS), KC_LALT, KC_LCTL, KC_LSFT, KC_GRV, ______________NAV_1_______________,  KC_0,
        KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_F1,  KC_F2,  KC_F3,  
        ______________MOD_LEFT____________, XXXXXXX, KC_F5,  KC_F6,  KC_F7,  KC_F8, KC_F4,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,       KC_F10, KC_F11, KC_F12
    )
};
// clang-format on
