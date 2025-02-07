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
#endif // !CONSOLE_ENABLE

#ifdef TAP_DANCE_ENABLE
    #include "tap_dance.h"
#endif // !TAP_DANCE_ENABLE

#ifdef AUDIO_ENABLE
float plover_enable[][2]  = PLOVER_ENABLE;
float plover_disable[][2] = PLOVER_DISABLE;
#endif // !AUDIO_ENABLE

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

    // Only process at user level if it was not handled at keymap level.
    // Doing so allows keymaps to override records as needed.
    if (!process_record_keymap(keycode, record)) {
        return false;
    }

#ifdef TAP_DANCE_ENABLE
    tap_dance_action_t *action;
#endif // !TAP_DANCE_ENABLE

    switch (keycode) {
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_enable);
#endif
                layer_off(_UPPER);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_disable);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
#ifdef TAP_DANCE_ENABLE
        case TH_ENAV:
        case TH_QCTL:
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
#endif // !TAP_DANCE_ENABLE
    }

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
