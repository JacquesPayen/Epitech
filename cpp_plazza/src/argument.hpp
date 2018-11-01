/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef ARGUMENT_HPP_
#define ARGUMENT_HPP_

#include "../include/my.h"

class	ARGUMENT
{
public:
	ARGUMENT();
	~ARGUMENT();
	void				set_arguments();
	void				set_instruction(std::vector<std::string>);
	std::string			get_instruction(int);
	std::vector<std::string>	get_vector();
	int				get_size();
	void				lock();
	void				unlock();
	void				lockFile();
	void				unlockFile();
private:
	COMMAND			instructions;
	pthread_mutex_t		locker;
	pthread_mutex_t		locker_file;
};

#endif /* !ARGUMENT_HPP_ */
