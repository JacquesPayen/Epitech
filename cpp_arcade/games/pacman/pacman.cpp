//
// EPITECH PROJECT, 2018
// tetri.cpp
// File description:
// tetris
//

#include "./pacman.hpp"

Pacman::Pacman()
{
	FILE	*myfile;
	myfile = fopen("./map.txt", "r");
	char	ch;
	int	y = 0;
	int	x = 0;
	
	while (EOF != (ch = getc(myfile))) {
		if (ch == '\n') {
			y++;
			x = 0;
		}
		else {
			this->map[y][x] = ch - 48;
				x++;
		}
	}
	fclose(myfile);
	this->posPlayer[0] = 13;
	this->posPlayer[1] = 17;
	this->score = 0;
	this->life = 3;
	this->vulnerable = true;
}

void	Pacman::printMap(libGraphic *aff)
{
	int	x = 0;
	int	y = 0;

	aff->clearW();
	while (y < 31) {
		x = 0;
		while (x < 28) {
			if (this->map[y][x] == 1)
				aff->setCell(x, y, 9);
			else if (this->map[y][x] == 4)
				aff->setCell(x, y, 5);
			else if (this->map[y][x] != 3)
				aff->setCell(x, y, 4);
			x++;
		}
		y++;
	}
	for (int i = 0 ; i < 4 ; i++)
		aff->setCell(gho[i][0], gho[i][1], 3);
	aff->setCell(this->posPlayer[0], this->posPlayer[1], 2);
	aff->setText(35, 32, "Score : " + std::to_string(this->score));
	aff->setText(8, 32, "Life : ");
	if (vulnerable == false)
		aff->setCell(25, 32, 5);
	for (int i = 0 ; i < this->life ; i++)
		aff->setCell(8 + i * 2, 32, 2);
}

void	Pacman::movePlayer(const int &x, const int &y)
{
	if (x == - 1 && y == 14)
		this->posPlayer[0] = 27;
	if (x == 28 && y == 14)
		this->posPlayer[0] = 0;
	else if (x < 0 || x > 27 || y < 0 || y > 30)
		return;
	else if (this->map[y][x] == 3) {
		this->posPlayer[0] = x;
		this->posPlayer[1] = y;
	}
	else if (this->map[y][x] == 1 || map[y][x] == 4) {
		this->posPlayer[0] = x;
		this->posPlayer[1] = y;
		if (map[y][x] == 4)
			vulnerable = false;
		this->map[y][x] = 3;
		this->score += 10;
	}
}

void	Pacman::play(const int &dir)
{
	this->dir = dir;
	if (this->dir == 1)
		this->movePlayer(posPlayer[0] + 1, posPlayer[1]);
	else if (this->dir == 2)
		this->movePlayer(posPlayer[0], posPlayer[1] - 1);
	else if (this->dir == 3)
		this->movePlayer(posPlayer[0] - 1, posPlayer[1]);
	else if (this->dir == 4)
		this->movePlayer(posPlayer[0], posPlayer[1] + 1);
}

int	Pacman::isAlive()
{
	if (vulnerable)
		for (int i = 0 ; i < 4 ; i++) {
			if (posPlayer[0] == gho[i][0]
			    && gho[i][1] == posPlayer[1]) {
				life -= 1;
				posPlayer[0] = 13;
				posPlayer[1] = 17;
			}
		}
	if (life == 0)
		return (0);
	if (vulnerable == false)
		for (int i = 0 ; i < 4 ; i++) {
			if (posPlayer[0] == gho[i][0]
			    && gho[i][1] == posPlayer[1]) {
				score += 100;
				gho[i][0] = 15;
				gho[i][1] = 15;
			}
		}
	return (1);
}

void	Pacman::openMap()
{
	map[12][13] = 3;
	map[12][14] = 3;
}

int	Pacman::moveLateral(int dir, int gh)
{
	int	x = gho[gh][0] + dir;
	int	y = gho[gh][1];
	
	if (map[y][x] != 0) {
		for (int i = 0 ; i < 4 ; i ++) {
			if (i != gh && gho[i][1] == y
			    && x == gho[i][0])
				return (0);
		}
		gho[gh][0] += dir;
		return (1);
	}
	return (0);
}

int    Pacman::moveVertical(int dir, int gh)
{
	int	x = gho[gh][0];
	int	y = gho[gh][1] + dir;
	
	if (map[y][x] != 0) {
		for (int i = 0 ; i < 4 ; i ++) {
			if (i != gh && gho[i][1] == y
			    && x == gho[i][0])
				return (0);
		}
		gho[gh][1] += dir;
		return (1);
	}
	return (0);
}

void	Pacman::moveGhost()
{
	int	move;
	
	for (int i = 0 ; i < 4 ; i++) {
		if (move && gho[i][0] > posPlayer[0] && moveLateral(-1, i))
			move = 0;
		else if (move && gho[i][0] < posPlayer[0] && moveLateral(1, i))
			move = 0;
		else if (move && gho[i][1] > posPlayer[1] && moveVertical(-1, i))
			move = 0;
		else if (move && gho[i][1] < posPlayer[1] && moveVertical(1, i))
			move = 0;
		move = 1;
	}
}

void	Pacman::initGhost()
{
	gho[0][0] = 12;
	gho[0][1] = 13;
	gho[1][0] = 12;
	gho[1][1] = 15;
	gho[2][0] = 15;
	gho[2][1] = 13;
	gho[3][0] = 15;
	gho[3][1] = 15;
}

int	Pacman::gameRun(libGraphic *aff)
{
	int	key = 0;
	int	i = 0;
	int	a = 0;

	this->initGhost();
	while (this->isAlive() && key != 84) {
		aff->getKey(&key);
		this->play(key);
		this->moveGhost();
		this->printMap(aff);
		aff->refreshW();
		i++;
		if (this->vulnerable == false)
			a++;
		if (a == 30) {
			this->vulnerable = true;
			a = 0;
		}
		if (i == 30)
			this->openMap();
	}
	return (0);
}

extern "C"
{
	Pacman        *createLibGame()
	{
		return (new Pacman());
	}
}