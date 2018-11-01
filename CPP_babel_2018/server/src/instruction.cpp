/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/instruction.hpp"

INSTRUCTION::INSTRUCTION()
{
}

INSTRUCTION::~INSTRUCTION()
{
}

std::string	INSTRUCTION::traitement(std::string input, std::string ip)
{
	std::vector<std::string>	arg;
	std::string			instruction = my_decode(input);
	
	arg = get_part(instruction, ip);
	input.assign(my_manager.call_com(arg[0], arg));
	input.push_back('\n');
	return input;
}

int	INSTRUCTION::is_active()
{
	if (my_manager.get_status().compare("CLOSE") == 0)
		return 0;
	return 1;
}

std::vector<std::string>	INSTRUCTION::get_part(std::string input, std::string ip)
{
	std::stringstream ss(input);
	std::string item;
	std::vector<std::string> arg;
	
	while (std::getline(ss, item, ' ')) {
		if (item.empty() == 1)
			item = ip;
		arg.push_back(item);
	}
	return arg;
}

std::string	INSTRUCTION::my_decode(std::string input)
{
	while (input.back() == '\r' || input.back() == '\n' || input.back() == ' ')
		input.pop_back();
	return input;
}