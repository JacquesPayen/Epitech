/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	get_stone_type(char *str, int fd)
{
	int 	i = 0;

	if (str == NULL) {
		dprintf(fd, "ko\n");
		return (-1);
	}
	while (object[i] != NULL && strcmp(object[i], str) != 0)
		i += 1;
	if (object[i] == NULL) {
		dprintf(fd, "ko\n");
		return (-1);
	}
	return (i);
}

int	my_take(char *str, int fd, server_t *server)
{
	int	i = get_stone_type(str, fd);
	player_t	*pt = server->player;

	if (i == -1)
		return (0);
	while (pt->fd != fd)
		pt = pt->next;
	if (server->map->map[pt->y][pt->x][i] < 1) {
		dprintf(fd, "ko\n");
		return (0);	
	}
	server->map->map[pt->y][pt->x][i] -= 1;
	pt->inv[i] += 1;
	place_ressource(server->map->map, server->map->height,
			server->map->width);
	dprintf(fd, "ok\n");
	return (7);
}

int	my_set(char *str, int fd, server_t *server)
{
	int	i = get_stone_type(str, fd);
	player_t	*pt = server->player;

	if (i == -1)
		return (0);
	while (pt->fd != fd)
		pt = pt->next;
	if (pt->inv[i] < 1) {
		dprintf(fd, "ko\n");
		return (0);	
	}
	server->map->map[pt->y][pt->x][i] =  i + 1;
	pt->inv[i] -= 1;
	dprintf(fd, "ok\n");
	return (7);
}
