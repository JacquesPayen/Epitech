/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef COMMANDE_HPP
#define COMMANDE_HPP

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "contacts.hpp"

class COMMANDE
{
public:
	COMMANDE();
	~COMMANDE();
	std::string			call_com(std::string, std::vector<std::string>);
	void				set_status(std::string);
	void				set_name(std::string);
	std::string			get_status();
	std::vector<std::string>	get_arg();
	std::string			get_name();
private:
	void		add_commande(std::string name, std::string (* function)(COMMANDE *obj));
	typedef	struct	command_s
	{
		std::string	name;
		std::string	(* function)(COMMANDE *obj);
	}		commande_t;
	std::vector<commande_t>		my_list;
	std::string			my_status;
	std::vector<std::string>	my_argument;
	std::string			my_name;
};	

std::string	my_register(COMMANDE *obj);
std::string	my_login(COMMANDE *obj);
std::string	my_logout(COMMANDE *obj);
std::string	my_add(COMMANDE *obj);
std::string	my_remove(COMMANDE *obj);
std::string	my_call(COMMANDE *obj);
std::string	my_get_status(COMMANDE *obj);
std::string	my_hang(COMMANDE *obj);

#endif /* COMMANDE_HPP */