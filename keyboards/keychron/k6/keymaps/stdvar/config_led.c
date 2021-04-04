#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix.h"
#include "config_led.h"

led_config_t g_led_config = {
    {
        {   0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      NO_LED,  15 },
        {  16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,      NO_LED,  31 },
        {  32,      33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      NO_LED,  45,      NO_LED,  47 },
        {  48,      NO_LED,  50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      NO_LED,  61,      62,      63 },
        {  64,      65,      66,      NO_LED,  NO_LED,  NO_LED,  70,      NO_LED,  NO_LED,  NO_LED,  74,      75,      76,      77,      78,      79 }
    },
    {
        {8,   6},  {22,  6},  {35,  6},  {49,  6},  {63,  6},  {77,  6},  {91,  6},  {105, 6},  {119, 6},  {133, 6},  {146, 6},  {160, 6},  {174, 6},  {195, 6},  {255,255},  {216, 6},
        {11,  19}, {29,  19}, {43,  19}, {56,  19}, {70,  19}, {84,  19}, {98,  19}, {112, 19}, {126, 19}, {140, 19}, {154, 19}, {168, 19}, {181, 19}, {199, 19}, {255,255}, {216, 19},
        {13,  31}, {32,  31}, {46,  31}, {60,  31}, {73,  31}, {87,  31}, {101, 31}, {115, 31}, {129, 31}, {143, 31}, {157, 31}, {171, 31}, {255,255}, {194, 31}, {255,255}, {216, 31},
        {17,  44}, {255,255}, {39,  44}, {53,  44}, {67,  44}, {81,  44}, {95,  44}, {108, 44}, {122, 44}, {136, 44}, {150, 44}, {164, 44}, {255,255}, {184, 44}, {202, 44}, {216, 44},
        {9,   56}, {27,  56}, {44,  56}, {255,255}, {255,255}, {255,255}, {95,  56}, {255,255}, {255,255}, {255,255}, {147, 56}, {161, 56}, {175, 56}, {189, 56}, {202, 56}, {216, 56}
    },
    {
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 0, 4,
        4, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4,
        4, 4, 4, 0, 0, 0, 4, 0, 0, 0, 4, 4, 4, 4, 4, 4
    }
};

#ifdef OPENRGB_ENABLE
const openrgb_config_t g_openrgb_config = {
    // Zones names
    {"Keyboard"},

    // Zones types
    {OPENRGB_ZONE_TYPE_MATRIX},

    // Zones sizes
    {80},

/* This servers as an example - the alt doesn't actually need this, only keyboards where their
//  g_led_config.matrix_co and layout doesn't actually represnet the true physical form of the keyboard
//  to get the correct values for the physical_to_hardware_location array
//  I used the second array on the layout macro at alt.h
*/
#    ifdef OPENRGB_USE_CUSTOM_MATRIX_MAP
    // LED matrix map
    {
        {   0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      NO_LED,  15 },
        {  16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,      NO_LED,  31 },
        {  32,      33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      NO_LED,  45,      NO_LED,  47 },
        {  48,      NO_LED,  50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      NO_LED,  61,      62,      63 },
        {  64,      65,      66,      NO_LED,  NO_LED,  NO_LED,  70,      NO_LED,  NO_LED,  NO_LED,  74,      75,      76,      77,      78,      79 }
    },
    // Key index to physical position map
    {
        {   0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,      11,      12,      13,      NO_LED,  15 },
        {  16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,      NO_LED,  31 },
        {  32,      33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      NO_LED,  45,      NO_LED,  47 },
        {  48,      NO_LED,  50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      NO_LED,  61,      62,      63 },
        {  64,      65,      66,      NO_LED,  NO_LED,  NO_LED,  70,      NO_LED,  NO_LED,  NO_LED,  74,      75,      76,      77,      78,      79 }
    },
#    endif
};
#endif

#endif
