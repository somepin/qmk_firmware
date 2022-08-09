/* Copyright 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "qal.h"

void board_init(void) {
    // B9 is configured as I2C1_SDA in the board file; that function must be
    // disabled before using B7 as I2C1_SDA.
    setPinInputHigh(B9);
}

#ifdef RGB_MATRIX_ENABLE 

#define XX NO_LED 

led_config_t g_led_config = { {
  // Key Matrix to LED Index
	{ 0,  XX, XX, XX, XX, XX, XX, XX, XX, 11 }, \
	{ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }, \
	{ 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 }, \
	{ 12, XX, XX, XX, XX, XX, XX, XX, XX, 23 }, \
}, {
  // LED Index to Physical Position
  { 0,    0 }, { 0,   21 }, { 25,  21 }, { 50,  21 },
  { 75,  21 }, { 100, 21 }, { 125, 21 }, { 150, 21 },
  { 175, 21 }, { 200, 21 }, { 224, 21 }, { 224,  0 },
  { 224, 63 }, { 224, 42 }, { 200, 42 }, { 175, 42 },
  { 150, 42 }, { 125, 42 }, { 100, 42 }, { 75,  42 }, 
  { 50,  42 }, { 25,  42 }, { 0,   42 }, { 0,   63 }, 
}, {
  // LED Index to Flag
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };

#endif