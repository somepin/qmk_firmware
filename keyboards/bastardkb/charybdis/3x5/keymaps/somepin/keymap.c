/**
 * Copyright 2022 somepin
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "somepin.h"

/*
 * The `LAYOUT_skeletyl_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_charybdis_3x5(__VA_ARGS__)
#define LAYOUT_charybdis_3x5_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
      K01,     K02,    K03,        K04,        K05,           K06,        K07,    K08,    K09,    K0A,   \
      K11,     K12,    K13,        K14,        K15,           K16,        K17,    K18,    K19,    K1A,   \
      K21,     K22,    K23,        K24,        K25,           K26,        K27,    K28,    K29,    K2A,   \
                   KC_BTN3, MO(_MOUSE),     MO_LWR,           MO_RSE,     KC_SPC                         \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_charybdis_3x5_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,  KC_Q, KC_W, KC_E,   KC_R,   KC_T,        KC_Y,        KC_UP,   KC_I,    KC_ESC,
        KC_TAB,  KC_A, KC_S, KC_D,   KC_F,   KC_G,        KC_LEFT,     KC_DOWN, KC_RGHT, KC_TAB,
        KC_LSFT, KC_Z, KC_X, KC_C,   KC_V,   KC_B,        KC_N,        KC_M,    KC_COMM, KC_RSFT,
                          XXXXXXX, KC_SPC, KC_SPC,        TG(_GAMING), XXXXXXX
    ),

    [_MOUSE] = LAYOUT_base_wrapper(
        DPI_MOD,  XXXXXXX, KC_UP,   XXXXXXX, S_D_MOD,      XXXXXXX,  KC_WH_D,  KC_WH_U,  XXXXXXX,  SNP_TOG,
        DPI_RMOD, KC_LEFT, KC_DOWN, KC_RGHT, S_D_RMOD,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  SNIPING,
        XXXXXXX,  XXXXXXX, KC_BTN1, KC_BTN1, XXXXXXX,      KC_BTN4,  KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_BTN5
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
        OS_GUI,   OS_ALT,   OS_CTRL,  OS_SHFT,  KC_GRV,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
        KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSLS,           KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NUM
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,    KC_ASTR,    KC_INS,   KC_DEL,
        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TILD,           XXXXXXX,  OS_SHFT,    OS_CTRL,    OS_ALT,   OS_GUI,
        KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           C(KC_L),  C(KC_PGDN), C(KC_PGUP), C(KC_W),  C(KC_TAB)
    ),

    [_FN] = LAYOUT_base_wrapper(
        KC_F1,         KC_F2,      KC_F3,      KC_F4,         KC_F5,            KC_F8,      KC_F9,      KC_F10,   KC_F11,     KC_F12,  
        OS_GUI,        OS_ALT,     OS_CTRL,    OS_SHFT,       KC_F6,            KC_F7,      OS_SHFT,    OS_CTRL,  OS_ALT,     OS_GUI,
        LCAG(KC_LEFT), G(KC_LEFT), G(KC_RGHT), LCAG(KC_RGHT), XXXXXXX,          S(KC_LEFT), S(KC_DOWN), S(KC_UP), S(KC_RGHT), C(KC_A)
    ),

    [_ADJUST] = LAYOUT_base_wrapper(
        RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  RGB_TOG,              HPT_FBK, HPT_TOG,     KC_VOLU,  KC_MNXT,  HPT_DWLI,
        RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, RGB_M_P,              HPT_RST, TG(_GAMING), KC_VOLD,  KC_MPRV,  HPT_DWLD,
        RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,  SMASH,                QK_BOOT, TG(_QWERTY), KC_MUTE,  KC_MPLY,  HPT_BUZ
    )
};
// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    return false;
}
