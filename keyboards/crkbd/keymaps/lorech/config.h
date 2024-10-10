#pragma once

// Redefine the pin for split communication.
// TODO: Make this conditional if I get a new set of MCUs.
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN B5
