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
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,          KC_Q,     KC_W,     KC_F,     KC_P,      KC_G,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_R,     KC_S,     KC_T,      KC_D,               KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
    KC_LSPO,         KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                                                   KC_LALT,   LOWER,    KC_SPC,   RAISE,    KC_ENT
  ),
  
  [_LOWER] = LAYOUT_reviung41(
    _______,         KC_0,     KC_1,     KC_2,     KC_3,      KC_PERC,            _______,  _______,  _______,  _______,  _______,  KC_DEL,
    _______,         KC_4,     KC_4,     KC_5,     KC_6,      KC_PIPE,            _______,  _______,  _______,  _______,  _______,  KC_BSLS,
    _______,         KC_7,     KC_7,     KC_8,     KC_9,      KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  KC_ENT,
                                                   _______,   _______,  _______,  _______,  _______
  ),
  
  [_RAISE] = LAYOUT_reviung41(
    _______,         KC_F1,    KC_F2,    KC_F3,    KC_F4,     _______,            KC_6,     KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_LEAD,
    _______,         KC_F5,    KC_F6,    KC_F7,    KC_F8,     _______,            KC_F1,    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F6,
    _______,         KC_F9,    KC_F10,   KC_F11,   KC_F12,    _______,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                                   _______,   _______,  KC_MINS,  _______,  KC_RGUI
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,          RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,          RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,          XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                   _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_LEFT) {
      // firefox tab left
      tap_code16(C(KC_PGUP));
    }
    SEQ_ONE_KEY(KC_DOWN) {
        //firefox tab right
        tap_code16(C(KC_PGDN));
    }
    // Note: This is not an array, you don't need to put any commas
    // or semicolons between sequences.
    //SEQ_TWO_KEYS(KC_N, KC_T) {
      // When I press KC_LEAD and then N followed by T, this sends CTRL + T
      //SEND_STRING(SS_LCTRL("t"));
    //}
  }
}
