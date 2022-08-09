#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_NAV,
  _FN
};

enum combo_events {
    COMBO_BSP,
    COMBO_DEL,
    COMBO_NBS,
    COMBO_TAB,
    COMBO_ESC,
    COMBO_ENT,
    COMBO_SCL,
    COMBO_SLH,
};

#define KC_NUM_SPC LT(_NUM_NAV, KC_SPC)
#define KC_FZ LT(_FN, KC_Z)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GQUOT RGUI_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,
    KC_GA,  KC_AS,  KC_CD,  KC_SF,  KC_G,   KC_H,   KC_SJ,   KC_CK,   KC_AL,    KC_GQUOT,
    KC_FZ,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,
            KC_LGUI,                KC_NUM_SPC,              KC_RALT
  ),

  [_NUM_NAV] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_GRV,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_CAPS,
    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   
              _______,                      _______,                      _______         
  ),

  [_FN] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F11,   KC_F12,
              _______,                      _______,                      _______         
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bsp[] = {KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_nbs[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_scl[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_slh[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_BSP] = COMBO(combo_bsp,KC_BSPC),
    [COMBO_DEL] = COMBO(combo_del,KC_DEL),
    [COMBO_NBS] = COMBO(combo_nbs,KC_BSPC),
    [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
    [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
    [COMBO_SCL] = COMBO(combo_scl,KC_SCLN),
    [COMBO_SLH] = COMBO(combo_slh,KC_SLSH),
};
#endif