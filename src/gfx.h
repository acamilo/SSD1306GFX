#ifndef _GFX_H_
#define _GFX_H_
#include "stdint.h"

/* Do Graphicsy things to the buffer
 * This should have more ui drawing code but now its sparse
 * 
 * gfx_getBuffer		Returns pointer to global buffer
 * gfx_clear			Takes pointer to buffer and clears it.
 * 
 */
void drawss

uint8_t * gfx_getBuffer();

void gfx_clear(uint8_t * buff);
#endif