#ifndef _SDL_FUNCS_H_
#define _SDL_FUNCS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

/* Deal with SDL stuff. setting up windows, handling events, etc..
 * 
 * pollEvents		handle SDL events for our display window
 * initSDL			Init sdl, make window and renderer
 * updateSDL		Dump display buffer to windoe
 * sdlGetRender		return pointer to Renderer
 * checkQuit		return value of global quit var. so we can quit in main loop
 *                    without having to export a global
 */

void pollEvents();
int initSDL();
void updateSDL();
SDL_Renderer* sdlGetRender();
int checkQuit();

#endif