#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#define screenScale 1

void testPixel(SDL_Renderer* ren);
void drawssd1306Pixel(SDL_Renderer* ren,int x, int y);
void writeByte(uint8_t byte, SDL_Renderer* ren);
void buffdump(uint8_t * buffer);
void testBufCopy();

#endif