//
// EPITECH PROJECT, 2018
// command.cpp
// File description:
// 
//

#include "command.hpp"

COMMAND::COMMAND()
{	
}

COMMAND::~COMMAND()
{
}

int	COMMAND::get_size()
{
	return size;
}

void	COMMAND::set_instruction(std::vector<std::string> ins)
{
	size = ins.size();
	instruction = ins;
}

std::string	COMMAND::get_instruction(int nb)
{
	return instruction[nb];
}

std::vector<std::string>	COMMAND::get_vect()
{
	return instruction;
}
