#include "popcorn.h"
#include OLED_FONT_H

static void draw_line_h(uint8_t x, uint8_t y, uint8_t len, bool on) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(i + x, y, on);
    }
}

static void draw_line_v(uint8_t x, uint8_t y, uint8_t len, bool on) {
    for (uint8_t i = 0; i < len; i++) {
        oled_write_pixel(x, i + y, on);
    }
}

void draw_rect_soft(uint8_t x, uint8_t y, uint8_t width, uint8_t height, bool on) {
    uint8_t tempHeight;

    draw_line_h(x + 1, y, width - 2, on);
    draw_line_h(x + 1, y + height - 1, width - 2, on);

    tempHeight = height - 2;

    if (tempHeight < 1) return;

    draw_line_v(x, y + 1, tempHeight, on);
    draw_line_v(x + width - 1, y + 1, tempHeight, on);
}

void write_char_at_pixel_xy(uint8_t x, uint8_t y, const char data, bool invert) {
    uint8_t i, j, temp;
    uint8_t cast_data = (uint8_t)data;

    const uint8_t *glyph = &font[(cast_data - OLED_FONT_START) * OLED_FONT_WIDTH];
    temp                 = pgm_read_byte(glyph);
    for (i = 0; i < OLED_FONT_WIDTH; i++) {
        for (j = 0; j < OLED_FONT_HEIGHT; j++) {
            if (temp & 0x01) {
                oled_write_pixel(x + i, y + j, !invert);
            } else {
                oled_write_pixel(x + i, y + j, invert);
            }
            temp >>= 1;
        }
        temp = pgm_read_byte(++glyph);
    }
}

void write_chars_at_pixel_xy(uint8_t x, uint8_t y, const char *data, bool invert) {
    uint8_t c      = data[0];
    uint8_t offset = 0;
    while (c != 0) {
        write_char_at_pixel_xy(x + offset, y, c, invert);
        data++;
        c = data[0];
        offset += 6;
    }
}

void draw_rect_filled_soft(uint8_t x, uint8_t y, uint8_t width, uint8_t height, bool on) {
    for (int i = x; i < x + width; i++) {
        if (i == x || i == (x + width - 1))
            draw_line_v(i, y + 1, height - 2, on);
        else
            draw_line_v(i, y, height, on);
    }
}

void draw_text_rectangle(uint8_t x, uint8_t y, uint8_t width, char *str, bool filled) {
    if (filled) {
        draw_rect_filled_soft(x, y, width, 11, true);
        write_chars_at_pixel_xy(x + 3, y + 2, str, true);
    } else {
        draw_rect_soft(x, y, width, 11, true);
        write_chars_at_pixel_xy(x + 3, y + 2, str, false);
    }
}
