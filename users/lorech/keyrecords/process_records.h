/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include <stdint.h>

#include "action.h"
#include "keycodes.h"

enum userspace_keycodes {
    PLOVER = QK_USER,
    EXT_PLV,
};

bool pre_process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);

#ifdef TAP_DANCE_ENABLE
    #define TD_MTRK TD(TD_NEXT_PREV)
    #define TH_ENAV TD(TH_ESC_LGUI)
    #define TH_QCTL TD(TH_QUOT_LCTL)
#endif // !TAP_DANCE_ENABLE

#define LOWER   TL_LOWR
#define UPPER   TL_UPPR

#define QWERTY  PDF(_QWERTY)
#define CLMAKDH PDF(_COLEMAK_DH)
#define PLOVER  PDF(_PLOVER)

// QWERTY home row mods
#define QHR_A   LGUI_T(KC_A)
#define QHR_S   LALT_T(KC_S)
#define QHR_D   LCTL_T(KC_D)
#define QHR_F   LSFT_T(KC_F)
#define QHR_J   RSFT_T(KC_J)
#define QHR_K   RCTL_T(KC_K)
#define QHR_L   LALT_T(KC_L)
#define QHR_SCL RGUI_T(KC_SCLN)

// COLEMAK-DH home row mods
#define CHR_A LGUI_T(KC_A)
#define CHR_R LALT_T(KC_R)
#define CHR_S LCTL_T(KC_S)
#define CHR_T LSFT_T(KC_T)
#define CHR_N RSFT_T(KC_N)
#define CHR_E RCTL_T(KC_E)
#define CHR_I LALT_T(KC_I)
#define CHR_O RGUI_T(KC_O)
