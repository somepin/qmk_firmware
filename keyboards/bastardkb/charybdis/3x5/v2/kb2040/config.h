/*
 * Copyright 2022 somepin
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

#pragma once

/* Key matrix configuration. */
#define MATRIX_ROW_PINS \
  { GP26, GP5, GP4, GP9 }
#define MATRIX_COL_PINS \
  { GP28, GP10, GP6, GP7, GP8 }

/* Handedness & split settings. */
#define SPLIT_HAND_PIN GP3
#define SPLIT_HAND_PIN_LOW_IS_LEFT  // High -> right, Low -> left.
#define USB_VBUS_PIN GP1

/* serial.c configuration (for split keyboard). */
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_TX_PIN GP29
#define SERIAL_USART_SPEED 230400

/* RGB settings. */
#define RGB_DI_PIN GP0

/* SPI & PMW3389 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP20
#define PMW33XX_CS_PIN GP2
#undef ROTATIONAL_TRANSFORM_ANGLE
#define POINTING_DEVICE_INVERT_Y
#define PMW33XX_LIFTOFF_DISTANCE 0x01

/* I2C EEPROM settings. */
#define I2C_DRIVER I2CD1
#define EEPROM_I2C_CAT24C512
#define I2C1_SCL_PIN GP13
#define I2C1_SDA_PIN GP12
#define MY_I2C_ADDRESS (0x50 << 1)

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
