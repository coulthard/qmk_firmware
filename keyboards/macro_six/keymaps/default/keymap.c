/* Copyright 2019 iain-c
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM reset_combo[] = { KC_5, KC_6, COMBO_END };
const uint16_t PROGMEM test_combo[] = { KC_5, KC_4, COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
    COMBO_ACTION(reset_combo),
    COMBO(test_combo, KC_9)
     };


void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        reset_keyboard();
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_4,    KC_5,    KC_6,  //MO(_FN),
        KC_1,    KC_2,    KC_3
    ),
    [_FN] = LAYOUT(
        KC_F4,   RESET,   _______,
        KC_F1,   KC_F2,   KC_F3
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int pin = -1;

    if (record->event.key.row == 0)
    {
        switch (record->event.key.col) {
            case 0: pin = B5; break;
            case 1: pin = B6; break;
            case 2: pin = B7; break;
        }
    }
    else if (record->event.key.row == 1)
    {
        switch (record->event.key.col) {
            case 0: pin = B2; break;
            case 1: pin = B3; break;
            case 2: pin = B4; break;
        }
    }
    if (pin != -1)
    {
        if (record->event.pressed)
            writePinHigh(pin);
        else
            writePinLow(pin);
    }

    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
