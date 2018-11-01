/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	place_ressource(int ***map, int y, int x)
{
	int	h = rand()%(y-1);
	int	w = rand()%(x-1);
	int	i = 0;
	int	r = rand()%(6);

	map[h][w][r] = map[h][w][r] + 1;
}

int	*add_element(int *line)
{
	int	nb = 0;
	int	z = 0;

	while (z != 7) {
		nb = rand()%3;
		line[z] = nb;
		z++;
	}
	return line;
}

int	***add_ressources(int ***map, int height, int width)
{
	int	nb;
	int	last = 0;;
	int	x = 0;
	int	y = 0;

	srand(time(NULL));
	while (y != height) {
		x = 0;
		while (x != width) {
			map[y][x] = add_element(map[y][x]);
			x++;
		}
		y++;
	}
	return map;
}

void	draw_map(int ***map, int height, int width)
{
	int	x = 0;
	int	y = 0;

	while (y != height) {
		x = 0;
		while (x != width)
		{
			printf("%i", map[y][x][0]);
			x++;
		}
		printf("\n");
		y++;
	}
	fflush(stdout);
}

int	***generation_map(int height, int width)
{
	int	***map = malloc(sizeof(int**) * height);
	int	i = 0;
	int	a = 0;
	int	z = 0;

	while (i != height) {
		a = 0;
		map[i] = malloc(sizeof(int*) * width);
		while (a != width) {
			z = 0;
			map[i][a] = malloc(sizeof(int) * 7);
			while (z != 7) {
				map[i][a][z] = 0;
				z++;
			}
			a++;
		}
		i++;
	}
	map = add_ressources(map, height, width);
	return map;
}
