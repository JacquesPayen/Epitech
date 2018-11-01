//
// EPITECH PROJECT, 2018
// graphic.cpp
// File description:
// 
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "my.hpp"
#include <fstream>

std::vector<std::string>	getScrap()
{
	std::vector<std::string>	vect;
	std::ifstream in("log.txt");
	std::string	str;

	if (!in)
		return vect;
	while (std::getline(in, str))
	{
		if(str.size() > 0)
			vect.push_back(str);
	}
	in.close();
	return vect;
}

void	drawStatus(WINDOW *haut, std::vector<SLAVE> list, std::vector<std::string> res)
{
	char	str[100];
	int	i = 0;
	int	pos = 3;
	
	clear();
	haut= subwin(stdscr, LINES - 1, COLS, 1, 0);
	box(haut, ACS_VLINE, ACS_HLINE);
	mvwprintw(haut, 1, 1, "Informations sur les slaves :");
	while (i != list.size()) {
		sprintf(str, "%d", i);
		mvwprintw(haut, pos, 1, "Slave n ");
		mvwprintw(haut, pos, 8, str);
		if (list[i].thread == 0)
			mvwprintw(haut, pos+1, 1, "Status : Working");
		else
			mvwprintw(haut, pos+1, 1, "Status : Sleeping");
		sprintf(str, "Nb command : %d", list[i].size);
		mvwprintw(haut, pos+2, 1, str);
		i++;
		pos = pos + 4;
	}
	i = 0;
	while (i != res.size())
	{
		mvwprintw(haut, i + 1, (COLS/2) + 1, res[i].c_str());
		i++;
	}
	wrefresh(haut);
}

std::string	getArg(WINDOW *haut, std::vector<SLAVE> list, std::vector<std::string> res)
{
	char	str[100];
	std::string	s;
	char	*buff = new char[160];
	int	i = 0;
	int	pos = 3;
	
	clear();
	haut= subwin(stdscr, LINES -1, COLS, 1, 0);
	box(haut, ACS_VLINE, ACS_HLINE);
	mvwprintw(haut, 1, 1, "Informations sur les slaves :");
	while (i != list.size()) {
		sprintf(str, "%d", i);
		mvwprintw(haut, pos, 1, "Slave n ");
		mvwprintw(haut, pos, 8, str);
		mvwprintw(haut, pos+1, 1, "Status : Sleeping");
		sprintf(str, "Nb command : %d", 0);
		mvwprintw(haut, pos+2, 1, str);
		i++;
		pos = pos + 4;
	}
	i = 0;
	while (i != res.size())
	{
		mvwprintw(haut, i + 1, COLS/2, res[i].c_str());
		i++;
	}
	getstr(buff);
	wrefresh(haut);
	return std::string(buff);
}
