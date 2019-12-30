/*
Copyright 2019 iain-c

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x1C1C
#define DEVICE_VER 0x0001
#define MANUFACTURER iain-c
#define PRODUCT macro_six
#define DESCRIPTION A backlit 6 key macro pad

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
//#define MATRIX_ROW_PINS { D0, D5 }
//#define MATRIX_COL_PINS { F1, F0, B0 }
#define DIRECT_PINS { \
    { D5, D6, D7 }, \
    { D2, D3, D4 } \
}

// LED pins B2, B3, B4, B5, B6, B7
#define UNUSED_PINS B0, B1, C6, C7, D0, D1, E6, F0, F1, F4, F5, F6, F7
/* COL2ROW, ROW2COL*/
//#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN B7
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_LEVELS 3

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


#define BOOTMAGIC_KEY_SALT           KC_1
#define BOOTMAGIC_KEY_BOOTLOADER     KC_4

#define COMBO_COUNT                  2
#define COMBO_TERM                   200

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#ifndef LINK_TIME_OPTIMIZATION_ENABLE
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION
#endif


/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
