#include "screen.h"

void testPixel(SDL_Renderer* ren){
	
	SDL_SetRenderDrawColor(ren, (Uint8)255, (Uint8)255, (Uint8)255, 255);
	for(int i=0; i<1; i++)
		for(int j=0; j<1; j++)
		drawssd1306Pixel(ren,i,j);
}

void drawssd1306Pixel(SDL_Renderer* ren,int x, int y){
	if (y<16) SDL_SetRenderDrawColor(ren, (Uint8)255, (Uint8)255, (Uint8)0, 255);
	else SDL_SetRenderDrawColor(ren, (Uint8)100, (Uint8)100, (Uint8)255, 255);
	for(int i=0; i<screenScale; i++)
		for(int j=0; j<screenScale; j++)
    		SDL_RenderDrawPoint(ren, (x*screenScale)+i, (y*screenScale)+j);
}