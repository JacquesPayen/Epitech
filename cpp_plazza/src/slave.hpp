//
// EPITECH PROJECT, 2018
// slave.hpp
// File description:
// 
//


#ifndef SLAVE_HPP
#define SLAVE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>

class	SLAVE
{
public:
	SLAVE();
	~SLAVE();
	int	thread;
	int	size;
	int	fd;
	int	port;
	size_t	*n;
	std::string	command;
};

int	start_server(int);

#endif /* SLAVE_HPP */
