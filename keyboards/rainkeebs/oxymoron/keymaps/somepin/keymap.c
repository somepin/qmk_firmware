#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_fck_stabs(
        KC_TAB,           KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,           KC_J,    KC_L,    KC_U,       KC_Y,            KC_QUOT,         KC_BSPC,
        LT(2, KC_ESC),    KC_A,    KC_R,    KC_S,    KC_T,   KC_G,           KC_M,    KC_N,    KC_E,       KC_I,            KC_O,            LT(2, KC_ENT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   LT(3, KC_BSLS), KC_K,    KC_H,    KC_COMM,    LT(4, KC_DOT),   RSFT_T(KC_SLSH),
        KC_LCPO, KC_LGUI, KC_SPC,  KC_RALT, KC_RCPC
    ),

    [1] = LAYOUT_fck_stabs(
        KC_TAB,                   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,       KC_O,    KC_P,            KC_BSPC,
        LT(2, KC_ESC),            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,       KC_L,    LT(4, KC_QUOT),  LT(2, KC_ENT),
        KC_LSFT, LT(3, KC_BSLS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,  RSFT_T(KC_SLSH),
        KC_LCPO, KC_LGUI, KC_SPC, KC_RALT, KC_RCPC
    ),
    
    [2] = LAYOUT_fck_stabs(
        KC_GRV,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______,          KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, _______,
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT_fck_stabs(
        KC_F1,            KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_CAPS,          KC_NUM,  KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(1),
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        _______, _______, _______, _______, _______
    ),

    [4] = LAYOUT_fck_stabs(
        _______,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,    _______,
        _______,          KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,     XXXXXXX,    _______,
        _______, C(KC_A), C(KC_X),   C(KC_C),   C(KC_V),   XXXXXXX,   XXXXXXX,   KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,      _______,
        _______, _______, _______, _______, _______
    ),
};
