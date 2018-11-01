//
// EPITECH PROJECT, 2018
// core.hpp
// File description:
// 
//

#ifndef CORE_HPP_
	#define CORE_HPP_

#include "./graphic.hpp"
#include "./game.hpp"

int	supportLib(char *);
int	gameStart(int);

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

class Core
{
	public:
		virtual	~Core(){};
	void	loadLib(std::string str);
	void	loadGame(std::string str);
		libGraphic	*_graph;
		GAME	*_game;
};

#endif /* !Core_HPP_ */
