/**
 * Copyright 2015-2023 Jack Humbert, 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include "lorech.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Standard QWERTY layout.
    [_QWERTY] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         KC_ESC,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        OS_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_ENT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LCTL,KC_LGUI,KC_LALT,  LOWER,_______, KC_SPC,  UPPER,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT
    // `-----------------------------------------------------------------------------------------------'
    ),

    // COLEMAK with the DH mod.
    [_COLEMAK_DH] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_TAB,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSPC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         KC_ESC,   KC_A,   KC_R,   KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        OS_LSFT,   KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,KC_COMM, KC_DOT,KC_SLSH, KC_ENT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,KC_LCTL,KC_LGUI,KC_LALT,  LOWER,_______, KC_SPC,  UPPER,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT
    // `-----------------------------------------------------------------------------------------------'
    ),

    // The lower layer for additional keys.
    [_LOWER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
         KC_GRV,_______,_______,_______,_______,KC_LBRC,KC_RBRC,   KC_7,   KC_8,   KC_9, KC_DEL,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,   KC_0,   KC_1,   KC_2,   KC_3,KC_HOME,KC_BSLS,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,KC_MINS, KC_EQL,   KC_4,   KC_5,   KC_6, KC_END,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,_______,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY
    // `-----------------------------------------------------------------------------------------------'
    ),


    // The upper layer for additional keys.
    [_UPPER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
        KC_TILD,_______,_______,KC_ASTR,KC_AMPR,KC_LCBR,KC_RCBR,_______,_______,_______, KC_DEL,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,KC_HASH,  KC_AT,KC_EXLM,KC_LPRN,KC_RPRN,_______,_______,_______,KC_HOME,KC_PIPE,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,KC_CIRC,KC_PERC, KC_DLR,KC_UNDS,KC_PLUS,_______,_______,_______, KC_END,_______,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        _______,_______,_______,_______,_______,_______,_______,_______,KC_MNXT,KC_VOLD,KC_VOLU,KC_MPLY
    // `-----------------------------------------------------------------------------------------------'
    ),

    // Keyboard adjustment layer (lower + raise).
    [_ADJUST] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
        QK_BOOT,_______,_______,UG_TOGG,UG_NEXT,UG_HUEU,UG_HUED,UG_SATU,UG_SATD,UG_SPDU,UG_SPDD, QWERTY,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        DB_TOGG,_______,MU_NEXT,  AU_ON, AU_OFF,AG_NORM,AG_SWAP,_______,_______,_______,_______,CLMAKDH,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         EE_CLR,AU_PREV,AU_NEXT,  MU_ON, MU_OFF,  MI_ON, MI_OFF,_______,_______,_______,_______, PLOVER,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
         QK_RBT,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
    // `-----------------------------------------------------------------------------------------------'
    ),

    // Compatibility layer with Plover's default mapping for stenography using QWERTY.
    // For more information, see https://www.openstenoproject.org/
    [_PLOVER] = LAYOUT_planck_grid(
    // ,-----------------------------------------------------------------------------------------------.
           KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,   KC_1,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        XXXXXXX,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        XXXXXXX,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_K,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
    // |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
        EXT_PLV,XXXXXXX,XXXXXXX,   KC_C,   KC_V,XXXXXXX,XXXXXXX,   KC_N,   KC_M,XXXXXXX,XXXXXXX,XXXXXXX
    // `-----------------------------------------------------------------------------------------------'
    ),

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _UPPER, _ADJUST);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
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
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float *)note = 440.0f;
    return 0;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
