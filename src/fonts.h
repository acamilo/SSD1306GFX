#ifndef FONTS_H
#define FONTS_H
#include "stdint.h"
#include <stdio.h>
int fonts_putchar(uint8_t c);
void fonts_putstr(char * str);
void fonts_sety(uint16_t sety);
void fonts_setx(uint16_t setx);
void fonts_setfont(uint8_t *fu,uint8_t *fl,uint16_t *foff);

#endif