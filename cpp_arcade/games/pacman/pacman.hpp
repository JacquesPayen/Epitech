//
// EPITECH PROJECT, 2018
// tetris.hpp
// File description:
// tetris
//

#ifndef	PACMAN_HPP_
#define PACMAN_HPP_

#include "../../include/game.hpp"
#include "../../include/graphic.hpp"

class Pacman : public	GAME
{
public:
	Pacman();
	virtual ~Pacman();
	int	gameRun(libGraphic *aff);
	void	printMap(libGraphic*);
	void	play(const int &dir);
	int	isAlive();
	void	movePlayer(const int &x, const int &y);
	void	initGhost();
	void	moveGhost();
	void	openMap();
	int	moveLateral(int dir, int gh);
	int	moveVertical(int dir, int gh);
	virtual	int	gameRun();
	int	map[31][28];
	int	score;
	int	life;
	int	dir;
	bool	vulnerable;
	int	posPlayer[2];
	int	gho[4][3];
};

#endif
