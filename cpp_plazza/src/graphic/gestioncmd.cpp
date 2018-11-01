//
// EPITECH PROJECT, 2018
// gestioncmd.cpp
// File description:
// 
//

#include "my.hpp"

int	checkCmd(std::string str)
{
	std::size_t	found = 0;

	if ((found = str.find(std::string("EMAIL_ADDRESS"))) != -1)
	    return 0;
	if ((found = str.find(std::string("PHONE_NUMBER"))) != -1)
	    return 0;
	if ((found = str.find(std::string("IP_ADDRESS"))) != -1)
	    return 0;
	return 1;
}

void	sendMessage(std::vector<SLAVE> list, WINDOW *haut, std::vector<std::string> res)
{
	int	i = 0;
	
	while (list[i].thread == 0 && i != list.size()) {
		write(list[i].fd, list[i].command.c_str(),
		      strlen(list[i].command.c_str()));
		i++;
	}
}

void	getMessage(std::vector<SLAVE> list, WINDOW *haut, std::vector<std::string> res)
{
	int	i = 0;
	char	pos[1];

	pos[0] = 'l';
	while (list[i].thread == 0 && i != list.size()) {
		while (pos[0] != '\n') {
			read(list[i].fd, pos, 1);
		}
		i++;
		pos[0] = 'K';
	}
}
