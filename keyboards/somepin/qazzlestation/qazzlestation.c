// Copyright 2022 somepin
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qazzlestation.h"
#include "qp.h"
#include "qazfold-screen.qgf.h"
#include "qp_st77xx_opcodes.h"
#include "qp_st7735_opcodes.h"
#include "qp_comms.h"

painter_device_t lcd;
kb_runtime_config kb_state;
__attribute__((weak)) void draw_ui_user(void) {}

//----------------------------------------------------------
// Automatic viewport offsets

#ifndef ST7735_NO_AUTOMATIC_OFFSETS
static inline void st7735_automatic_viewport_offsets(painter_device_t device, painter_rotation_t rotation) {
    struct painter_driver_t *driver = (struct painter_driver_t *)device;

    // clang-format off
    const struct {
        uint16_t offset_x;
        uint16_t offset_y;
    } rotation_offsets_80x160[] = {
        [QP_ROTATION_0]   = { .offset_x = 24, .offset_y =  0 },
        [QP_ROTATION_90]  = { .offset_x =  0, .offset_y = 24 },
        [QP_ROTATION_180] = { .offset_x = 24, .offset_y =  0 },
        [QP_ROTATION_270] = { .offset_x =  0, .offset_y = 24 },
    };
    // clang-format on

    if (driver->panel_width == 80 && driver->panel_height == 160) {
        driver->offset_x = rotation_offsets_80x160[rotation].offset_x;
        driver->offset_y = rotation_offsets_80x160[rotation].offset_y;
    }
}
#endif // ST7735_NO_AUTOMATIC_OFFSETS

//----------------------------------------------------------
// Initialisation

bool qp_st7735_init(painter_device_t device, painter_rotation_t rotation) {
    // clang-format off
    const uint8_t st7735_init_sequence[] = {
        // Command,                 Delay, N, Data[N]
        ST77XX_CMD_RESET,            120,  0,
        ST77XX_CMD_SLEEP_OFF,          5,  0,
        ST7735_SET_PGAMMA,             0, 16, 0x10, 0x0E, 0x02, 0x03, 0x0E, 0x07, 0x02, 0x07, 0x0A, 0x12, 0x27, 0x37, 0x00, 0x0D, 0x0E, 0x10,
        ST7735_SET_NGAMMA,             0, 16, 0x10, 0x0E, 0x03, 0x03, 0x0F, 0x06, 0x02, 0x08, 0x0A, 0x13, 0x26, 0x36, 0x00, 0x0D, 0x0E, 0x10,
        ST77XX_SET_PIX_FMT,            0,  1, 0x55,
        ST77XX_CMD_INVERT_OFF,         0,  0,
        ST77XX_CMD_NORMAL_ON,          0,  0,
        ST77XX_CMD_DISPLAY_ON,        20,  0
    };
    // clang-format on
    qp_comms_bulk_command_sequence(device, st7735_init_sequence, sizeof(st7735_init_sequence));

    // Configure the rotation (i.e. the ordering and direction of memory writes in GRAM)
    const uint8_t madctl[] = {
        [QP_ROTATION_0]   = ST77XX_MADCTL_RGB,
        [QP_ROTATION_90]  = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MX | ST77XX_MADCTL_MV,
        [QP_ROTATION_180] = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MX | ST77XX_MADCTL_MY,
        [QP_ROTATION_270] = ST77XX_MADCTL_RGB | ST77XX_MADCTL_MV | ST77XX_MADCTL_MY,
    };
    qp_comms_command_databyte(device, ST77XX_SET_MADCTL, madctl[rotation]);

#ifndef ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS
    st7735_automatic_viewport_offsets(device, rotation);
#endif // ST7735_NO_AUTOMATIC_VIEWPORT_OFFSETS

    return true;
}

void keyboard_post_init_kb(void) {
    // Let the LCD get some power...
    wait_ms(150);

    // Initialise the LCD
    lcd = qp_st7735_make_spi_device(128, 160, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_90);

    static painter_image_handle_t my_image;
    my_image = qp_load_image_mem(gfx_qazfold_screen);
    if (my_image != NULL) {
        qp_drawimage(lcd, 0, 0, my_image);
    }

    // Allow for user post-init
    keyboard_post_init_user();
}

void kb_state_update(void) {
    // Turn off the LCD if there's been no matrix activity
    kb_state.lcd_power = (last_input_activity_elapsed() < LCD_ACTIVITY_TIMEOUT) ? 1 : 0;
}

//----------------------------------------------------------
// Housekeeping

void housekeeping_task_kb(void) {
    kb_state_update();
    if (kb_state.lcd_power) {
        backlight_level_noeeprom(3);
    } else {
        backlight_level_noeeprom(0);
    }
    static bool lcd_on = false;
    if (lcd_on != (bool)kb_state.lcd_power) {
        lcd_on = (bool)kb_state.lcd_power;
        qp_power(lcd, lcd_on);
    }
    if (kb_state.lcd_power) {
        draw_ui_user();
    }
}
