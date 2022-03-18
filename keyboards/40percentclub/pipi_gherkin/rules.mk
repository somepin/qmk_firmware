# MCU name
MCU = RP2040

ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS!
SERIAL_DRIVER = pio

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes 	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	  # Mouse keys
EXTRAKEY_ENABLE = yes	  # Audio control and System control
CONSOLE_ENABLE = no	    # Console for debug
COMMAND_ENABLE = no     # Commands for debug and configuration
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
NKRO_ENABLE = no		    # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no
COMBO_ENABLE = yes
HAPTIC_ENABLE = yes
HAPTIC_DRIVER += DRV2605L

LAYOUTS = ortho_3x10 ortho_4x10
