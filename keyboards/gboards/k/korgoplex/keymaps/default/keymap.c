/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

/* Combomap
 *
 * ,-----------------------------.       ,--------------------------------.
 * |      |    ESC    |     |     |      |     |    ESC    |    BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |      |   BSPC   ENT    |     |      |    LES   COLN  GRT    |        | 
 * |-----+-----+-----+--RMB+-LMB--+	 |--------------------------------|
 * |      |   MINS    |     |     |      |    QUO   UNDR   |     |        |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .-------------------------.           .-----------------.   
 *  |        |       |        |           |        |    |   |
 *  '-------------------------'           '-----------------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |     Q|  W  |  F  |  P  |  G  |      |  J  |  L  |  U  |  Y  |    :   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |CTRL/A|  R  |  S  |  T  |  D  |      |  H  |  N  |  E  |  I  | CTRL/O | 
 * |------+-----+-----+-----+-----+	 |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  K  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+-----+-----'	 `--------------------------------'
 *      .-------------------------.      .-----------------.   
 *      |ESC/META|ENT/ALT|SPC(NUM)|      |SPC(SYM)|BSPC|TAB|
 *      '-------------------------'      '-----------------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,              KC_W, KC_F, KC_P, KC_G,  	KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, 
    MT(MOD_LCTL, KC_A),KC_R, KC_S, KC_T, KC_D,  	KC_H, KC_N, KC_E,    KC_I,   MT(MOD_LCTL, KC_O),
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,  	KC_K, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

    MT(MOD_LGUI, KC_ESC), MT(MOD_LALT, KC_ENT), LT(NUMB, KC_SPC),	// Left
    LT(SYMB, KC_SPC), KC_LSFT, MT(MOD_RSFT, KC_TAB)			// Right
    ),
/* Keymap 1: Symbols layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  {  |  }  |     |      |  `  |  ~  |     |     |    \   |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |  #   |  $  |  (  |  )  | LMB |      |  +  |  -  |  /  |  *  |    '   | 
 * |-----+-----+-----+-----+------+	 |--------------------------------|
 * |  %   |  ^  |  [  |  ]  | RMB |      |  &  |  =  |  ,  |  .  |   -    |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  		.-----------------.      .------------------.   https://puu.sh/GlZKC/9b36f3eb21.png
 *  		| MMB |  ;  |  =  |      |  =  |  ;  |  DEL |
 *  		'-----------------'      '------------------' 
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,   KC_GRV,  KC_TILD, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,   KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_MINS,
                      CMB_TOG, KC_SCLN, KC_EQL,   KC_EQL,  KC_SCLN, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 * ,-----------------------------.      ,-------------------------------.
 * |  0  |  1  |  2  |  3  |     |      | F1  | F2  | F3  | F4  |   0   |
 * |-----+-----+-----+-----+-----|      |-------------------------------|
 * |     |  4  |  5  |  6  |     |      | F5  | F6  | F7  | F8  | VOLUP | 
 * |-----+-----+-----+-----+-----+	|-------------------------------|
 * |CTRL |  7  |  8  |  9  |     |      | F9  | F10 | F11 | F12 | VOLDN |
 * `-----+-----+-----+------+----'      `-------------------------------'
 *  		.-----------------.      .-----------------.   
 *  		|     |    |	  |	 |     | F11 | F12 |
 *  		'-----------------'      '-----------------' 
 */
[NUMB] = LAYOUT_gergoplex(
    KC_0,     KC_1,  KC_2,  KC_3, KC_TRNS,		KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_0,
    KC_TRNS,  KC_4,  KC_5,  KC_6, KC_TRNS,   		KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLU,
    MOD_LCTL, KC_7,  KC_8,  KC_9, KC_TRNS,  		KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_VOLD,
    		 KC_TRNS,KC_TRNS,KC_TRNS,  	        KC_TRNS, KC_F11, KC_F12
    )
};
