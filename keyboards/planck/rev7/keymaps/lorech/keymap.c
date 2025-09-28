/**
 * Copyright 2015-2023 Jack Humbert, 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "lorech.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         KC_ESC,  QHR_A,  QHR_S,  QHR_D,  QHR_F,   KC_G,   KC_H,  QHR_J,  QHR_K,  QHR_L,QHR_SCL,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        OS_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_ENT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LCTL,KC_LGUI,KC_LALT,  LOWER,_______, KC_SPC,  UPPER,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT
    // `-----------------------------------------------------------------------------------------------'
    ),

    [_COLEMAK_DH] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         KC_ESC,  CHR_A,  CHR_R,  CHR_S,  CHR_T,   KC_G,   KC_M,  CHR_N,  CHR_E,  CHR_I,  CHR_O,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        OS_LSFT,   KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,KC_COMM, KC_DOT,KC_SLSH, KC_ENT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LCTL,KC_LGUI,KC_LALT,  LOWER,_______, KC_SPC,  UPPER,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT
    // `-----------------------------------------------------------------------------------------------'
    ),

    [_LOWER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_GRV, KC_F12,  KC_F9,  KC_F8,  KC_F7,XXXXXXX,XXXXXXX,   KC_7,   KC_8,   KC_9, KC_INS, KC_DEL,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______, KC_F10,  KC_F3,  KC_F2,  KC_F1,KC_MINS,KC_PLUS,   KC_1,   KC_2,   KC_3,   KC_0,KC_BSLS,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______, KC_F11,  KC_F6,  KC_F5,  KC_F4,KC_UNDS, KC_EQL,   KC_4,   KC_5,   KC_6,XXXXXXX,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,_______,_______,TD_MTRK,KC_VOLD,KC_VOLU,KC_MPLY
    // `-----------------------------------------------------------------------------------------------'
    ),

    [_UPPER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
        KC_TILD,KC_LBRC,XXXXXXX,KC_ASTR,KC_AMPR,KC_RBRC,XXXXXXX,XXXXXXX,XXXXXXX,KC_PSCR, KC_INS, KC_DEL,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LPRN,KC_HASH,  KC_AT,KC_EXLM,KC_RPRN,KC_CAPS,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_PIPE,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LCBR,KC_CIRC,KC_PERC, KC_DLR,KC_RCBR,KC_SCRL,KC_HOME,KC_PGDN,KC_PGUP, KC_END,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,_______,_______,TD_MTRK,KC_VOLD,KC_VOLU,KC_MPLY
    // `-----------------------------------------------------------------------------------------------'
    ),

    [_ADJUST] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
        QK_BOOT,AU_TOGG,MU_TOGG,MI_TOGG,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, QWERTY,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        DB_TOGG,AU_PREV,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,CLMAKDH,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         EE_CLR,AU_NEXT,MU_NEXT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, PLOVER,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         QK_RBT,XXXXXXX,XXXXXXX,XXXXXXX,_______,XXXXXXX,XXXXXXX,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
    // `-----------------------------------------------------------------------------------------------'
    ),

    // Compatibility layer with Plover's default mapping for stenography using QWERTY.
    // For more information, see https://www.openstenoproject.org/
    [_PLOVER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
           KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        XXXXXXX,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        XXXXXXX,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_K,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        EXT_PLV,XXXXXXX,XXXXXXX,   KC_C,   KC_V,XXXXXXX,XXXXXXX,   KC_N,   KC_M,XXXXXXX,XXXXXXX,XXXXXXX
    // `-----------------------------------------------------------------------------------------------'
    ),

};
/* clang-format on */
