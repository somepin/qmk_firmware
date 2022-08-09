#include "somepin.h"

float enter[][2] = SONG(SAMSUNG_NOTIF);
// float esc[][2] = SONG(HIDE_AND_SEEK);
float caps[][2] = SONG(MII);

/*
 * The `LAYOUT_alpha_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_alpha_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28            \
  ) \
  LAYOUT_wrapper( \
      K01,    K02,    K03,    K04,    K05,    K06,    K07,    K08,    K09,    K0A,  \
      K11,    K12,    K13,    K14,    K15,    K16,    K17,    K18,    K19,    K1A,  \
      K21,    K22,    K23,    K24,    K25,    K26,    K27,    K28                   \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_alpha_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        HM_AC, HM_RC, HM_SC, HM_TC, LT(_FN, KC_G),   ______________COLEMAK_DH_HRM_R2____________,
        ___________C_ANGLE_MOD_L3_________, LT(_NAV_NUM, KC_K), KC_H, KC_COMM, KC_DOT  
    ),

    [_NAV_NUM] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_RS_______________,
        KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    [_FN] = LAYOUT_base_wrapper(
        AU_ON,  AU_OFF,  AU_TOG,  CK_TOGG, XXXXXXX, XXXXXXX, KC_F1,  KC_F2,  KC_F3,  KC_F4,
        ______________MOD_LEFT____________, XXXXXXX, XXXXXXX, KC_F5,  KC_F6,  KC_F7,  KC_F8,
        CK_UP,  CK_DOWN,  CK_RST,  RESET, KC_F9, KC_F10, KC_F11, KC_F12
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        PLAY_SONG(enter);
      }
      return true; // Let QMK send the enter press/release events
    // case KC_ESC:
    //   if (record->event.pressed) {
    //     PLAY_SONG(esc);
    //   }
    //   return true;
    case KC_CAPS:
      if (record->event.pressed) {
        PLAY_SONG(caps);
      }
      return true;
    default:
      return true; // Process all other keycodes normally
  }
}