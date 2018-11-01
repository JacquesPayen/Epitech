//
// EPITECH PROJECT, 2018
// core.cpp
// File description:
// 
//

#include "../include/core.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

int	supportLib(char *str)
{
	if (strcmp(str, "./lib_arcade_ncurses.so") == 0)
		return 1;
	if (strcmp(str, "./lib_arcade_sdl2.so") == 0)
		return 2;
	if (strcmp(str, "./lib_arcade_opengl.so") == 0)
		return 3;
	std::cout << str << " is not a supported lib" << std::endl;
	return 0;
}

void	Core::loadLib(std::string str)
{
	void	*anything;
	libGraphic	*(*create_lib)();

	anything = dlopen(str.c_str(), RTLD_LOCAL | RTLD_LAZY);
	if (!anything)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(84);
	}
	create_lib = reinterpret_cast<libGraphic* (*)()>(dlsym(anything, "createLibGraph"));
	_graph = create_lib();
}

void	Core::loadGame(std::string str)
{
	void	*anything;
	GAME	*(*create_game)();
	
	anything = dlopen(str.c_str(), RTLD_LOCAL | RTLD_LAZY);
	if (!anything)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}
	create_game = reinterpret_cast<GAME* (*)()>(dlsym(anything, "createLibGame"));
	_game = create_game();
}

const char	*selectLib(int lib)
{
	if (lib == 1)
		return "lib/lib_arcade_ncurses.so";
	if (lib == 2)
		return "lib/lib_arcade_sdl2.so";
	if (lib == 3)
	       return "lib/lib_arcade_opengl.so";
	return "lib/lib_arcade_ncurses.so";
}

const char	*selectGame(int game)
{
	if (game == 1)
		return "games/snake.so";
	if (game == 2)
		return "games/pacman.so";
	return "games/snake.so";
}

int	gameStart(int i)
{
	int	end = 1;

	if (i == 3)
		return 0;
	while (end != -1)
	{
		Core	core;
		std::string	slib(selectLib(i));
		std::string     str(selectGame(end));
		core.loadLib(slib);
		core.loadGame(str);
		end = core._game->gameRun(core._graph);
		if (end == 10)
			end = 2;
	}
	return 0;
}
