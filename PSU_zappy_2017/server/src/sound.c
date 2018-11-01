/*
** EPITECH PROJECT, 2018
** broadcast.c
** File description:
** broadcast
*/

#include "../include/my.h"
#include <math.h>

int     get_sound_tile(player_t *from, player_t *to, map_t *map)
{
	int     xdiff;
	int     ydiff;

	xdiff = from->x - to->x;
	ydiff = from->y - to->y;
	if (xdiff > (map->width / 2))
		xdiff -= map->width;
	else if (xdiff < (-map->width / 2))
		xdiff += map->width;
	if (ydiff > (map->height / 2))
		ydiff -= map->height;
	else if (ydiff < (-map->height / 2))
		ydiff += map->height;
	if (xdiff != 0)
		xdiff = xdiff / abs(xdiff);
	if (ydiff != 0)
		ydiff = ydiff / abs(ydiff);
	return (choose_dir(xdiff, ydiff, to->dir));
}

int	choose_dir(int xdiff, int ydiff, int dir)
{
	if (dir == 0)
		return (find_case(xdiff, ydiff, 0, -1));
	if (dir == 1)
		return (find_case(xdiff, ydiff, 1, 0));
	if (dir == 2)
		return (find_case(xdiff, ydiff, 0, 1));
	if (dir == 3)
		return (find_case(xdiff, ydiff, -1, 0));
}

int     find_case(int xd, int yd, int dirx, int diry)
{
	if ((xd == rotatex(0, 0, dirx, diry)) && (yd == rotatey(0, 0, dirx, diry)))
		return (0);
	if ((xd == rotatex(1, 0, dirx, diry)) && (yd == rotatey(1, 0, dirx, diry)))
		return (1);
	if ((xd == rotatex(1, -1, dirx, diry)) && (yd == rotatey(1, -1, dirx, diry)))
		return (2);
	if ((xd == rotatex(0, -1, dirx, diry)) && (yd == rotatey(0, -1, dirx, diry)))
		return (3);
	if ((xd == rotatex(-1, -1, dirx, diry)) && (yd == rotatey(-1, -1, dirx, diry)))
		return (4);
	if ((xd == rotatex(-1, 0, dirx, diry)) && (yd == rotatey(-1, 0, dirx, diry)))
		return (5);
	if ((xd == rotatex(-1, 1, dirx, diry)) && (yd == rotatey(-1, 1, dirx, diry)))
		return (6);
	if ((xd == rotatex(0, 1, dirx, diry)) && (yd == rotatey(0, 1, dirx, diry)))
		return (7);
	if ((xd == rotatex(1, 1, dirx, diry)) && (yd == rotatey(1, 1, dirx, diry)))
		return (8);
}

int     rotatex(int x, int y, int dirx, int diry)
{
	int     rotated;

	rotated = x * dirx - y * diry;
	return (rotated);
}

int     rotatey(int x, int y, int dirx, int diry)
{
	int     rotated;

	rotated = y * dirx + x * diry;
	return (rotated);
}
