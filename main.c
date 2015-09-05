#include "src/screen.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "src/sdl_funcs.h"
#include "main.h"
#include "src/gfx.h"

#include "fonts/fonts.h"



int main(){
	initSDL();
	printf("Hello World!\n");
	//testBufCopy();

	gfx_clear(gfx_getBuffer());
	fonts_putstr("Hello Chicago!");
	while(!checkQuit()){
		updateSDL();
		pollEvents();
	}
}
