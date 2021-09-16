#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"

enum userspace_layers {
    _BASE = 0,
    _QWERTY,
    _GAMING,
    _NAV,
    _LOWER,
    _RAISE,
    _ADJUST,
};

void          matrix_init_keymap(void);
void          suspend_power_down_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
// layer_state_t default_layer_state_set_keymap(layer_state_t state);

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define KC_SZ  LSFT_T(KC_Z)
#define KC_SDT RSFT_T(KC_DOT)
#define KC_GES LGUI_T(KC_ESC)
#define KC_AEN RALT_T(KC_ENT)
#define KC_CQT LCTL_T(KC_QUOT)
#define KC_CSL RCTL_T(KC_SLSH)