//
// EPITECH PROJECT, 2018
// snake.cpp
// File description:
// 
//

#include "snake.hpp"

SNAKE::SNAKE()
{
	std::vector<int>        new_snake(8);

	score = 0;
	snake = new_snake;
	key = 3;
	size = 12;
}

SNAKE::~SNAKE()
{
}

int	SNAKE::gameRun(libGraphic *lib)
{
	this->getMap("map");
	this->spawnSnake();
	this->setSnake();
	while (key != 84) {
		this->spawnFood();
		lib->getKey(&key);
		if (key == 10) {
			delete lib;
			return 10;
		}
		if (this->moveSnake() == -1) {
			delete lib;
			return 1;
		}
		lib->clearW();
		this->clearMap();
		this->setSnake();
		this->drawMap(lib);
		score = (this->snakeSize() -8)*5;
		lib->setText(0, 0, std::to_string(score));
		lib->refreshW();
	}
	delete lib;
	return -1;
}

int	SNAKE::snakeSize(void)
{
	return snake.size();
}

void	SNAKE::setKey(int k)
{
	key = k;
}

void	SNAKE::getMap(const char *str)
{
	std::vector<std::string>	nmap(size);
	std::string	line;
	int	i = 0;
	std::ifstream	myfile;

	myfile.open(str);
	if (myfile.is_open()) {
		while (getline(myfile,line)) {
			nmap[i] = line;
			i++;
		}
		myfile.close();
	}
	map = nmap;
}

void	SNAKE::spawnSnake(void)
{
	snake[0] = 7;
	snake[1] = size / 2;
	snake[2] = 8;
	snake[3] = size / 2;
	snake[4] = 9;
	snake[5] = size / 2;
	snake[6] = 10;
	snake[7] = size / 2;
}

void	SNAKE::setSnake(void)
{
	int	i = 2;

	map[snake[1]][snake[0]] = 'h';
	while (i != snake.size()) {
		map[snake[i + 1]][snake[i]] = 's';
		i = i + 2;
	}
}

int	SNAKE::getKey(void)
{
	return key;
}

void	SNAKE::spawnFood(void)
{
	int     i = 0;
	int     x = 0;
	int     y = 0;

	if (endGame() == 1)
		return ;
	while (map[0][i] != 'e')
		i++;
	while (map[y][x] != 'x')
	{
		x = rand()%(i - 1 + 1) + 1;
		y = rand()%(map.size() - 2 - 1 + 1) + 1;
		if (map[y][x] == ' ')
			map[y][x] = 'x';
	}
}

void	SNAKE::changeSnake(std::vector<int> new_snake, int size)
{
	std::vector<int> final(size);
	int     i = 2;
	int     a = 0;

	final[0] = new_snake[0];
	final[1] = new_snake[1];
	while (i != size) {
		final[i] = snake[a];
		i++;
		a++;
	}
	snake = final;
}

int	SNAKE::moveSnake(void)
{
	int	i = 0;
	std::vector<int>	new_snake(snake.size());

	if (key == 1) {
		if (map[snake[1]][snake[0] + 1] == 's' ||
		    map[snake[1]][snake[0] + 1] == '.' )
			return -1;
		else if (map[snake[1]][snake[0] + 1] != '-') {
			new_snake[0] = snake[0] + 1;
			new_snake[1] = snake[1];
		}
		else
			return 0;
	}

	else if (key == 2) {
		if (map[snake[1] - 1][snake[0]] == 's' ||
		    map[snake[1] - 1][snake[0]] == '.') 
			return -1;
		else if (map[snake[1] - 1][snake[0]] != '-') {
			new_snake[0] = snake[0];
			new_snake[1] = snake[1] - 1;
		}
		else
			return 0;
	}
	else if (key == 3) {
		if (map[snake[1]][snake[0] - 1] == 's' ||
		    map[snake[1]][snake[0] - 1] == '.' ) 
			return -1;
		else if (map[snake[1]][snake[0] - 1] != '-') {
			new_snake[0] = snake[0] - 1;
			new_snake[1] = snake[1];
		}
		else
			return 0;
	}
	else if (key == 4) {
		if (map[snake[1] + 1][snake[0]] == 's' ||
		    map[snake[1] + 1][snake[0]] == '.')
			return -1;
		else if (map[snake[1] + 1][snake[0]] != '-') {
			new_snake[0] = snake[0];
			new_snake[1] = snake[1] + 1;
		}
		else
			return 0;
	}
	if (map[new_snake[1]][new_snake[0]] == 'x')
		i = 2;
	this->changeSnake(new_snake, i + snake.size());
}

void	SNAKE::clearMap(void)
{
	int     a = 0;
	int     i = 0;

	while (i != map.size()) {
		a = 0;
		while (map[i][a] != 'e') {
			if (map[i][a] == 's' || map[i][a] == 'h')
				map[i][a] = ' ';
			a++;
		}
		i++;
	}
}

void	SNAKE::drawMap(libGraphic *lib)
{
	int	a = 0;
	int	i = 0;

	while (i != size) {
		a = 0;
		while (map[i][a] != 'e') {
			if (map[i][a] == '.')
				lib->setCell(a, i, 3);
			else if (map[i][a] == 's')
				lib->setCell(a, i, 4);
			else if (map[i][a] == 'h')
				lib->setCell(a, i, 5);
			else if (map[i][a] == '-')
				lib->setCell(a, i, 1);
			else if (map[i][a] == 'x')
				lib->setCell(a, i, 2);
			a++;
		}
		i++;
	}
}

int	SNAKE::endGame(void)
{
	int     a = 0;
	int     i = 0;
	
	while (i != map.size()) {
		a = 0;
		while (map[i][a] != 'e') {
			if (map[i][a] == 'x')
			{
				return 1;
			}
			a++;
		}
		i++;
	}
	return 0;
}

extern "C"
{
	SNAKE        *createLibGame()
	{
		return (new SNAKE());
	}
}
