SRC += somepin.c

ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif

ifeq ($(strip $(KEYBOARD)), qal)
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
    VPATH  +=  keyboards/gboards/
endif