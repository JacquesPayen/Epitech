/*
** EPITECH PROJECT, 2018
** incantation.c
** File description:
** incantation
*/

#include "../include/my.h"

int	level_1(server_t *server, player_t *pt)
{
	int	x = pt->x;
	int	y = pt->y;

	if (require_player(server, pt, 1, 1) == 0)
		return (0);
	if (server->map->map[y][x][1] < 1)
		return (0);
	server->map->map[y][x][1] -= 1;
	elevate_player(server, x, y);
	return (1);
}

int     level_2(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 2, 2) == 0)
		return (0);
	if (server->map->map[y][x][1] < 1 || server->map->map[y][x][2] < 1
		 || server->map->map[y][x][3] < 1)
		return (0);
	server->map->map[y][x][1] -= 1;
	server->map->map[y][x][2] -= 1;
	server->map->map[y][x][3] -= 1;
	elevate_player(server, x, y);
	return (2);
}

int     level_3(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 3, 2) == 0)
		return (0);
	if (server->map->map[y][x][1] < 2 || server->map->map[y][x][3] < 1
	    || server->map->map[y][x][5] < 2)
		return (0);
	server->map->map[y][x][1] -= 2;
	server->map->map[y][x][3] -= 1;
	server->map->map[y][x][5] -= 2;
	elevate_player(server, x, y);
	return (3);
}

int     level_4(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 4, 4) == 0)
		return (0);
	if (server->map->map[y][x][1] < 1 || server->map->map[y][x][2] < 1
	    || server->map->map[y][x][3] < 2 || server->map->map[y][x][5] < 1)
		return (0);
	server->map->map[y][x][1] -= 1;
	server->map->map[y][x][2] -= 1;
	server->map->map[y][x][3] -= 2;
	server->map->map[y][x][5] -= 1;
	elevate_player(server, x, y);
	return (4);
}

int     level_5(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 5, 4) == 0)
		return (0);
	if (server->map->map[y][x][1] < 1 || server->map->map[y][x][2] < 2
	    || server->map->map[y][x][3] < 1 || server->map->map[y][x][4] < 3)
		return (0);
	server->map->map[y][x][1] -= 1;
	server->map->map[y][x][2] -= 2;
	server->map->map[y][x][3] -= 1;
	server->map->map[y][x][4] -= 3;
	elevate_player(server, x, y);
	return (5);
}
