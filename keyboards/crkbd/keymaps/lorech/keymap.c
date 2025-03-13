/**
 * Copyright 2019 @foostan, 2020 Drashna Jaelre, 2024-2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "lorech.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------.                  ,-----------------------------------------------.
        KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                      KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSPC,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
        KC_ESC,   KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                      KC_M,   KC_N,   KC_E,   KC_I,   KC_O,KC_QUOT,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       OS_LSFT,   KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,                      KC_K,   KC_H,KC_COMM, KC_DOT,KC_SLSH,KC_LCTL,
    //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                       KC_LGUI,  LOWER, KC_SPC,    KC_ENT,  UPPER,KC_RALT
                                    //`-----------------------'  `-----------------------'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------.                  ,-----------------------------------------------.
        KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       KC_LSFT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,XXXXXXX,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       XXXXXXX,XXXXXXX,XXXXXXX,KC_LCBR,KC_LBRC,KC_LPRN,                   KC_RPRN,KC_RBRC,KC_RCBR,XXXXXXX,XXXXXXX,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                       KC_LGUI,_______, KC_SPC,    KC_ENT,_______,KC_RALT
                                    //`-----------------------'  `-----------------------'
    ),

    [_UPPER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------.                  ,-----------------------------------------------.
       KC_TILD,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                   KC_CIRC,KC_AMPR,KC_ASTR,KC_PLUS, KC_EQL,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       KC_LSFT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PLUS,                   KC_MINS,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_PIPE,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_EQL,                   KC_UNDS,XXXXXXX,XXXXXXX,XXXXXXX,KC_BSLS,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                       KC_LGUI,_______, KC_SPC,    KC_ENT,_______,KC_RALT
                                    //`-----------------------'  `-----------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------.                  ,-----------------------------------------------.
       QK_BOOT,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,KC_MUTE,KC_VOLD,KC_VOLU,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       KC_CAPS,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------|                  |-------+-------+-------+-------+-------+-------|
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    //|-------+-------+-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------+-------+-------|
                                       KC_LGUI,_______, KC_SPC,    KC_ENT,_______,KC_RALT
                                    //`-----------------------'  `-----------------------'
  )

};
// clang-format on
