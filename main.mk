TARGET := main

SOURCES := \
    main.c \
    src/screen.c \
	src/sdl_funcs.c\
	src/gfx.c \
	src/fonts.c

CXXFLAGS := -g -O0 -Wall -pipe -framework SDL2 -framework GLUT -framework OpenGL 

TGT_LDFLAGS := -framework SDL2 -framework GLUT -framework OpenGL 