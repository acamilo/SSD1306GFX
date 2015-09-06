#include "fonts.h"
#include "gfx.h"
#include "sdl_funcs.h"
#include "../fonts/chicago.h"


// Where the 'line' currently is on the screen
int x=0;
int y=0;


int fonts_putchar(uint8_t c){
	if (c > 127) return -1; // Table is only 128b
	// is it a space?
	if (c==' '){
		x +=2;
		return c;
	}
	
	// Look up the char
	uint16_t ref = font_off_len_table[c];

	if (ref==0) return -2; // We don't have that char
	
	uint16_t offset = ref>>4;
	uint8_t len = 0x000f & ref;
	
	printf("char [off:%d  len:%d]\n", offset,len);
	
	uint8_t * buf = gfx_getBuffer();
	
	// offset y. shift across display
	// Theres probubly a better way t do this
	


	printf("cursor [x:%d  y:%d]\n", x,y);
	
	for (uint8_t i=0; i<len; i++){
		uint8_t ly = y&0x07;
		uint8_t s  = y>>3;
		printf("s: %d\n",s);
		uint8_t lower = (font_lower_pix[i+offset]<<ly ) ;
		uint8_t upper = ( font_upper_pix[i+offset]<<ly) | (font_lower_pix[i+offset]>>(8-ly) ) ;
		uint8_t overflow = (font_upper_pix[i+offset]>>(8-ly) );
		
		
		buf[i+(SSD1306_LCDWIDTH*(0+s))+x] |= lower;
		buf[i+(SSD1306_LCDWIDTH*(1+s))+x] |= upper;
		if((i+(SSD1306_LCDWIDTH*(2+s))+x)<SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT)
			buf[i+(SSD1306_LCDWIDTH*(2+s))+x] |= overflow;
	}
	
	x += len+1;
	
	
	return c;
}

void fonts_putstr(char * str){
	for (int i = 0; i < strlen(str); i++){
		fonts_putchar(str[i]);
	}
	
}

void fonts_sety(uint16_t sety){
	y=sety;
}

void fonts_setx(uint16_t setx){
	x=setx;
}