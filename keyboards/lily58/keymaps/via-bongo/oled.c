#include QMK_KEYBOARD_H
#include "animation_frames.h"

#ifdef OLED_DRIVER_ENABLE
#define IDLE_FRAME_DURATION 200 // Idle animation iteration rate in ms

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;

bool tap_anim        = false;
bool tap_anim_toggle = false;


// Decompress and write a precompressed bitmap frame to the OLED.
// Documentation and python compression script available at:
// https://github.com/nullbitsco/squeez-o
#ifdef USE_OLED_BITMAP_COMPRESSION
static void oled_write_compressed_P(const char* input_block_map, const char* input_block_list) {
    uint16_t block_index = 0;
    for (uint16_t i=0; i<NUM_OLED_BYTES; i++) {
        uint8_t bit = i%8;
        uint8_t map_index = i/8;
        uint8_t _block_map = (uint8_t)pgm_read_byte_near(input_block_map + map_index);
        uint8_t nonzero_byte = (_block_map & (1 << bit));
        if (nonzero_byte) {
            const char data = (const char)pgm_read_byte_near(input_block_list + block_index++);
            oled_write_raw_byte(data, i);
        } else {
            const char data = (const char)0x00;
            oled_write_raw_byte(data, i);
        }
    }
}
#endif

static void render_anim(void) {
    // Idle animation
    void animation_phase(void) {
        if (!tap_anim) {
            current_idle_frame = (current_idle_frame + 1) % NUM_IDLE_FRAMES;
            uint8_t idx = abs((NUM_IDLE_FRAMES - 1) - current_idle_frame);
            #ifdef USE_OLED_BITMAP_COMPRESSION
            oled_write_compressed_P(idle_block_map[idx], idle_frames[idx]);
            #else
            oled_write_raw_P(idle_frames[idx], NUM_OLED_BYTES);
            #endif
        }
    }

    // Idle behaviour
    if (get_current_wpm() != 000) {  // prevent sleep
        oled_on();
        if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {  // Turn off screen when timer threshold elapsed or reset time since last input
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}
void render_mod_status(uint8_t modifiers) {
    oled_write_char('G', (modifiers & MOD_MASK_GUI));
    oled_write_char('A', (modifiers & MOD_MASK_ALT));
    oled_write_char('C', (modifiers & MOD_MASK_CTRL));
    oled_write_char('S', (modifiers & MOD_MASK_SHIFT));
}

void oled_task_user(void) {
    render_anim();

    led_t led_state = host_keyboard_led_state();

    oled_set_cursor(0,12);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR(""), false);

    oled_set_cursor(0, 13);
    uint8_t n = get_current_wpm();
    char wpm_counter[5];
    wpm_counter[4] = '\0';
    wpm_counter[3] = '0' + n % 10;
    wpm_counter[2] = '0' + (n /= 10) % 10;
    wpm_counter[1] = '0' + n / 10 ;
    wpm_counter[0] = '>';
    oled_write_ln(wpm_counter, false);

    oled_set_cursor(0, 14);
    switch (get_highest_layer(layer_state)) {  
        case 0:
            oled_write_P(PSTR("Base "), false); 
            break;
        case 1:
            oled_write_P(PSTR("Lower"), false); 
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Funct"), false);
            break;
        default:
            oled_write("?????", false);
            break;
    }

    oled_set_cursor(0, 15);
    render_mod_status(get_mods());
    oled_set_cursor(4,15);
    oled_write_P(led_state.num_lock ? PSTR("#") : PSTR("  "), false);
}
#endif
       
// Animate tap
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        anim_timer = timer_read32();
        if (!is_oled_on()) {
            oled_on();
        }
    }

    // Check if non-mod
    if ((keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_TAB && keycode <= KC_SLASH)) {
        if (record->event.pressed) {
            // Display tap frames
            tap_anim_toggle = !tap_anim_toggle;
            #ifdef USE_OLED_BITMAP_COMPRESSION
            oled_write_compressed_P(tap_block_map[tap_anim_toggle], tap_frames[tap_anim_toggle]);
            #else
            oled_write_raw_P(tap_frames[tap_anim_toggle], NUM_OLED_BYTES);
            #endif
        }
    } else if (!(keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_TAB && keycode <= KC_SLASH)) {
        if (record->event.pressed) {
            set_current_wpm(get_current_wpm() + 1);
        }
    } 
    #endif
    return true;
}

void suspend_power_down_user(void) {
    oled_off();
}
