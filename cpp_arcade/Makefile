##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

CXX =	g++

CXXFLAGS +=	-fPIC

LDFLAGS =	-ldl

GL_SRC =	./lib/GL/src/libGL.cpp	\
		./lib/GL/src/libGLShaders.cpp

SDL_SRC =	lib/sdl/sdl.cpp

NC_SRC =	lib/ncurses/myncurses.cpp

SNAKE_SRC =	games/snake/snake.cpp

PACMAN_SRC =	games/pacman/pacman.cpp

CORE_SRC =	src/main.cpp	\
		src/core.cpp

GL_NAME =	./lib/lib_arcade_opengl.so

SDL_NAME =	./lib/lib_arcade_sdl2.so

NC_NAME =	./lib/lib_arcade_ncurses.so

SNAKE_NAME =	./games/snake.so

PACMAN_NAME =    ./games/pacman.so

CORE_NAME = arcade

GL_OBJS =	$(GL_SRC:.cpp=.o)

SDL_OBJS =	$(SDL_SRC:.cpp=.o)

NC_OBJS =	$(NC_SRC:.cpp=.o)

SNAKE_OBJS =	$(SNAKE_SRC:.cpp=.o)

PACMAN_OBJS =	$(PACMAN_SRC:.cpp=.o)

CORE_OBJS =	$(CORE_SRC:.cpp=.o)

all: graphicals games core

graphicals:	$(GL_NAME) $(SDL_NAME) $(NC_NAME)

games:	$(SNAKE_NAME) $(PACMAN_NAME)

core:	$(CORE_NAME)

$(GL_NAME):	$(GL_OBJS)
		$(CXX) -shared -o $(GL_NAME) $(GL_OBJS) ./lib/GL/lib/libglfw3.a ./lib/GL/lib/libGLEW.a -lGL

$(SDL_NAME):	$(SDL_OBJS)
		$(CXX) -shared -o $(SDL_NAME) $(SDL_OBJS) -lSDL2 -lSDL2_ttf

$(NC_NAME):	$(NC_OBJS)
		$(CXX) -shared -o $(NC_NAME) $(NC_OBJS) -lncurses

$(SNAKE_NAME):	$(SNAKE_OBJS)
		$(CXX) -shared -o $(SNAKE_NAME) $(SNAKE_OBJS)

$(PACMAN_NAME):	$(PACMAN_OBJS)
		$(CXX) -shared -o $(PACMAN_NAME) $(PACMAN_OBJS)

$(CORE_NAME):	$(CORE_OBJS)
		$(CXX) -o $(CORE_NAME) $(CORE_OBJS) $(LDFLAGS)

clean:
		rm -f $(GL_OBJS) $(SDL_OBJS) $(NC_OBJS) $(SNAKE_OBJS) $(PACMAN_OBJS) $(CORE_OBJS)

fclean:		clean
		rm -f $(GL_NAME) $(SDL_NAME) $(NC_NAME) $(SNAKE_NAME) $(PACMAN_NAME) $(CORE_NAME)

re:	fclean graphicals games core
