//
// EPITECH PROJECT, 2018
// game.hpp
// File description:
// 
//

# ifndef GAME_HPP
# define GAME_HPP

#include "graphic.hpp"

class GAME
{
public:
	virtual ~GAME(){};
	virtual int	gameRun(libGraphic *aff) = 0;
};

#endif /* GAME_HPP */
