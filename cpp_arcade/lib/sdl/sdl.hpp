//
// EPITECH PROJECT, 2018
// sdl.hpp
// File description:
// 
//

# ifndef SDL_HPP
# define SDL_HPP

#include "../../include/core.hpp"

#include "lib/SDL.h"
#include "lib/SDL_ttf.h"

class SDL : public libGraphic
{
public:
	SDL();
	~SDL();
	void	clearW();
	void	setCell(const int &x, const int &y, const int &c);
	void	refreshW();
	void	setText(const int &x, const int &y, const std::string &text);
	void    getKey(int *key);
private:
	SDL_Window	*window;
	SDL_Renderer	*renderer;
};

#endif /* SDL_HPP */
