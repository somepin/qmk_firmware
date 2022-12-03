// Copyright 2022 somepin (@somepin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SOLENOID_PIN GP28
#define SOLENOID_DEFAULT_BUZZ 1
#define SOLENOID_DEFAULT_DWELL 30
#define SOLENOID_BUZZ_ACTUATED 20
#define SOLENOID_BUZZ_NONACTUATED 30

#define AUDIO_PIN GP29
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_PWM_CHANNEL 2
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.0f
#define AUDIO_CLICKY_FREQ_DEFAULT AUDIO_CLICKY_FREQ_MAX

#define DIP_SWITCH_MATRIX_GRID { {6,6}, {6,3} } // List of row and col pairs

#define RGB_DI_PIN GP22
// #define WS2812_PIO_USE_PIO1

#ifdef RGB_DI_PIN
#define RGBLED_NUM 1
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 64
#define RGBLIGHT_SLEEP
#endif

#define ENCODERS_PAD_A { GP14 }
#define ENCODERS_PAD_B { GP15 }

// SPI settings
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18  // SCK
#define SPI_MOSI_PIN GP19 // SDA
// #define SPI_MISO_PIN   // not connected on LCD

// LCD Configuration
#define LCD_RST_PIN GP20  // RES
#define LCD_CS_PIN GP17   // CS
#define LCD_DC_PIN GP21   // RS
#ifndef LCD_ACTIVITY_TIMEOUT
#    define LCD_ACTIVITY_TIMEOUT 30000
#endif // LCD_ACTIVITY_TIMEOUT

// Backlight driver (to control LCD backlight)
#define BACKLIGHT_PIN GP16
// #define BACKLIGHT_LIMIT_VAL	128
#define BACKLIGHT_LEVELS 4
#define BACKLIGHT_PWM_DRIVER PWMD0
#define BACKLIGHT_PWM_CHANNEL 1 // RP2040_PWM_CHANNEL_A
// #define BACKLIGHT_PAL_MODE 1
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
