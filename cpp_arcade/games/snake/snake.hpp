//
// EPITECH PROJECT, 2018
// snake.hpp
// File description:
// 
//

# ifndef SNAKE_HPP
# define SNAKE_HPP

#include "../../include/core.hpp"

#include <vector>

class   SNAKE : public GAME
{
public:
	SNAKE();
	virtual ~SNAKE();
	int	gameRun(libGraphic *aff);
	void	getMap(const char *);
	void	spawnSnake(void);
	void	setSnake(void);
	int	getKey(void);
	void	clearMap(void);
	int	moveSnake(void);
	void	spawnFood(void);
	void	drawMap(libGraphic *);
	void	setKey(int);
	int	snakeSize(void);
	void	changeSnake(std::vector<int>, int);
	int	endGame(void);
private:
	int	key;
	std::vector<int>	snake;
	std::vector<std::string>	map;
	int     size;
	int	score;
};

#endif /* SNAKE_HPP */
