#include "somepin.h"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h"
#endif

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

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }
layer_state_t                       layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
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
    return state;
}
