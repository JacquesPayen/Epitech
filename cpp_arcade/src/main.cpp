//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// 
//

#include "../include/core.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	int	lib;
	
	if (ac != 2) {
		std::cout << "Program take 1 arg, the graphic lib" << std::endl; 
		return 84;
	}
	if ((lib = supportLib(av[1])) == 0)
		return 84;
	gameStart(lib);
	return 0;
}
