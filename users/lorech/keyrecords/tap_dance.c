/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "quantum.h"

#include "tap_dance.h"

tap_dance_action_t tap_dance_actions[] = {
    [TD_NEXT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
    [TH_ESC_LGUI]  = ACTION_TAP_DANCE_TAP_HOLD(KC_ESC, KC_LGUI),
    [TH_QUOT_LCTL] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, KC_LCTL),
};

/**
 * Handles a key press for a tap-hold keycode.
 *
 * @param state The incoming information about the keycode press
 * @param user_data The outgoing information about the tap-hold status
 */
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif // !PERMISSIVE_HOLD
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
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
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}
