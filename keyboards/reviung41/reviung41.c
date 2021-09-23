/* Copyright 2020 gtips
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "reviung41.h"

#ifdef RGB_MATRIX_ENABLE 

#define XX NO_LED 

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    // 0,   20, 40, 60,  80,  100,      120, 140, 160, 180, 200, 220
    // K00, K01, 1, K03, 0,   K05,      K30, 9,   K32, K33, 8,   K35,
    // 2, K11, K12, K13, K14, 10,       K40, K41, K42, K43, K44, 7,  
    // K20, K21, 3, K23, K24, K25,      K50, K51, K52, 6,   K54, K55,
    //                     K60, 4, K62, 5, K64 

    { XX, XX, 1,  XX, 0,  XX }, \
    { 2,  XX, XX, XX, XX, 10 }, \
    { XX, XX, 3,  XX, XX, XX }, \
    { XX, 9,  XX, XX, 8,  XX }, \
    { XX, XX, XX, XX, XX, 7  }, \
    { XX, XX, XX, 6,  XX, XX }, \
    { XX, 4,  XX, 5,  XX, XX }  \
  }, {
  // LED Index to Physical Position
  { 80,  0  }, { 40,  0  }, { 0,   21 }, { 40,  43 },
  { 100, 64 }, { 120, 64 }, { 180, 43 }, { 220, 21 },
  { 200, 0  }, { 140, 0  }, { 100, 21 }
}, {
  // LED Index to Flag
  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };

#endif
