/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "keycode_config.h"
#include "quantum.h"

#include "mods.h"

/**
 * Executes a keycode tap with respect to the global keycode configuration.
 *
 * @param keycode The raw keycode to tap
 */
void mod_tap_code16(uint16_t keycode) {
    tap_code16(keycode_config(keycode));
}

/**
 * Registers a keycode with respect to the global keycode configuration.
 *
 * @param keycode The raw keycode to tap
 */
void mod_register_code16(uint16_t keycode) {
    register_code16(keycode_config(keycode));
}

/**
 * Unregisters a keycode with respect to the global keycode configuration.
 *
 * @param keycode The raw keycode to tap
 */
void mod_unregister_code16(uint16_t keycode) {
    unregister_code16(keycode_config(keycode));
}
