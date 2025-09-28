/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include <stdint.h>

#include "process_tap_dance.h"

#define TAPPING_TERM_PER_KEY

enum tap_dance_actions {
    TD_NEXT_PREV,
    TAP_DANCE_MAX,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
void tap_dance_tap_hold_start(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                        \
    {                                                                               \
        .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
        .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
    }

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_MAX];
