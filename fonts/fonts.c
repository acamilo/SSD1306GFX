#include "fonts.h"
#include "../src/gfx.h"
#include "../src/sdl_funcs.h"
#include "chicago.h"


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
	
	uint8_t offset = ref>>4;
	uint8_t len = 0x000f & ref;
	
	printf("char [off:%d  len:%d]\n", offset,len);
	
	uint8_t * buf = gfx_getBuffer();
	
	for (uint8_t i=0; i<len; i++){
		buf[i+x] = 				  font_lower_pix[i+offset];
		buf[i+SSD1306_LCDWIDTH+x] = font_upper_pix[i+offset];
	}
	x += len+1;
	
	
	return c;
}

void fonts_putstr(char * str){
	for (int i = 0; i < strlen(str); i++){
		fonts_putchar(str[i]);
	}
	
}