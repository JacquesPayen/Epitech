/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** Graphic
*/

#ifndef GRAPHIC_HPP_
#define GRAPHIC_HPP_

#include <string>

class libGraphic
{
	public:
		virtual ~libGraphic(){};
		virtual	void	refreshW() = 0;
		virtual	void	clearW() = 0;
		virtual	void	getKey(int *key) = 0;
		virtual	void	setCell(const int &x, const int &y, const int &cell) = 0;
		virtual	void	setText(const int &x, const int &y, const std::string &text) = 0;
};


#endif /* !GRAPHIC_HPP_ */
