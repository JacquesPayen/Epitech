//
// EPITECH PROJECT, 2018
// command.hpp
// File description:
// 
//

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

class	COMMAND
{
public:
	COMMAND();
	~COMMAND();
	int	get_size();
	void	set_instruction(std::vector<std::string>);
	std::string	get_instruction(int);
	std::vector<std::string>	get_vect();
private:
	int				size;
	std::vector<std::string>	instruction;
};

#endif /* COMMAND_HPP */
