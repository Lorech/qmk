/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#include "audio/audio_config.h"
#endif // !AUDIO_ENABLE
#include "layers.h"
#include "keyrecords/process_records.h"
#ifdef TAP_DANCE_ENABLE
#include "keyrecords/tap_dance.h"
#endif // !TAP_DANCE_ENABLE
