#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _GAMING,
    _NAV,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_charybdis_3x5(
    KC_Q,     KC_W,      KC_F,     KC_P,     KC_B,             KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    KC_A,     KC_R,      KC_S,     KC_T,     KC_G,             KC_M,     KC_N,     KC_E,     KC_I,     KC_O,   
    KC_Z,     KC_X,      KC_C,     KC_D,     KC_V,             KC_K,     KC_H,     KC_COMM,  KC_DOT, KC_SLSH,
                   KC_BTN3,  MO(_LOWER), MO(_NAV),             MO(_RAISE), KC_SPC
  ),
  
  [_GAMING] = LAYOUT_charybdis_3x5(
    KC_ESC,   KC_Q,  KC_W,     KC_E,    KC_R,    KC_T,        KC_Y,    KC_UP,   KC_I,    KC_ESC,
    KC_TAB,   KC_A,  KC_S,     KC_D,    KC_F,    KC_G,        KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB,
    KC_LSFT,  KC_Z,  KC_X,     KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_RSFT,
                               KC_NO,   KC_SPC,  KC_SPC,      TG(_GAMING), KC_NO
  ),

  [_NAV] = LAYOUT_charybdis_3x5(
    DPI_MOD,  XXXXXXX, KC_UP,   XXXXXXX,   S_D_MOD,             XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  SNP_TOG,  
    DPI_RMOD, KC_LEFT, KC_DOWN, KC_RGHT,   S_D_RMOD,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  SNIPING,
    XXXXXXX,  KC_BTN2, KC_BTN3, KC_BTN1,   XXXXXXX,             KC_WH_D,  KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_WH_U, 
                       _______, KC_BTN1,   KC_BTN2,             KC_BTN4,  KC_BTN5        
  ),

  [_LOWER] = LAYOUT_charybdis_3x5(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_GRV,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
    KC_MINS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSLS,           KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
                        _______,  _______,  _______,           KC_TAB,  KC_ENT      
  ),
  
  [_RAISE] = LAYOUT_charybdis_3x5(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_F11,   KC_F12,
    KC_RGUI,  KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TILD,           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
    KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
                        _______,  KC_ESC,   KC_BSPC,           _______,  _______         
  ),
  
  [_ADJUST] = LAYOUT_charybdis_3x5(
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   RGB_TOG,             XXXXXXX,  XXXXXXX,      KC_VOLU,  KC_MNXT,  XXXXXXX,  
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  RGB_M_P,             XXXXXXX,  TG(_GAMING),  KC_VOLD,  KC_MPRV,  XXXXXXX,
    RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,   XXXXXXX,             XXXXXXX,  MO(_NAV),     KC_MUTE,  KC_MPLY,  XXXXXXX,  
                      _______, _______,   _______,             _______,  _______        
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // https://discord.com/channels/527180441950617611/529309006494171137/825062839223451650
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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

#ifdef USB_VBUS_PIN
bool usb_vbus_state(void) {
    setPinInputLow(USB_VBUS_PIN);
    wait_us(5);
    return readPin(USB_VBUS_PIN);
}
#endif
