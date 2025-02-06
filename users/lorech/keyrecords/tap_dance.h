/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include "process_tap_dance.h"

#define TD_MTRK TD(TD_NEXT_PREV)

enum tap_dance_actions {
    TD_NEXT_PREV,
    TAP_DANCE_MAX,
};

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_MAX];
