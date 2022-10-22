#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" 

enum layer_names {
    _BASE,
    _GAMING,
    _NAV,
    _LOWER,
    _RAISE,
    _ADJUST
};

// enum my_keycodes {
//   SMASH = CHARYBDIS_SAFE_RANGE,
// };

#define NV_COMM LT(_NAV, KC_COMM)

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

  [_BASE] = LAYOUT_charybdis_3x5(
    KC_Q,     KC_W,      KC_F,     KC_P,     KC_B,             KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,
    HM_A,     HM_R,      HM_S,     HM_T,     KC_G,             KC_M,     HM_N,     HM_E,     HM_I,     HM_O,   
    KC_Z,     KC_X,      KC_C,     KC_D,     KC_V,             KC_K,     KC_H,     NV_COMM,  KC_DOT, KC_SLSH,
    KC_BTN3,  LT(_LOWER, KC_BSPC), LT(_NAV, KC_DEL),           LT(_NAV, KC_ENT),   LT(_RAISE, KC_SPC)
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
                        _______,  _______,  QK_BOOT,           _______,  _______      
  ),
  
  [_RAISE] = LAYOUT_charybdis_3x5(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_F11,   KC_F12,
    KC_RGUI,  KC_RALT,  KC_RCTL,  KC_RSFT,  KC_TILD,           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
    KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
                        _______, _______,   _______,           QK_BOOT,  _______        
  ),
  
  [_ADJUST] = LAYOUT_charybdis_3x5(
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,   RGB_TOG,             HPT_FBK,  HPT_TOG,      KC_VOLU,  KC_MNXT,  HPT_DWLI,  
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,  RGB_M_P,             HPT_RST,  TG(_GAMING),  KC_VOLD,  KC_MPRV,  HPT_DWLD,
    RGB_SPD, RGB_SPI, KC_LCBR, KC_RCBR,   XXXXXXX,               QK_BOOT,  MO(_NAV),     KC_MUTE,  KC_MPLY,  HPT_BUZ,  
                      _______, _______,   _______,             _______,  _______        
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // https://discord.com/channels/527180441950617611/529309006494171137/825062839223451650
    #ifdef COMBO_ENABLE
        switch(get_highest_layer(state)) {
        case _GAMING:
            combo_disable();
            break;
        default:
            combo_enable();
            break;
        }
    #endif // COMBO_ENABLE

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


// #define rot8(x,k) (((x) << (k))|((x) >> (8 - (k))))
// uint8_t jsf8(void) {
//     static uint8_t a = 0xf1;
//     static uint8_t b = 0xee, c = 0xee, d = 0xee;

//     uint8_t e = a - rot8(b, 1);
//     a = b ^ rot8(c, 4);
//     b = c + d;
//     c = d + e;
//     return d = e + a;
// }

// void tap_random_base10(void) {
// #if defined(__AVR_ATmega32U4__)
//     uint8_t key = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % 10;
// #else
//     uint8_t key = jsf8() % 10;
// #endif
//     switch (key) {
//         case 0:
//             send_char('a');
//             break;
//         case 1:
//             send_char('s');
//             break;
//         case 2:
//             send_char('d');
//             break;
//         case 3:
//             send_char('f');
//             break;
//         case 4:
//             send_char('g');
//             break;
//         case 5:
//             send_char('h');
//             break;
// 		case 6:
//             send_char('j');
//             break;
// 		case 7:
//             send_char('k');
//             break;
// 	    case 8:
//             send_char('l');
//             break;
// 	    case 9:
//             send_char(';');
//             break;
//     }
// }

// bool keysmash_mode = false;
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (keysmash_mode) {
//         switch(keycode) {
//             case KC_A ... KC_Z:
//             case KC_SCLN:
//             case KC_QUOT:
//             case KC_COMM:
//             case KC_DOT:
//             case KC_SLSH:
//             case HM_A:
//             case HM_R:
//             case HM_S:
//             case HM_T:
//             case HM_N:
//             case HM_E:
//             case HM_I:
//             case HM_O:
//                 if (record->event.pressed) {
//                     tap_random_base10();
//                     return false;
//                     break;
//                 }
//         }
//     }
//     switch(keycode) {
//         case SMASH:
//             if (record->event.pressed) {
//                 keysmash_mode ^= 1;
//             }
//         return false; 
//         break;
//         default:
//             return true; 
//     }
// }