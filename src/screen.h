#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#define screenScale 10

void testPixel(SDL_Renderer* ren);
void drawssd1306Pixel(SDL_Renderer* ren,int x, int y);
void writeByte(uint8_t byte, SDL_Renderer* ren);