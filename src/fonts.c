#include "fonts.h"
#include "gfx.h"
#include "sdl_funcs.h"


// Where the 'line' currently is on the screen
int x=0;
int y=0;


// Pointers to the data structures for the current font
uint8_t  * fontUpper;
uint8_t  * fontLower;
uint16_t * fontOffset;

void fonts_setfont(uint8_t *fu,uint8_t *fl,uint16_t *foff){
	fontUpper  = fu;
	fontLower  = fl;
	fontOffset = foff;
}


int fonts_putchar(uint8_t c){
	if (c > 127) return -1; // Table is only 128b
	// is it a space?
	if (c==' '){
		// just advance cursor by 2 px
		x +=2;
		return c;
	}
	
	// Look up the char
	uint16_t ref = fontOffset[c];

	if (ref==0) return -2; // We don't have that char
	
	// Extract offset, length
	uint16_t offset = ref>>4;
	uint8_t len = 0x000f & ref;
	
	printf("char [off:%d  len:%d]\n", offset,len);
	
	// Get a pointer to our display buffer
	uint8_t * buf = gfx_getBuffer();
	

	


	printf("cursor [x:%d  y:%d]\n", x,y);
	
	// Draw the char offset by clobal x and y co-ords
	// use offset to lookup char. copy len cols into buffer while applying x and y offsets.
	for (uint8_t i=0; i<len; i++){
		uint8_t ly = y&0x07; //  use this to move text by small amounts (across 3 rows)
		uint8_t s  = y>>3;  // adding lcdwidth to buffer pointer causes us to wrap to the next line.
							// Effectivley shifting text down by 8. divide y by 8 to get this
		printf("s: %d\n",s);
		
		// current small y offset col
		uint8_t lower = (fontLower[i+offset]<<ly ) ; // row 1 col
		uint8_t upper = ( fontUpper[i+offset]<<ly) | (fontLower[i+offset]>>(8-ly) ) ; // row 2 col
		uint8_t overflow = (fontUpper[i+offset]>>(8-ly) ); // row 3 col
		
		// write to buff and apply coarse y and x
		buf[i+(SSD1306_LCDWIDTH*(0+s))+x] |= lower;
		buf[i+(SSD1306_LCDWIDTH*(1+s))+x] |= upper;
		if((i+(SSD1306_LCDWIDTH*(2+s))+x)<SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT)
			buf[i+(SSD1306_LCDWIDTH*(2+s))+x] |= overflow;
	}
	
	x += len+1; // advance cursor by 1px after each charecter
	
	
	return c;
}


void fonts_putstr(char * str){
	// run putchar on each char of the string writing them to the display
	for (int i = 0; i < strlen(str); i++){
		fonts_putchar(str[i]);
	}
	
}

// setter for local y cursor global
void fonts_sety(uint16_t sety){
	y=sety;
}

// setter for local x cursor global
void fonts_setx(uint16_t setx){
	x=setx;
}