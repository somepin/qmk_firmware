#include "somepin.h"

float enter[][2] = SONG(SONIC_RING);
float esc[][2] = SONG(SONIC_LOSE);

/*
 * The `LAYOUT_le_chiffre_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_le_chiffre_base( \
    K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29  \
  ) \
  LAYOUT_wrapper( \
    K00,   K01,   K02,   K03,   K04,   KC_NO,  K05,   K06,    K07,   K08,   K09, \
    K10,   K11,   K12,   K13,   K14,           K15,   K16,    K17,   K18,   K19, \
    K20,   K21,   K22,   K23,   K24,           K25,   K26,    K27,   K28,   K29, \
                        KC_GES, LOWER,         RAISE, KC_AEN                     \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_le_chiffre_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_DH_HRM_L2____________, ______________COLEMAK_DH_HRM_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _______________QWERTY_HRM_L2_______________, _______________QWERTY_HRM_R2_______________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_CS_______________,
        _________________LOWER_L3__________________, _________________LOWER_R3_CS_______________
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________
    ),

    [_ADJUST] = LAYOUT_base_wrapper(
        _________________ADJUST_L1_________________, AU_ON,   AU_TOG,      CK_UP,   XXXXXXX, XXXXXXX,
        _________________ADJUST_L2_________________, AU_OFF,  CK_TOGG,     CK_DOWN, XXXXXXX, XXXXXXX,
        _________________ADJUST_L3_________________, RESET,   TG(_QWERTY), CK_RST,  XXXXXXX, XXXXXXX
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_AEN:
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        PLAY_SONG(enter);
      }
      return true; // Let QMK send the enter press/release events
    case KC_GES:
    case KC_ESC:
      if (record->event.pressed) {
        PLAY_SONG(esc);
      }
      return true;
    default:
      return true; // Process all other keycodes normally
  }
}
