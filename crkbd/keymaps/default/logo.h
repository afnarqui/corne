#pragma once

#include "quantum.h"

extern const char logo[];         // <- Referencia al logo
extern const uint16_t logo_size;  // <- Tamaño en bytes del logo

void oled_render_logo(void);