#pragma once
#include "somepin.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts
*/
// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define ___________Q_ANGLE_MOD_L3_________                KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _______________QWERTY_HRM_L2_______________       HM_AQ,   HM_SQ,   HM_DQ,   HM_FQ,   KC_G
#define _______________QWERTY_HRM_R2_______________       KC_H,    HM_JQ,   HM_KQ,   HM_LQ,   HM_QTQ


#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define ___________C_ANGLE_MOD_L3_________                KC_X,    KC_C,    KC_D,    KC_V


#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O  
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define ______________COLEMAK_DH_HRM_L2____________       HM_AC,    HM_RC,   HM_SC,   HM_TC,   KC_G
#define ______________COLEMAK_DH_HRM_R2____________       KC_M,     HM_NC,   HM_EC,   HM_IC,   HM_OC


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define __________________FUNC_1___________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __________________FUNC_2___________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
        
#define ______________MOD_LEFT____________                KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT
#define ______________NAV_1_______________                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define ______________NAV_2_______________                KC_HOME, KC_PGDN, KC_PGUP, KC_END


#define ___________________BLANK___________________       _______, _______, _______, _______, _______
#define XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO


#define _________________LOWER_L1__________________       ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_GRV
#define _________________LOWER_L3__________________       KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_BSLS

#define _________________LOWER_R1__________________       ________________NUMBER_RIGHT_______________
#define _________________LOWER_R2_CS_______________       ______________NAV_1_______________,  KC_INS
#define _________________LOWER_R3_CS_______________       ______________NAV_2_______________,  KC_DEL

#define _________________LOWER_R2_RS_______________       ______________NAV_1_______________, KC_CAPS
#define _________________LOWER_R3_RS_______________       KC_INS,  ______________NAV_2_______________


#define _________________RAISE_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________       KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, KC_TILD
#define _________________RAISE_L3__________________       KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE

#define _________________RAISE_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12
#define _________________RAISE_R2__________________       __________________FUNC_1___________________
#define _________________RAISE_R3__________________       __________________FUNC_2___________________


#define _________________ADJUST_L1_________________       RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  RGB_TOG
#define _________________ADJUST_L2_________________       RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, RGB_M_P
#define _________________ADJUST_L3_________________       RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,  XXXXXXX

#define _________________ADJUST_R1_________________       XXXXXXX, XXXXXXX,     KC_VOLU, KC_MNXT, XXXXXXX
#define _________________ADJUST_R2_________________       XXXXXXX, TG(_GAMING), KC_VOLD, KC_MPRV, XXXXXXX
#define _________________ADJUST_R3_________________       RESET,   TG(_QWERTY), KC_MUTE, KC_MPLY, XXXXXXX
