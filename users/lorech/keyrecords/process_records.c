/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "lorech.h"
#include "process_records.h"
#ifdef CONSOLE_ENABLE
    #include "print.h"
#endif

/**
 * Pre-process a keycode at the keymap level.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 * @return Whether the event was handled and should be sent to the host
 */
__attribute__((weak)) bool pre_process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/**
 * A hook into keycode processing, which enables keymap-level processing.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 * @return Whether the event was handled and should be sent to the host
 */
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    return pre_process_record_keymap(keycode, record);
}

/**
 * Process a keycode as part of a specific keymap.
 *
 * Useful for processing which should not be global across all keyboards or
 * keymaps. For those, see `process_record_user`.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 * @return Whether the event was handled and should be sent to the host
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/**
 * Global processor of keycode events shared across all keymaps.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 * @return Whether the event was handled and should be sent to the host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// Enable HID printing if console is enabled, formatted for QMK Heatmap.
// See: https://precondition.github.io/qmk-heatmap
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    // clang-format off
    uprintf(
        "0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,%u\n",
        keycode,
        is_combo ? 254 : record->event.key.row,
        is_combo ? 254 : record->event.key.col,
        get_highest_layer(layer_state),
        record->event.pressed,
        get_mods(),
        get_oneshot_mods(),
        record->tap.count
    );
    // clang-format-on
#endif

    return true;
}

/**
 * Post-process a keycode at the keymap level.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 */
__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}

/**
 * A hook into keycode processing, which enables keymap-level post-processing.
 *
 * @param keycode The keycode from the keymap matrix
 * @param record The full keyrecord structure
 */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}
