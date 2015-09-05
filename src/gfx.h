#ifndef _GFX_H_
#define _GFX_H_
#include "stdint.h"

void renderChar(int x, int y, char c, uint8_t * buff);

uint8_t * gfx_getBuffer();

void gfx_clear(uint8_t * buff);
#endif