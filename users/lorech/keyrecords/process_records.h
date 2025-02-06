/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include "action.h"
#include "keycodes.h"

enum userspace_keycodes {
    PLOVER = QK_USER,
    EXT_PLV
};

bool pre_process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define LOWER   TL_LOWR
#define UPPER   TL_UPPR

#define QWERTY  PDF(_QWERTY)
#define COLEMAK PDF(_COLEMAK)
#define CLMAKDH PDF(_COLEMAK_DH)
#define DVORAK  PDF(_DVORAK)
#define PLOVER  PDF(_PLOVER)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_HYPR OSM(MOD_HYPR)
#define OS_MEH  OSM(MOD_MEH)
