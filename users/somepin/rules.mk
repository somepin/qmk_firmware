SRC += somepin.c

# ifneq ($(PLATFORM),CHIBIOS)
#     ifneq ($(strip $(LTO_SUPPORTED)), no)
#         LTO_ENABLE = yes
#     endif
# endif

# ifeq ($(strip $(KEYBOARD)), somepin/qal)
# COMBO_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
# CONSOLE_ENABLE = no
# endif

ifeq ($(strip $(KEYBOARD)), reviung41)
COMBO_ENABLE = yes
NKRO_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306 
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
RGBLIGHT_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
SRC += oled.c
endif

# ifeq ($(strip $(KEYBOARD)), somepin/popcorn)
# COMBO_ENABLE = yes
# NKRO_ENABLE = yes
# OLED_ENABLE = yes
# OLED_DRIVER = SSD1306 
# SRC += oled.c
# endif

ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
ENCODER_ENABLE = yes
COMBO_ENABLE = yes
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
    VPATH  +=  keyboards/gboards/
endif
