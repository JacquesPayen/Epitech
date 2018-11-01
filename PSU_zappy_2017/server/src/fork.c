/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

void	create_egg(server_t *server, player_t *player)
{	
	egg_t	*pt;

	if (server->egg == NULL) {
		server->egg = malloc(sizeof(egg_t));
		pt = server->egg;
	}
	else {
		pt = server->egg;
		while (pt->next != NULL)
			pt = pt->next;
		pt->next = malloc(sizeof(player_t));
		pt = pt->next;
	}
	pt->team = player->team;
	pt->x = player->x;
	pt->y = player->y;
	pt->timer = 0;
	pt->next = NULL;
}

int	my_fork(char *str, int fd, server_t *server)
{
	player_t	*pt = server->player;

	while (pt->fd != fd)
		pt = pt->next;
	create_egg(server, pt);
	return (42);
}

void	my_hatching(server_t *server)
{
	egg_t	*pte = server->egg;
	team_t	*ptt = server->team;

	while (pte != NULL) {
		if (pte->timer < 601)
			pte->timer += 1;
		if (pte->timer == 600) {
			while (strcmp(ptt->name, pte->team) != 0)
				ptt = ptt->next;
			ptt->max_player += 1;
		}
		pte = pte->next;
	}
}