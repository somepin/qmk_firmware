#include "somepin.h"
#include "print.h"

/*
 * The `LAYOUT_pipi_gherkin_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_wrapper(...)            LAYOUT_ortho_4x10(__VA_ARGS__)
#define LAYOUT_pipi_gherkin_base( \
    K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
    K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
    K32, K33, K34, K35, K40, K41, K42, K43, K44, K45  \
  ) \
  LAYOUT_wrapper( \
      K00, K01, K02, K03, K04, K05, K10, K11, K12, K13, \
      K14, K15, K20, K21, K22, K23, K24, K25, K30, K31, \
      K32, K33, K34, K35, K40, K41, K42, K43, K44, K45, \
      LT(_NAV_NUM, KC_SPC)                              \
  )
#define LAYOUT_base_wrapper(...)       LAYOUT_pipi_gherkin_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        HM_AC, HM_RC, HM_SC, HM_TC, LT(_FN, KC_G),   ______________COLEMAK_DH_HRM_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_DVORAK] = LAYOUT_base_wrapper(
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        HM_AD, HM_OD, HM_ED, HM_UD, LT(_FN, KC_I),   _______________DVORAK_HRM_R2_______________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),

    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        HM_AQ, HM_SQ, HM_DQ, HM_FQ, LT(_FN, KC_G),   _______________QWERTY_HRM_R2_______________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_NAV_NUM] = LAYOUT_base_wrapper(
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2_CS_______________,
        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _________________LOWER_R3_CS_______________
    ),

    [_FN] = LAYOUT_base_wrapper(
        HPT_MODI, HPT_MODD, HPT_FBK,  HPT_TOG, HPT_BUZ,  TG(_DVORAK),  KC_F1, KC_F2,  KC_F3,  KC_F4,
        ______________MOD_LEFT____________, XXXXXXX,     TG(_QWERTY),  KC_F5, KC_F6,  KC_F7,  KC_F8,
        HPT_CONI, HPT_COND, HPT_CONT, HPT_RST, HPT_OFF,  XXXXXXX,      KC_F9, KC_F10, KC_F11, KC_F12
    ),
};
// clang-format on
