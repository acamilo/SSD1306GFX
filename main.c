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
	uint8_t *buf = gfx_getBuffer();
	//for (int i=0; i<128*2; i++) buf[i]=0x0;
	fonts_putstr("Variable Width Fonts");
	while(!checkQuit()){
		updateSDL();
		pollEvents();
	}
}
