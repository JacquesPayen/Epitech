/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "argument.hpp"

ARGUMENT::ARGUMENT()
{	
}

ARGUMENT::~ARGUMENT()
{
}

int	ARGUMENT::get_size()
{
	return instructions.get_size();
}

void	ARGUMENT::set_arguments()
{
	pthread_mutex_init(&locker, NULL);
	pthread_mutex_init(&locker_file, NULL);
}

void	ARGUMENT::set_instruction(std::vector<std::string> ins)
{
	instructions.set_instruction(ins);
}

std::string	ARGUMENT::get_instruction(int nb)
{
	return instructions.get_instruction(nb);
}

void	ARGUMENT::lock()
{
	pthread_mutex_lock(&locker);
}

void	ARGUMENT::unlock()
{
	pthread_mutex_unlock(&locker);
}

void	ARGUMENT::lockFile()
{
	pthread_mutex_lock(&locker_file);
}

void	ARGUMENT::unlockFile()
{
	pthread_mutex_unlock(&locker_file);
}

std::vector<std::string>	ARGUMENT::get_vector()
{
	return instructions.get_vect();
}
