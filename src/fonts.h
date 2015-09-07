#ifndef FONTS_H
#define FONTS_H
#include "stdint.h"
#include <stdio.h>

/* Variable Width font rendering
 * 
 * 
 * fonts_putchar		using corrent font and current x,y write a char to framebuffer. advance x by char len.
 * fonts_putstr			takes a string and calls putchar with each charecter
 * fonts_sety			set the cursor y		
 * fonts_setx           set the cursor x
 * fonts_setfont		set the current font. takes 3 arrays. upper pix data, lower pix data, offset/len table
 * 
 * 
 */
int fonts_putchar(uint8_t c);
void fonts_putstr(char * str);
void fonts_sety(uint16_t sety);
void fonts_setx(uint16_t setx);
void fonts_setfont(uint8_t *fu,uint8_t *fl,uint16_t *foff);

#endif