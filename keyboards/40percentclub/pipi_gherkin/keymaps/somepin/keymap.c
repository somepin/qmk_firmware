#include "somepin.h"

/*
 * The `LAYOUT_pipi_gherkin_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_ortho_3x10(__VA_ARGS__)
#define LAYOUT_pipi_gherkin_base( \
    K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
    K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
    K32, K33, K34, K35, K40, K41, K42, K43, K44, K45  \
  ) \
  LAYOUT_wrapper( \
      K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
      K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
      K32, K33, K34, K35, K40, K41, K42, K43, K44, K45 \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_pipi_gherkin_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSPC,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        GH_Z, GH_X,  KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, GH_DOT, KC_SPC
    ),

    [_LOWER] = LAYOUT_base_wrapper(
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
        OS_GUI,   OS_ALT,   OS_CTRL,  OS_SHFT,  KC_GRV,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_QUOT,
        KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_SLSH
    ),

    [_RAISE] = LAYOUT_base_wrapper(
        KC_F1,   KC_F2,      KC_F3,      KC_F4,         KC_F5,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  
        KC_CAPS, KC_ESC,     KC_TAB,     KC_DEL,        KC_F6,   KC_F7,   OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        SMASH, G(KC_LEFT), G(KC_RGHT), LCAG(KC_RGHT), QK_BOOT, KC_SCLN, KC_ENT,  XXXXXXX, XXXXXXX, HPT_FBK
    )
};
// clang-format on
