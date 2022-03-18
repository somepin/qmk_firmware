#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"

enum userspace_layers {
    _BASE = 0,
    _COLEMAK,
    _DVORAK,
    _QWERTY,
    _GAMING,
    _NAV,
    _NAV_NUM,
    _NUMPD,
    _FN,
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

// QAZ/QAL modtaps
#define KC_SZ  LSFT_T(KC_Z)
#define KC_SDT RSFT_T(KC_DOT)
#define KC_GES LGUI_T(KC_ESC)
#define KC_AEN RALT_T(KC_ENT)
#define KC_CQT LCTL_T(KC_QUOT)
#define KC_CSL RCTL_T(KC_SLSH)

// Left-hand home row mods Colemak
#define HM_AC LGUI_T(KC_A)
#define HM_RC LALT_T(KC_R)
#define HM_SC LCTL_T(KC_S)
#define HM_TC LSFT_T(KC_T)

// Right-hand home row mods Colemak
#define HM_NC RSFT_T(KC_N)
#define HM_EC RCTL_T(KC_E)
#define HM_IC LALT_T(KC_I)
#define HM_OC RGUI_T(KC_O)

// Left-hand home row mods QWERTY
#define HM_AQ LGUI_T(KC_A)
#define HM_SQ LALT_T(KC_S)
#define HM_DQ LCTL_T(KC_D)
#define HM_FQ LSFT_T(KC_F)

// Right-hand home row mods QWERTY
#define HM_JQ RSFT_T(KC_J)
#define HM_KQ RCTL_T(KC_K)
#define HM_LQ LALT_T(KC_L)
#define HM_QTQ RGUI_T(KC_QUOT)

// Left-hand home row mods Dvorak
#define HM_AD LGUI_T(KC_A)
#define HM_OD LALT_T(KC_O)
#define HM_ED LCTL_T(KC_E)
#define HM_UD LSFT_T(KC_U)

// Right-hand home row mods Dvorak
#define HM_HD RSFT_T(KC_H)
#define HM_TD RCTL_T(KC_T)
#define HM_ND LALT_T(KC_N)
#define HM_SD RGUI_T(KC_S)
