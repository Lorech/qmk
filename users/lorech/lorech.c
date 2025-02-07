/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#ifdef TRI_LAYER_ENABLE
    #include "layers.h"
    #include "tri_layer.h"
#endif // !TRI_LAYER_ENABLE
#ifdef OS_DETECTION_ENABLE
    #include "keycode_config.h"
    #include "os_detection.h"
#endif // !OS_DETECTION_ENABLE

void keyboard_pre_init_user() {
#ifdef TRI_LAYER_ENABLE
    set_tri_layer_layers(_LOWER, _UPPER, _ADJUST);
#endif // !TRI_LAYER_ENABLE
}

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_IOS:
        case OS_MACOS:
            keymap_config.swap_lalt_lgui = true;
            break;
        default:
            keymap_config.swap_lalt_lgui = false;
    }

    return true;
}
#endif // !OS_DETECTION_ENABLE
