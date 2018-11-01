/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <stdlib.h>
#include <boost/asio.hpp>
#include <iostream>
#include "./connection.hpp"

class SERVER
{
public:
	SERVER();
	~SERVER();
	int	run();
	int	my_help();
	void	initialisation(int);
private:
	int	my_port;
};

#endif /* SERVER_HPP */