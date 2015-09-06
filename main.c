#include "src/screen.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "src/sdl_funcs.h"
#include "main.h"
#include "src/gfx.h"

#include "src/fonts.h"



int main(){
	int h=0;
	initSDL();
	printf("Hello World!\n");

	gfx_clear(gfx_getBuffer());
	
	fonts_sety(2);
	fonts_setx(25);
	fonts_putstr("Variable Width:?!");
	
	fonts_sety(16);
	fonts_setx(10);
	fonts_putstr("Hello World");
	
	fonts_sety(16+12);
	fonts_setx(80);
	fonts_putstr("ssd1306");
	
	fonts_sety(16+12+12);
	fonts_setx(30);
	fonts_putstr("display");
	
	fonts_sety(16+12+12+12);
	fonts_setx(40);
	fonts_putstr("wheeeeee");

	while(!checkQuit()){
		updateSDL();
		pollEvents();
	}
}
