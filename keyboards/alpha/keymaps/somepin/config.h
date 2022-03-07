#ifdef MATRIX_COL_PINS
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D7, E6, D0, D1, B2, B3, B1, F7, F6, F5 }
#endif

#define COMBO_DICT_ALPHA

#ifdef COMBO_TERM
#undef COMBO_TERM
#define COMBO_TERM 75
#endif

#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
#define AUDIO_PIN_ALT B6
#define AUDIO_CLICKY
#endif
