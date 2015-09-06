#include "screen.h"
#include "sdl_funcs.h"
int row = 0;
int page = 0;


void writeByte(uint8_t byte, SDL_Renderer* ren){
	for(int i=0; i<8; i++)
		
		if ((byte>>i)&0x01) drawssd1306Pixel(ren,row,i+(page*8));
	row++;
	if(row>127){
		row = 0;
		page++;
		if (page>63)
			page=0;
	}
}

void drawssd1306Pixel(SDL_Renderer* ren,int x, int y){
	if (y<16) SDL_SetRenderDrawColor(ren, (Uint8)255, (Uint8)255, (Uint8)0, 255);
	else SDL_SetRenderDrawColor(ren, (Uint8)100, (Uint8)100, (Uint8)255, 255);
	for(int i=0; i<screenScale; i++)
		for(int j=0; j<screenScale; j++)
    		SDL_RenderDrawPoint(ren, (x*screenScale)+i, (y*screenScale)+j);
}

void buffdump(uint8_t * buffer){
	for(int i=0; i<(SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH); i++)
		writeByte(buffer[i],sdlGetRender());
	
}