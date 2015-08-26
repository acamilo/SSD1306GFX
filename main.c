#include "src/screen.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "main.h"

int quit=0;
SDL_Event e;

int main(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}
	
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 128*4, 64*4, SDL_WINDOW_SHOWN);
	if (win == 0){
		printf("SDL_CreateWindow Error: %s",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == 0){
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	printf("Hello World!\n");
	while(!quit){
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);
		for (int i=0; i< 64; i++)
			drawssd1306Pixel(ren,i,i);
		
		
		SDL_RenderPresent(ren);
		SDL_Delay(100);
		pollEvents();
	}
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