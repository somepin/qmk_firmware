#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _LWR,
  _RSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_MUTE, KC_TAB,
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LGUI, MO(_LWR) ,KC_BSPC, KC_SPC, MO(_RSE), KC_RALT, KC_RCTL
  ),

  [_LWR] = LAYOUT_split_space(
    KC_MUTE, KC_1,
    KC_1,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LGUI, KC_LALT ,KC_BSPC, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_RSE] = LAYOUT_split_space(
    KC_MUTE, KC_2,
    KC_2,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,
    KC_LCTL, KC_LGUI, KC_LALT ,KC_BSPC, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
            if(active) {
              rgblight_setrgb (0x15, 0x00, 0x15);
              haptic_enable();
              solenoid_fire_handler();
            } else { 
              rgblight_setrgb (0x15, 0x0A, 0x00);
              solenoid_fire_handler();
              haptic_disable();
            }
            break;
        case 1:
            if(active) {
              rgblight_setrgb (0x00, 0x15, 0x15);
              audio_on();
            } else {
              rgblight_setrgb (0x15, 0x0A, 0x00);
              audio_off();
            }
            break;
    }
    return true;
}


// void keyboard_post_init_user(void) {
//     rgblight_set_clipping_range(0, 2);
// }

// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _BASE:
//         //               Green Red   Blue
//         rgblight_setrgb (0x15, 0x0A, 0x00); // green
//         break;
//     case _LWR:
//         rgblight_setrgb (0x15, 0x00, 0x15); // cyan
//         break;
//     case _RSE:
//         rgblight_setrgb (0x00, 0x15, 0x15); // magenta
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (0x15, 0x15, 0x15); // white
//         break;
//     }
//     return state;
// }
