/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#include <string.h>

#include "lorech.h"

#include "musical_notes.h"
#include "user_song_list.h"

#ifdef AUDIO_ENABLE
float the_lick_song[][2] = SONG(THE_LICK);
#endif // !AUDIO_ENABLE

bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
#ifdef AUDIO_ENABLE
    // Play the lick if that's what was typed, leveraging the trie provided by
    // autocorrect as an easy, built-in way for tracking typed words.
    if (strcmp("lick", typo) || strcmp("licc", typo)) {
        PLAY_SONG(the_lick_song);
        return false;
    }
#endif

    return true;
}
