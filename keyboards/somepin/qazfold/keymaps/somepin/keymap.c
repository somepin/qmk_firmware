#include "somepin.h"

/*
 * The `LAYOUT_qazfold_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_qazfold_base( \
    K00, K01, K02, K03, K04, K05, K06, K40, K41,  K42, \
    K10,  K11, K12, K13, K14, K15, K16, K50, K51, K52, \
    K20,    K21, K22, K23, K24, K25, K26, K43,    K53  \
    ) \
  LAYOUT_wrapper( \
      KC_ESC,    KC_TAB,                                          MO(_QWERTY), MO(_NUMPD), \
      K00,    K01,     K02,     K03,     K04,     K05,     K06,     K40,     K41,      K42, \
      K10,     K11,     K12,     K13,     K14,     K15,     K16,     K50,     K51,     K52, \
      K20,       K21,     K22,     K23,     K24,     K25,     K26,     K43,            K53, \
      KC_LCTL, KC_LGUI,             LT(_LOWER, KC_SPC),                   KC_RALT,  KC_RSFT \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_qazfold_base(__VA_ARGS__)


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

    [_NUMPD] = LAYOUT_wrapper(
        _______, _______, _______, _______,
        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_PSLS,     KC_P7,  KC_P8,  KC_P9,  KC_PMNS,
        ______________MOD_LEFT____________,  KC_NUM, KC_PAST, KC_P4,  KC_P5,  KC_P6,  KC_PPLS,
        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_P0,       KC_P1, KC_P2, KC_P3,
        XXXXXXX,  XXXXXXX,  KC_SPC,  KC_DOT, KC_PENT
    ),

    [_GAMING] = LAYOUT_wrapper(
        _______, _______, _______, _______,
        KC_ESC,   KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y,    KC_UP,   KC_I,    KC_ESC,
        KC_TAB,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
        KC_LSFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N,    KC_M,    KC_RSFT,
        KC_LCTL,  KC_LALT,  KC_SPC,  KC_RALT, KC_RCTL
    ),


    [_LOWER] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_RS_______________,
        KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAMING),     KC_F1,  KC_F2,  KC_F3,  KC_F4,
        ______________MOD_LEFT____________, XXXXXXX, TG(_QWERTY), KC_F5,  KC_F6,  KC_F7,  KC_F8,
        XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX, KC_F9,       KC_F10, KC_F11, KC_F12
    )
};
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        //              Green  Red   Blue
        // rgblight_setrgb (0x15, 0x00, 0x00); // green
        rgblight_setrgb (0x15, 0x0A, 0x00); // green
        break;
    case _QWERTY:
        rgblight_setrgb (0x15, 0x15, 0x00); // amber
        break;
    case _NUMPD:
        rgblight_setrgb (0x00, 0x00, 0x15); // blue
        break;
    case _GAMING:
        rgblight_setrgb (0x00, 0x15, 0x00); // red
        break;
    case _LOWER:
        rgblight_setrgb (0x15, 0x00, 0x15); // cyan
        break;
    case _RAISE:
        rgblight_setrgb (0x00, 0x15, 0x15); // magenta
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x15, 0x15, 0x15); // white
        break;
    }
    state = update_tri_layer_state(state, _QWERTY, _NUMPD, _GAMING);
    return state;
}
