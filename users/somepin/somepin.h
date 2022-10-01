#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"

enum userspace_layers {
    _BASE = 0,
    _QWERTY,
    _NUMPD,
    _GAMING,
    _MOUSE,
    _NAV,
    _NAV_NUM,
    _LOWER,
    _RAISE,
    _FN,
    _ADJUST,
};

// enum userspace_keycodes {
// #ifndef NO_CHARYBDIS_KEYCODES
//     SMASH = CHARYBDIS_SAFE_RANGE,
// #else
    // SMASH = SAFE_RANGE,
// #endif // !NO_CHARYBDIS_KEYCODES
    // Oneshot mods
//     OS_ALT,
//     OS_CTRL,
//     OS_GUI,
//     OS_SHFT,
// };

void          matrix_init_keymap(void);
void          suspend_power_down_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
// layer_state_t default_layer_state_set_keymap(layer_state_t state);

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define MO_LWR MO(_LOWER)
#define MO_RSE MO(_RAISE)
#define GH_Z LT(_RAISE, KC_Z)
#define QZ_X LT(_RAISE, KC_X)
#define GH_X LT(_LOWER, KC_X)
#define GH_DOT LT(_LOWER, KC_DOT)

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
