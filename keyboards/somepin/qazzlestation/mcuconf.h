// Copyright 2022 somepin (@somepin)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
 
#include_next "mcuconf.h"

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_PWM_USE_PWM0
#define RP_PWM_USE_PWM0 TRUE

#undef RP_PWM_USE_PWM6
#define RP_PWM_USE_PWM6 TRUE
