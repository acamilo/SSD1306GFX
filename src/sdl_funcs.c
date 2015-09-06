#include "sdl_funcs.h"
#include "screen.h"
#include "gfx.h"


SDL_Renderer *ren;
SDL_Window *win;
int quit=0;
SDL_Event e;

int initSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}
	
	win = SDL_CreateWindow("SSD1306 128x64!", 100, 100, 128*screenScale, 64*screenScale, SDL_WINDOW_SHOWN);
	if (win == 0){
		printf("SDL_CreateWindow Error: %s",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == 0){
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s",SDL_GetError());
		SDL_Quit();
		return 1;
	}

	
	
	return 0;
}


void updateSDL(){
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	buffdump(gfx_getBuffer());
	SDL_RenderPresent(ren);
	SDL_Delay(100);
}

void pollEvents(){
	while (SDL_PollEvent(&e)){
		//If user closes the window
		if (e.type == SDL_QUIT){
			quit = 1;
		}
		//If user presses any key
		if (e.type == SDL_KEYDOWN){
			quit = 1;
		}
		//If user clicks the mouse
		if (e.type == SDL_MOUSEBUTTONDOWN){
			quit = 1;
		}
	}
}

int checkQuit(){
	return quit;
}

SDL_Renderer* sdlGetRender(){
	return ren;
}
