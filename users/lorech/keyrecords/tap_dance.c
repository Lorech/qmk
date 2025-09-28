/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include <stdint.h>

#include "action.h"
#include "action_tapping.h"

#include "mods.h"
#include "process_records.h"
#include "tap_dance.h"

tap_dance_action_t tap_dance_actions[] = {
    [TD_NEXT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
};

/**
 * Returns the tapping term for each individual tap dance keycode.
 *
 * @param keycode The incoming keycode to perform the lookup for
 * @param record The incoming information about the keycode press
 * @return The tapping term for the keycode
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

/**
 * Handles a key press for a tap-hold keycode.
 *
 * TODO: Add support for *PER_KEY hold modifiers
 *
 * @param state The incoming information about the keycode press
 * @param user_data The outgoing information about the tap-hold status
 */
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifdef HOLD_ON_OTHER_KEY_PRESS
            || state->interrupted
#elif !defined(PERMISSIVE_HOLD)
            && !state->interrupted
#endif
        ) {
            mod_register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            mod_register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

/**
 * Handles a key release for a tap-hold keycode.
 *
 * @param state The incoming information about the keycode press
 * @param user_data The outgoing information about the tap-hold status
 */
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        mod_unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}
