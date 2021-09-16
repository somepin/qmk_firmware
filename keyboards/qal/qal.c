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
	{ XX, XX, XX, XX, XX, XX, XX, XX, XX, XX }, \
	{ 0,  XX, XX, XX, XX, XX, XX, XX, XX, 11 }, \
	{ 1,  2,  3,  4,  5,  6,  7,  8,  9,  10 }, \
	{ XX, XX, XX, XX, XX, XX, XX, XX, XX, XX }, \
}, {
  // LED Index to Physical Position
  { 0,   21 }, { 0,   43 }, { 25,  43 }, { 50,  43 },
  { 75,  43 }, { 100, 43 }, { 125, 43 }, { 150, 43 },
  { 175, 43 }, { 200, 43 }, { 224, 43 }, { 224, 21 }
}, {
  // LED Index to Flag
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };

#endif