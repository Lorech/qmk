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
