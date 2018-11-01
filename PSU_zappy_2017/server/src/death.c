/*
** EPITECH PROJECT, 2018
** death
** File description:
** 
*/

#include "../include/my.h"

void	delete_map(server_t *server)
{
	for (int y = 0; y < server->map->height; y += 1) {
		for (int x = 0; x < server->map->width; x += 1)
			free(server->map->map[y][x]);
		free(server->map->map[y]);
	}
	free(server->map->map);
	free(server->map);
}

void	delete_client(server_t *server, int fd)
{
	player_t	*pt = server->player;
	player_t	*save = NULL;

	while (pt->fd != fd) {
		save = pt;
		pt = pt->next;
	}
	if (save == NULL)
		server->player = pt->next;
	else
		save->next = pt->next;
	dprintf(pt->fd, "dead\n");	
	free(pt->cmd);
	free(pt);
}

void	delete_team(server_t *server, char *name)
{
	team_t	*pt = server->team;
	team_t	*save = NULL;

	while (strcmp(pt->name, name) != 0) {
		save = pt;
		pt = pt->next;
	}
	if (save == NULL)
		server->team = pt->next;
	else
		save->next = pt->next;
	free(pt);
}

void	my_death(server_t *server)
{
	player_t	*ptp = server->player;

	while (ptp != NULL) {
		ptp->food += 1;
		if (ptp->food == 126) {
			ptp->inv[0] -= 1;
			ptp->food = 0;
		}
		if (ptp->inv[0] <= 0)
			delete_client(server, ptp->fd);
		ptp = ptp->next;
	}
}
