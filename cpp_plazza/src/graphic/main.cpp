//
// EPITECH PROJECT, 2018
// main.cppp
// File description:
// 
//

#include <ncurses.h>
#include "my.hpp"

int	calSize(int a, int b, int size)
{
	int	res = 0;
	int	i = 0;

	while (i < a) {
		i = i + b;
		res++;
	}
	if (size > res)
		res = size;
	return res;
}

std::string	getInstruction(COMMAND ins, int z, int nb, int *size)
{
	int	i = 0;
	std::string	res("");

	*size = 0;
	while (i != nb && z < ins.get_size()) {
		if (i == 0)
			res = ins.get_instruction(z);
		else
			res  = res + ";" + ins.get_instruction(z);
		*size = *size + 1;
		i++;
		z++;
	}
	return res;
}

std::vector<SLAVE>	gestionSlave(COMMAND ins, int nb, std::vector<SLAVE> list)
{
	srand(time(NULL));
	static int	port = rand()%9000+1000;
	pid_t	pid;
	int	z = 0;
	int	i = 0;
	std::vector<std::string>	tab;
	std::vector<SLAVE>	res(calSize(ins.get_size(), nb, list.size()));

	while (i != (list.size())) {
		res[i] = list[i];
		if ((res[i].command = getInstruction(ins, z, nb, &res[i].size)) == "")
			res[i].thread = 1;
		else
			res[i].thread = 0;
		i++;
		z = z + nb;
	}
	while (i != res.size()) {
		if ((res[i].command = getInstruction(ins, z, nb, &res[i].size)) == "")
			res[i].thread = 1;
		else {
			res[i].thread = 0;
		}
		res[i].fd = startServer(port, (nb/2));
		res[i].port = port;
		port++;
		i++;
		z = z + nb;
	}
	return res;
}

int	slave(int nb)
{
	int	pid;
	WINDOW	*haut;
	size_t	n;
	std::string	str;
	std::vector<std::string>	command;
	COMMAND	instruction;
	std::vector<SLAVE>	list;
	std::vector<std::string>	res;

	pid = fork();
	if (pid == 0) {
		while (1) {
			res = getScrap();
			drawStatus(haut, list, res);
		}
	}
	initscr();
	while (1) {
		str = getArg(haut, list, res);
		if (checkCmd(str) == 0) {
			command = commandSet(str);
			instruction.set_instruction(command);
			list = gestionSlave(instruction, nb*2, list);
			sendMessage(list, haut, res);
			getMessage(list, haut, res);
		}
	}
	return 0;
}

int	main(int ac, char **av)
{
	std::string	str;
	std::vector<std::string>	command;
	COMMAND	instruction;
	
	if (ac != 2) {
		std::cout << "Wrong arg nbr" << std::endl;
		return 84;
	}
	slave(atoi(av[1]));
	return 0;
}
