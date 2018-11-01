/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/commande.hpp"
#include <unistd.h>
#include <string.h>

COMMANDE::COMMANDE()
{
	add_commande("Register", &my_register);
	add_commande("Login", &my_login);
	add_commande("Logout", &my_logout);
	add_commande("AddFriend", &my_add);
	add_commande("RemoveFriend", &my_remove);
	add_commande("StartCall", &my_call);
	add_commande("Status", &my_get_status);
	add_commande("EndCall", &my_hang);
	add_commande("END", &my_hang);
	set_status("LOGIN") ;
}

COMMANDE::~COMMANDE()
{
}

void	COMMANDE::add_commande(std::string name, std::string (* function)(COMMANDE *obj))
{
	commande_t	elem;

	elem.name = name;
	elem.function = function;
	if (elem.name == "END")
		elem.name.clear();
	my_list.push_back(elem);
}

std::string	COMMANDE::call_com(std::string com, std::vector<std::string> arg)
{
	my_argument = arg;
	int	i = 0;

	while (my_list[i].name.empty() != 1 && my_list[i].name.compare(com) != 0)
		i += 1;
	if (my_list[i].name.empty() != 1)
		return my_list[i].function(this);
	return "Commande error";
}

void	COMMANDE::set_status(std::string value)
{
	my_status = value;
}

void	COMMANDE::set_name(std::string value)
{
	my_name = value;
}

std::string	COMMANDE::get_status()
{
	return my_status;
}

std::vector<std::string>	COMMANDE::get_arg()
{
	return my_argument;
}

std::string	COMMANDE::get_name()
{
	return my_name;
}


std::string	my_register(COMMANDE *client)
{
	CONTACTS	my_directory;
	std::vector<std::string>	my_arg = client->get_arg();

	if (client->get_status() != "LOGIN" || my_directory.checkinfo(my_arg[1], my_arg[1]) == 1)
		return "Register Off";
	my_directory.adduser(my_arg[1], my_arg[2], my_arg[3], "CLOSE");
	return "Register On";
}

std::string	my_login(COMMANDE *client)
{
	CONTACTS	my_directory;
	std::vector<std::string>	my_arg = client->get_arg();

	if (client->get_status() != "LOGIN")
		return "Login off";
	if (my_directory.checkinfo(my_arg[1], my_arg[1]) == 0 ||
		my_directory.checkinfo(my_arg[1], my_arg[2]) == 0 ||
		my_directory.checkinfo(my_arg[1], "CLOSE") == 0)
		return "Login off";
	client->set_name(my_arg[1]);
	my_directory.replace_ip(my_arg[1], my_arg[3]);
	my_directory.replace_status(client->get_name(), "OPEN");
	client->set_status("OPEN");
	return "Login on";
}

std::string	my_logout(COMMANDE *client)
{
	CONTACTS	my_directory;

	if (client->get_status() != "LOGIN")
		my_directory.replace_status(client->get_name(), "CLOSE");
	client->set_status("CLOSE");
	return "End of communication";
}

std::string	my_add(COMMANDE *client)
{
	CONTACTS	my_directory;

	if (client->get_status() == "CLOSE" || client->get_status() == "LOGIN")
		return "AddFriend off";
	my_directory.add_contacts(client->get_name(), client->get_arg()[1]);
	return "AddFriend on";
}

std::string	my_remove(COMMANDE *client)
{
	CONTACTS	my_directory;

	if (client->get_status() == "CLOSE" || client->get_status() == "LOGIN")
		return "Revmove off";
	my_directory.remove_contacts(client->get_name(), client->get_arg()[1]);
	return "Remove on";
}

std::string	my_call(COMMANDE *client)
{
	std::string	output = "StartCall ";
	CONTACTS	my_directory;

	if (client->get_status() != "OPEN")
		return "StartCall off";
	output += my_directory.get_ip(client->get_arg()[1]);
	my_directory.replace_status(client->get_arg()[1], "BUSY");
	my_directory.replace_status(client->get_name(), "BUSY");
	client->set_status("BUSY");
	return output;
}

std::string	my_get_status(COMMANDE *client)
{
	std::string	sta = "Status ";
	CONTACTS	my_directory;

	if (client->get_status() == "CLOSE" || client->get_status() == "LOGIN")
		return "Status error";
	sta += my_directory.get_status(client->get_arg()[1]);
	return sta;
}

std::string	my_hang(COMMANDE *client)
{
	CONTACTS	my_directory;

	if (client->get_status() != "IN_CALL")
		return "EndCall off";
	my_directory.replace_status(client->get_name(), "OPEN");
	client->set_status("OPEN");
	return "EndCall on";
}