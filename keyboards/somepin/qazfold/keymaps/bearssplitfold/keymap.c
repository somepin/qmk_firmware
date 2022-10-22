#include QMK_KEYBOARD_H
#include "bears/bears.h"
#include "bears/keymap_combo.h"
#include "bears/macros.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    DYN_REC_START2, DYN_MACRO_PLAY2, MO(_COL), MO(_CUS),
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    LT(_NAV,KC_A),  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_QUOT,
    MT(MOD_LSFT, KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMMA, MT(MOD_RSFT,KC_DOT),
    KC_LCTL, KC_LGUI, KC_LALT, MT(MOD_LCTL,KC_SPACE),  LT(_NUM_SYM,KC_SPACE),  DYN_REC_START1, DYN_MACRO_PLAY1, KC_RALT
  ),

  [_NUM_SYM] = LAYOUT_split_space(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TRNS, DYN_REC_START1, DYN_MACRO_PLAY1, KC_F, KC_G, KC_SCLN, KC_MINS, KC_EQL, KC_QUOT, KC_NO,
    KC_TRNS, DYN_REC_START2, DYN_MACRO_PLAY2, DYN_REC_STOP, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,
    KC_TRNS, KC_TRNS, RGB_MODE_FORWARD, KC_TRNS, KC_TRNS, RGB_VAI, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT_split_space(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_PGUP,
    KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL, LOCK_SHIFT, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_TRNS, CUT, COPY, LCTL(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_COL] = LAYOUT_split_space(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,     KC_QUOT,
    LT(_NAV,KC_A),  KC_R,  KC_S,  KC_T,   KC_D,   KC_H,  KC_N,   KC_E,  KC_I, KC_O,
    MT(MOD_LSFT, KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M, KC_COMMA, MT(MOD_RSFT,KC_DOT),
    KC_LCTRL, KC_LGUI, KC_LALT, MT(MOD_LCTL,KC_SPACE),  LT(_NUM_SYM,KC_SPACE),  KC_RALT, DYN_REC_START1, DYN_MACRO_PLAY1
  ),

  [_CUS] = LAYOUT_split_space(
    DYN_REC_START2, DYN_MACRO_PLAY2, MO(_COL), MO(_CUS),
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    LT(_NAV,KC_A),  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_QUOT,
    MT(MOD_LSFT, KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMMA, MT(MOD_RSFT,KC_DOT),
    KC_LCTRL, KC_LGUI, KC_LALT, MT(MOD_LCTL,KC_SPACE),  LT(_NUM_SYM,KC_SPACE),  KC_RALT, DYN_REC_START1, DYN_MACRO_PLAY1
  ),
};

#ifdef #MATRIX_MASKED
const matrix_row_t matrix_mask[MATRIX_ROWS] =
{
  0b1111111,
  0b1111111,
  0b1111111,
  0b0111111,
  0b1111111,
  0b1111111,
  0b1111111,
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        //              Green  Red   Blue
        rgblight_setrgb (0x15, 0x00, 0x00); // green
        break;
    case _NAV:
        rgblight_setrgb (0x00, 0x00, 0x15); // blue
        break;
    case _NUM_SYM:
        rgblight_setrgb (0x15, 0x15, 0x00); // amber
        break;
    case _COL:
        rgblight_setrgb (0x00, 0x15, 0x15); // magenta
        break;
    case _CUS:
        rgblight_setrgb (0x15, 0x00, 0x15); // cyan
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x15, 0x15, 0x15); // white
        break;
    }
  return state;
}
