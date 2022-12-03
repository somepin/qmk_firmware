#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _QWERTY,
  _LWR,
  _RSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    C(KC_W),      KC_ESC,
    KC_Q,         KC_W,    KC_F,    KC_P,     KC_B,   KC_J,     KC_L,    KC_U,           KC_Y,   KC_BSPC,
    KC_A,         KC_R,    KC_S,    KC_T,     KC_G,   KC_M,     KC_N,    KC_E,           KC_I,   KC_O,
    KC_X,         KC_C,    KC_D,    KC_V,     KC_Z,   KC_K,     KC_H,    KC_COMM,        KC_DOT,
    KC_LCTL,      KC_LGUI, KC_LSFT, MO(_LWR), KC_SPC, KC_RSFT, KC_RALT, KC_RCTL 
  ),

  [_QWERTY] = LAYOUT_split_space(
    _______, _______,
    _______, _______, KC_E,     KC_R,    KC_T,    KC_Y,     KC_U,   KC_I,    KC_O,   KC_P,
    _______, KC_S,    KC_D,     KC_F,    _______, KC_H,     KC_J,   KC_K,    KC_L,   KC_BSPC,
    KC_Z,    KC_X,    KC_C,     _______, KC_B,    KC_N,     KC_M,   KC_COMM, KC_DOT,
    _______, _______,  _______, _______, _______, _______, _______, _______ 
  ),

  [_LWR] = LAYOUT_split_space(
    KC_MPLY, KC_TAB,
    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_GRV,  KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME,  KC_PGDN, KC_PGUP, KC_END,
    KC_CAPS, KC_NUM,  XXXXXXX, _______,  KC_ENT,  _______,  KC_SLSH,  KC_SCLN
  ),

  [_RSE] = LAYOUT_split_space(
    QK_BOOT,       CK_RST,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,     KC_F1,   KC_F2,  KC_F3,  KC_F4,
    OSM(MOD_RGUI), OSM(MOD_RALT), OSM(MOD_RCTL), OSM(MOD_RSFT), XXXXXXX, TG(_QWERTY), KC_F5,   KC_F6,  KC_F7,  KC_F8,
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, KC_F9,       KC_F10,  KC_F11, KC_F12,
    _______,       _______,       _______,       _______,       _______, _______,     _______, _______
  )
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This is called when the override activates and deactivates. Enable the fn layer on activation and disable on deactivation
bool momentary_layer(bool key_down, void *layer) {
    if (key_down) {
        layer_on((uint8_t)(uintptr_t)layer);
    } else {
        layer_off((uint8_t)(uintptr_t)layer);
    }

    return false;
}

const key_override_t fn_override = {.trigger_mods          = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL),                       //
                                   .layers                 = ~(1 << _RSE),                                              //
                                   .suppressed_mods        = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL),                       //
                                   .options                = ko_option_no_unregister_on_other_key_down,                 //
                                   .negative_mod_mask      = (uint8_t) ~(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL)),          //
                                   .custom_action          = momentary_layer,                                           //
                                   .context                = (void *)_RSE,                                              //
                                   .trigger                = KC_NO,                                                     //
                                   .replacement            = KC_NO,                                                     //
                                   .enabled                = NULL};

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &fn_override,
    NULL // Null terminate the array of overrides!
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _BASE:
        case _QWERTY:
            if (index == 0) {
                if (clockwise) {
                    tap_code16(C(KC_PGDN));
                } else {
                    tap_code16(C(KC_PGUP));
                }
            }
            break;
        case _LWR:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            }
            break;
        case _RSE:
            if (index == 0) {
                if (clockwise) {
                    clicky_freq_up();
                } else {
                    clicky_freq_down();
                }
            }
            break;
    }
    return false;
}

#define LED_RED 0x00, 0x15, 0x00
#define LED_BLUE 0x00, 0x00, 0x15
#define LED_GREEN 0x15, 0x0A, 0x00
#define LED_CYAN 0x15, 0x00, 0x15
#define LED_MAGENTA 0x00, 0x15, 0x15

bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
            if(active) {
              rgblight_setrgb(LED_CYAN);
              haptic_enable();
            } else { 
              rgblight_setrgb(LED_GREEN);
              haptic_disable();
            }
            break;
        case 1:
            if(active) {
              rgblight_setrgb(LED_MAGENTA);
              audio_on();
            } else {
              rgblight_setrgb(LED_GREEN);
              audio_off();
            }
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LWR:
        rgblight_setrgb(LED_BLUE);
        break;
    case _RSE:
        rgblight_setrgb(LED_RED);
        break;
    default: //  for any other layers, or the default layer
        if (haptic_get_enable() == 1) {
          rgblight_setrgb(LED_CYAN);
        } else if (audio_is_on()) {
          rgblight_setrgb(LED_MAGENTA);
        } else {
          rgblight_setrgb(LED_GREEN);
        }
        break;
    }
    return state;
}
