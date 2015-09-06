#include "src/screen.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "src/sdl_funcs.h"
#include "main.h"
#include "src/gfx.h"

#include "fonts/fonts.h"



int main(){
	int h=0;
	initSDL();
	printf("Hello World!\n");
	//testBufCopy();

	gfx_clear(gfx_getBuffer());
	uint8_t *buf = gfx_getBuffer();
	
	fonts_sety(2);
	fonts_setx(25);
	fonts_putstr("Variable Width");
	
	fonts_sety(16);
	fonts_setx(10);
	fonts_putstr("Hello");
	
	fonts_sety(16+12);
	fonts_setx(20);
	fonts_putstr("ssd1306");
	
	fonts_sety(16+12+12);
	fonts_setx(30);
	fonts_putstr("display");
	
	fonts_sety(16+12+12+12);
	fonts_setx(40);
	fonts_putstr("wheeeeee");
	//fonts_sety(10);

	while(!checkQuit()){
		updateSDL();
		pollEvents();
	}
}
