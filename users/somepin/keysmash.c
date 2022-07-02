/**
 * Copyright 2022 somepin
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "keysmash.h"

#define rot8(x,k) (((x) << (k))|((x) >> (8 - (k))))
uint8_t jsf8(void) {
    static uint8_t a = 0xf1;
    static uint8_t b = 0xee, c = 0xee, d = 0xee;

    uint8_t e = a - rot8(b, 1);
    a = b ^ rot8(c, 4);
    b = c + d;
    c = d + e;
    return d = e + a;
}

void tap_random_base10(void) {
#if defined(__AVR_ATmega32U4__)
    uint8_t key = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % 10;
#else
    uint8_t key = jsf8() % 10;
#endif
    switch (key) {
        case 0:
            send_char('a');
            break;
        case 1:
            send_char('s');
            break;
        case 2:
            send_char('d');
            break;
        case 3:
            send_char('f');
            break;
        case 4:
            send_char('g');
            break;
        case 5:
            send_char('h');
            break;
		case 6:
            send_char('j');
            break;
		case 7:
            send_char('k');
            break;
	    case 8:
            send_char('l');
            break;
	    case 9:
            send_char(';');
            break;
    }
}
