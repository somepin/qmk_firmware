// Copyright 2022 somepin
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#include "quantum.h"
#include "qp.h"

extern painter_device_t lcd;
typedef struct kb_runtime_config {
    unsigned          lcd_power : 1;
} kb_runtime_config;

#define XXX KC_NO

#define LAYOUT_split_space( \
  K60, K61,                                          \
  K00, K01, K02, K03, K04, K05, K06, K40, K41,  K42, \
  K10,  K11, K12, K13, K14, K15, K16, K50, K51, K52, \
  K20,    K21, K22, K23, K24, K25, K26, K43,    K53, \
  K30, K31, K32,      K33, K34,       K35, K36, K44 \
) { \
{ K00, K01, K02, K03, K04, K05, K06 }, \
{ K10, K11, K12, K13, K14, K15, K16 }, \
{ K20, K21, K22, K23, K24, K25, K26 }, \
{ K30, K31, K32, K33, K34, K35, K36 }, \
{ K40, K41, K42, K43, K44, XXX, XXX }, \
{ K50, K51, K52, K53, XXX, XXX, XXX }, \
{ K60, K61, XXX, XXX, XXX, XXX, XXX }, \
}
