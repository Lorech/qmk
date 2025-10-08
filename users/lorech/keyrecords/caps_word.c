/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "quantum.h"

/**
 * Pre-processes a key press made with Caps Word enabled to determine
 * the handling procedure for both the key and the Caps Word state.
 *
 * @param keycode The keycode of the tapped key
 * @return If caps word should remain enabled after this key press
 */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Continue Caps Word, applying Shift.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        // Continue Caps Word.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        // Deactivate Caps Word.
        default:
            return false;
    }
}
