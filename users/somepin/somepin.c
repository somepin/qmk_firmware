#include "somepin.h"
// #include "keysmash.c"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h"
#endif

// #if defined(ONESHOT_MOD_ENABLE)
// #include "oneshot.c"

// bool is_oneshot_cancel_key(uint16_t keycode) {
//     switch (keycode) {
//     case QZ_X:
//     case GH_Z:
//     case GH_X:
//     case GH_DOT:
//     case MO_LWR:
//     case MO_RSE:
//         return true;
//     default:
//         return false;
//     }
// }

// bool is_oneshot_ignored_key(uint16_t keycode) {
//     switch (keycode) {
//     case QZ_X:
//     case GH_Z:
//     case GH_X:
//     case GH_DOT:
//     case MO_LWR:
//     case MO_RSE:
//     case KC_LSFT:
//     case OS_SHFT:
//     case OS_CTRL:
//     case OS_ALT:
//     case OS_GUI:
//         return true;
//     default:
//         return false;
//     }
// }

// oneshot_state os_shft_state = os_up_unqueued;
// oneshot_state os_ctrl_state = os_up_unqueued;
// oneshot_state os_alt_state = os_up_unqueued;
// oneshot_state os_gui_state = os_up_unqueued;
// #endif

#if defined(AUDIO_ENABLE)
float tone_startup[][2] = SONG(USSR_ANTHEM);
#endif

void matrix_init_user(void) {
#if defined(BOOTLOADER_CATERINA) && defined(__AVR__)
    // supposedly turn off red pro micro led
    DDRD &= ~(1 << 5);
    PORTD &= ~(1 << 5);

    DDRB &= ~(1 << 0);
    PORTB &= ~(1 << 0);
#endif
#if defined(AUDIO_ENABLE)
    startup_user();
#endif
}

void startup_user() {
#if defined(AUDIO_ENABLE)
    PLAY_SONG(tone_startup);
#endif
}

void suspend_power_down_user(void) {
#if defined(OLED_ENABLE)
    oled_off();
#endif
}

// bool keysmash_mode = false;
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// #if defined(ONESHOT_MOD_ENABLE)
//     update_oneshot(
//         &os_shft_state, KC_LSFT, OS_SHFT,
//         keycode, record
//     );
//     update_oneshot(
//         &os_ctrl_state, KC_LCTL, OS_CTRL,
//         keycode, record
//     );
//     update_oneshot(
//         &os_alt_state, KC_LALT, OS_ALT,
//         keycode, record
//     );
//     update_oneshot(
//         &os_gui_state, KC_LGUI, OS_GUI,
//         keycode, record
//     );
// #endif
//     if (keysmash_mode) {
//         switch(keycode) {
//             case KC_A ... KC_Z:
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
//     return true;
// }

// __attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }
layer_state_t                       layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _MOUSE, _RAISE, _FN);
#if defined (COMBO_ENABLE)
    switch(get_highest_layer(state | default_layer_state)) {
        case _GAMING:
          combo_disable();
          break;
        default:
          combo_enable();
          break;
    }
#endif
    // return state;
    return layer_state_set_keymap(state);
}
