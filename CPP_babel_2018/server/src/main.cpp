/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/server.hpp"

int	main(int ac, char **av)
{
	SERVER	server;

	if(ac != 2) {
		return server.my_help();
	}
	server.initialisation(atoi(av[1]));
	return server.run();
}