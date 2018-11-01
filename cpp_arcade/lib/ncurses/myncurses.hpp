//
// EPITECH PROJECT, 2018
// myncurses.hpp
// File description:
// ncurses
//

#include "../../include/core.hpp"

#include <ncurses.h>


class   libNcurses : public libGraphic
{
public:
	libNcurses();
	~libNcurses();
	void    refreshW();
	void    clearW();
	void    closeW();
	void    setCell(const int &x, const int &y, const int &color);
	void    setText(const int &x, const int &y, const std::string &text);
	void	getKey(int *key);
private:
	WINDOW  *win;
};
