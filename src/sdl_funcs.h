#ifndef _SDL_FUNCS_H_
#define _SDL_FUNCS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

void pollEvents();
int initSDL();
void updateSDL();
SDL_Renderer* sdlGetRender();
int checkQuit();

#endif