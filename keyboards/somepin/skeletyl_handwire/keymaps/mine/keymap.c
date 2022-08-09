#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" 

enum layer_names {
    _BASE,
    _QWERTY,
    _NAV,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define NUMPD  MO(_NUMPD)

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

// Right-hand home row mods
#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,              KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    HM_A,     HM_R,     HM_S,     HM_T,     KC_G,              KC_M,     HM_N,     HM_E,     HM_I,     HM_O,   
    KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,              KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,
              LT(_NAV, KC_ESC),   LOWER,    KC_DEL,            KC_ENT,   RAISE,    LT(_NAV, KC_TAB)
  ),
  
  [_QWERTY] = LAYOUT(
    _______,       _______,  KC_E,     KC_R,     KC_T,              KC_Y,  KC_U,     KC_I,     KC_O,     KC_P,   
    LSFT_T(KC_A),  KC_S,     KC_D,     KC_F,     _______,           KC_H,  KC_J,     KC_K,     KC_L,     RSFT_T(KC_SCLN),
    LCTL_T(KC_Z),  _______,  _______,  KC_V,     KC_B,              KC_N,  KC_M,     _______,  _______,  RCTL_T(KC_SLSH),
                   LALT_T(KC_ESC),     _______,  _______,           _______, _______, RGUI_T(KC_TAB)         
  ), 

  [_GAMING] = LAYOUT(
    KC_ESC,   KC_Q,  KC_W,     KC_E,    KC_R,    KC_T,        KC_Y,    KC_UP,   KC_I,    KC_ESC,
    KC_TAB,   KC_A,  KC_S,     KC_D,    KC_F,    KC_G,        KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
    KC_LSFT,  KC_Z,  KC_X,     KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_RSFT,
                     KC_NO,  KC_SPC,  KC_SPC,    TG(_GAMING), KC_NO,   KC_NO
  ),

  [_NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,   XXXXXXX,             KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1,   XXXXXXX,             XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  
                      _______, _______,   _______,             _______,  _______,  _______         
  ),

  [_LOWER] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_GRV,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
    KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSLS,           KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
                        _______,  _______,  RESET,             _______,  _______,  _______         
  ),
  
  [_RAISE] = LAYOUT(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_F11,   KC_F12,
    KC_RGUI,  KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TILD,           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
    KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
                        _______,  _______,  _______,           RESET,  _______,  _______         
  ),
  
  [_ADJUST] = LAYOUT(
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   RGB_TOG,             XXXXXXX,  XXXXXXX,      KC_VOLU,  KC_MNXT,  XXXXXXX,  
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  RGB_M_P,             XXXXXXX,  TG(_GAMING),      KC_VOLD,  KC_MPRV,  XXXXXXX,
    RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,   XXXXXXX,             RESET,    TG(_QWERTY),  KC_MUTE,  KC_MPLY,  XXXXXXX,  
                      _______, _______,   _______,             _______,  _______,      _______         
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // https://discord.com/channels/527180441950617611/529309006494171137/825062839223451650
    #ifdef COMBO_ENABLE
        switch(get_highest_layer(state)) {
        case _QWERTY:
            combo_disable();
            break;
        default:
            combo_enable();
            break;
        }
    #endif // COMBO_ENABLE

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
