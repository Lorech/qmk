/**
 * Copyright 2015-2023 Jack Humbert, 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#ifdef AUDIO_ENABLE
    // #define STARTUP_SONG SONG(NO_SOUND)
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    #define DEFAULT_LAYER_SONGS {SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND)}
#endif

/**
 * Enable basic MIDI features:
 * - MIDI notes can be sent when in Music mode is on
 */
#define MIDI_BASIC

/**
 * Enable advanced MIDI features:
 * - MIDI notes can be added to the keymap
 *   - Octave shift and transpose
 *   - Virtual sustain, portamento, and modulation wheel
 *   - etc.
 */
// #define MIDI_ADVANCED
