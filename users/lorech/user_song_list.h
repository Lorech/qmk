/**
 * Copyright 2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#include "musical_notes.h"

#define AUTOCORRECT_ON_SOUND  E__NOTE(_C5), E__NOTE(_A5)
#define AUTOCORRECT_OFF_SOUND E__NOTE(_A5), E__NOTE(_C5)

// Each note length is doubled to make it sound more recognizable without
// adjusting the tempo, which would interfere with every other song.
// The last note is an eight + whole tie, which is modified to be a
// quarter + whole + whole tie, as separating the notes makes a cut.
#define THE_LICK Q__NOTE(_D4), Q__NOTE(_E4), Q__NOTE(_F4), Q__NOTE(_G4), H__NOTE(_E4), Q__NOTE(_C4), MUSICAL_NOTE(_D4, 16 + 64 + 64),
