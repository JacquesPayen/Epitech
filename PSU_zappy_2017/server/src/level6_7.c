/*
** EPITECH PROJECT, 2018
** incantation.c
** File description:
** incantation
*/

#include "../include/my.h"

int     level_6(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 6, 6) == 0)
		return (0);
	if (server->map->map[y][x][1] < 1 || server->map->map[y][x][2] < 2
	    || server->map->map[y][x][3] < 3 || server->map->map[y][x][5] < 1)
		return (0);
	server->map->map[y][x][1] -= 1;
	server->map->map[y][x][2] -= 2;
	server->map->map[y][x][3] -= 3;
	server->map->map[y][x][5] -= 1;
	elevate_player(server, x, y);
	return (6);
}

int     level_7(server_t *server, player_t *pt)
{
	int     x = pt->x;
	int     y = pt->y;

	if (require_player(server, pt, 7, 6) == 0)
		return (0);
	if (server->map->map[y][x][1] < 2 || server->map->map[y][x][2] < 2
	    || server->map->map[y][x][3] < 2 || server->map->map[y][x][4] < 2
	    || server->map->map[y][x][5] < 2 || server->map->map[y][x][6] < 1)
		return (0);
	server->map->map[y][x][1] -= 2;
	server->map->map[y][x][2] -= 2;
	server->map->map[y][x][3] -= 2;
	server->map->map[y][x][4] -= 2;
	server->map->map[y][x][5] -= 2;
	server->map->map[y][x][6] -= 1;
	elevate_player(server, x, y);
	return (7);
}
