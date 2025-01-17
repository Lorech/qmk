/**
 * Copyright 2012 Yun Wako, 2015 Jack Humbert, 2024-2025 Lauris Patriks Dedumets
 *
 * Licensed under the GNU General Public License, version 2 or later.
 * See <https://www.gnu.org/licenses/> for details.
 */

#pragma once

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Redefine the pin for split communication.
// TODO: Make this conditional if I get a new set of MCUs.
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN B5
