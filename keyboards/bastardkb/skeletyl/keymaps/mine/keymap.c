/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x5_3(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,              KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    LGUI_T(KC_A),     LALT_T(KC_R),     LCTL_T(KC_S),     LSFT_T(KC_T),     KC_G,              KC_M,     RSFT_T(KC_N),     RCTL_T(KC_E),     LALT_T(KC_I),     RGUI_T(KC_O),   
    KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,              KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,
              LT(3, KC_ESC),   LT(4, KC_BSPC),    KC_DEL,            KC_ENT,   LT(5, KC_SPC),    LT(3, KC_TAB)
  ),
  
  [1] = LAYOUT_split_3x5_3(
    _______,       _______,  KC_E,     KC_R,     KC_T,              KC_Y,  KC_U,     KC_I,     KC_O,     KC_P,   
    LSFT_T(KC_A),  KC_S,     KC_D,     KC_F,     _______,           KC_H,  KC_J,     KC_K,     KC_L,     RSFT_T(KC_SCLN),
    LCTL_T(KC_Z),  _______,  _______,  KC_V,     KC_B,              KC_N,  KC_M,     _______,  _______,  RCTL_T(KC_SLSH),
                   LALT_T(KC_ESC),     _______,  _______,           _______, _______, RGUI_T(KC_TAB)         
  ), 

  [2] = LAYOUT_split_3x5_3(
    KC_ESC,   KC_Q,  KC_W,     KC_E,    KC_R,    KC_T,        KC_Y,    KC_UP,   KC_I,    KC_ESC,
    KC_TAB,   KC_A,  KC_S,     KC_D,    KC_F,    KC_G,        KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
    KC_LSFT,  KC_Z,  KC_X,     KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_RSFT,
                                KC_NO,  KC_SPC,  KC_SPC,    TG(2), KC_NO,   KC_NO
  ),

  [3] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,   XXXXXXX,             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1,   XXXXXXX,             XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  
                      _______, _______,   _______,             _______,  _______,  _______         
  ),

  [4] = LAYOUT_split_3x5_3(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_GRV,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
    KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSLS,           KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
                        _______,  _______,  RESET,             _______,  _______,  _______         
  ),
  
  [5] = LAYOUT_split_3x5_3(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_F11,   KC_F12,
    KC_RGUI,  KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TILD,           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
    KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
                        _______,  _______,  _______,           RESET,  _______,  _______         
  ),
  
  [6] = LAYOUT_split_3x5_3(
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   RGB_TOG,             XXXXXXX,  XXXXXXX,      KC_VOLU,  KC_MNXT,  XXXXXXX,  
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  RGB_M_P,             XXXXXXX,  TG(2),      KC_VOLD,  KC_MPRV,  XXXXXXX,
    RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,   XXXXXXX,             RESET,    TG(1),  KC_MUTE,  KC_MPLY,  XXXXXXX,  
                      _______, _______,   _______,             _______,  _______,      _______         
  ),
};
