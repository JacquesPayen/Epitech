//
// EPITECH PROJECT, 2018
// sdl.cpp
// File description:
//
//

#include <vector>
#include "sdl.hpp"

SDL::SDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << "Error initialization sdl" << std::endl;
	}
	if (TTF_Init() == -1)
		std::cout << "Error initialization ttf sdl" << std::endl;
	window = SDL_CreateWindow("Game"
				   , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				   1000, 1000, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

SDL::~SDL()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	SDL::clearW()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void	SDL::setCell(const int &x, const int &y, const int &c)
{
	SDL_Rect rect = {50*x+100, 50*y+100, 50, 50};

	if (c == 1)
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	else if (c == 2)
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	else if (c == 3)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	else if (c == 4)
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	else if (c == 5)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void	SDL::refreshW()
{
	SDL_RenderPresent(renderer);
	SDL_Delay(300);
}

void	SDL::setText(const int &x, const int &y, const std::string &text)
{
	TTF_Font	*Sans = TTF_OpenFont("Sans.ttf", 1000);
	SDL_Color	White = {255, 255, 255};
	SDL_Surface	*surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White);
	SDL_Texture	*Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_Rect	Message_rect;
	
	Message_rect.x = x;
	Message_rect.y = y;
	Message_rect.w = 100;
	Message_rect.h = 100;
	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
}


void	SDL::getKey(int *key)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
			case SDLK_LEFT:
				*key = 3;
				break;
			case SDLK_RIGHT:
				*key = 1;
				break;
			case SDLK_UP:
				*key = 2;
				break;
			case SDLK_DOWN:
				*key = 4;
				break;
			case SDLK_ESCAPE:
				*key = 84;
				break;
			case SDLK_SPACE:
				*key = 10;
				break;
			}
			break;
		case SDL_KEYUP:
			break;
		}
	}
}

extern "C"
{
	SDL        *createLibGraph()
	{
		return (new SDL());
	}
}
