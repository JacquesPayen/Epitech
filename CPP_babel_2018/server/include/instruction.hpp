#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "./commande.hpp"

class INSTRUCTION
{
public:
	INSTRUCTION();
	~INSTRUCTION();
	std::string	traitement(std::string input, std::string ip);
	int		is_active();
private:

	std::vector<std::string>	get_part(std::string, std::string);
	std::string			my_decode(std::string);
	COMMANDE			my_manager;
};

#endif /* INSTRUCTION_HPP */