/* Copyright 2021
    *
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 2 of the License, or
    * (at your option) any later version.
    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    *
    * You should have received a copy of the GNU General Public License
    * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers{
    _BASE,
    _GAMING,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum combo_events {
    COMBO_BSP,
    COMBO_DEL,
    COMBO_NBS,
    COMBO_TAB,
    COMBO_ESC,
    COMBO_ENT,
    COMBO_QEN
};

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define KC_SZ  LSFT_T(KC_Z)
#define KC_SDT RSFT_T(KC_DOT)
#define KC_GES LGUI_T(KC_ESC)
#define KC_AEN RALT_T(KC_ENT)
#define KC_CQT LCTL_T(KC_QUOT)
#define KC_CSL RCTL_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,   KC_F,   KC_P,   KC_B,          KC_J,     KC_L,  KC_U,  KC_Y,     KC_QUOT,
        KC_A,    KC_R,   KC_S,   KC_T,   KC_G,          KC_M,     KC_N,  KC_E,  KC_I,     KC_O,
        KC_SZ,   KC_X,   KC_C,   KC_D,   KC_V,          KC_SCLN,  KC_K,  KC_H,  KC_COMM,  KC_SDT,
        KC_LCTL,                 KC_GES, LOWER,         RAISE,    KC_AEN,                 KC_CSL
    ),

    [_GAMING] = LAYOUT(
        KC_ESC,    KC_Q,   KC_W,   KC_E,     KC_R,          KC_T,     KC_Y,    KC_UP,   KC_I,     KC_ESC,
        KC_TAB,    KC_A,   KC_S,   KC_D,     KC_F,          KC_G,     KC_LEFT, KC_DOWN, KC_RGHT,  KC_TAB,
        KC_LSFT,   KC_Z,   KC_X,   KC_C,     KC_V,          KC_B,     KC_N,    KC_M,    KC_COMM,  KC_RSFT,
        KC_LCTL,                   KC_LALT,  KC_SPC,        RAISE,    KC_RGUI,                    KC_RCTL
    ),

    [_QWERTY] = LAYOUT(
        _______,  _______,  KC_E,     KC_R,     KC_T,           KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,   
        _______,  KC_S,     KC_D,     KC_F,     _______,        KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,
        KC_SZ,    KC_X,     KC_C,     KC_V,     KC_B,           KC_B,    KC_N,  KC_M,    _______,  _______,
        KC_CQT,             _______,  LT(_LOWER, KC_SPC),       LT(_RAISE, KC_BSPC),     _______,  _______
    ),

    [_LOWER] = LAYOUT(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_GRV,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
        KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSLS,           KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   
        _______,                      _______,  _______,           _______,  _______,                      _______         
    ),

    [_RAISE] = LAYOUT(
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_F11,   KC_F12,
        KC_RGUI,  KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TILD,           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
        KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
        _______,                      _______,  _______,           _______,  _______,                      _______         
    ),

    [_ADJUST] = LAYOUT(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   RGB_TOG,             XXXXXXX,  XXXXXXX,      KC_VOLU,  KC_MNXT,  XXXXXXX,  
        RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  RGB_M_P,             XXXXXXX,  TG(_GAMING),  KC_VOLD,  KC_MPRV,  XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   XXXXXXX,             RESET,    TG(_QWERTY),  KC_MUTE,  KC_MPLY,  XXXXXXX,  
        _______,                   _______,   _______,             _______,  _______,                          _______         
    ),
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bsp[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_nbs[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_qen[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_BSP] = COMBO(combo_bsp,KC_BSPC),
    [COMBO_DEL] = COMBO(combo_del,KC_DEL),
    [COMBO_NBS] = COMBO(combo_nbs,KC_BSPC),
    [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
    [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
    [COMBO_QEN] = COMBO(combo_qen,KC_ENT),
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef COMBO_ENABLE
    switch(get_highest_layer(state | default_layer_state)) {
        case _GAMING:
          combo_disable();
          break;
        default:
          combo_enable();
          break;
    }
#endif
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
