#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#define screenScale 2

/* crude emulation of a SSD screen.
 * Take buffer formatted for SSD and draw it to a SDL Renderer.
 * drawssd1306Pixel		sets pixel at X,Y in Renderer ren
 * writeByte			writes a line of 8 pixels using above func
 * buffdump				takes pointer to SSD displat buffer and dumps it to Renderer
 */
void drawssd1306Pixel(SDL_Renderer* ren,int x, int y);
void writeByte(uint8_t byte, SDL_Renderer* ren);
void buffdump(uint8_t * buffer);

#endif