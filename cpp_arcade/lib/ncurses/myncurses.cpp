//
// EPITECH PROJECT, 2018
// myncurses.cpp
// File description:
// ncurses
//

#include "./myncurses.hpp"

libNcurses::libNcurses()
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_BLUE, COLOR_BLUE);
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	noecho();
	timeout(300);
	keypad(stdscr, TRUE);
	curs_set(0);
}

libNcurses::~libNcurses()
{
	clear();
	endwin();
}

void    libNcurses::refreshW()
{
	refresh();
}

void    libNcurses::clearW()
{
	clear();
}

void    libNcurses::closeW()
{
	clear();
	endwin();
}

void    libNcurses::setCell(const int &x, const int &y, const int &color)
{
	if (color == 9)
		mvprintw(y, x * 2, "<>");
	else {
		attron(COLOR_PAIR(color));
		mvprintw(y, x * 2, "  ");
		attroff(COLOR_PAIR(color));
	}
}

void	libNcurses::setText(const int &x, const int &y, const std::string &text)
{
	for (int a = 0 ; a < text.size() ; a++) {
		mvprintw(y, x + a, "%c", text.at(a));
	}
}

void	libNcurses::getKey(int *key)
{
	int keyP = 0;

	keyP = getch();
	if (keyP == 0)
		return;
	else if (keyP == KEY_UP)
		*key = 2;
	else if (keyP == KEY_LEFT)
		*key = 3;
	else if (keyP == KEY_RIGHT)
		*key = 1;
	else if (keyP == KEY_DOWN)
		*key = 4;
	else if (keyP == 27)
		*key = 84;
	else if (keyP == ' ')
		*key = 10;
}

extern "C"
{
	libNcurses        *createLibGraph()
	{
		return (new libNcurses());
	}
}
