/*
** EPITECH PROJECT, 2018
** connect_nbr
** File description:
** 
*/

#include "../include/my.h"


int	my_connect_nbr(char *str, int fd, server_t *server)
{
	int	nbr;
	team_t	*ptt = server->team;
	player_t	*ptp = server->player;

	while (ptp->fd != fd)
		ptp = ptp->next;
	while (strcmp(ptp->team, ptt->name) != 0)
		ptt = ptt->next;
	nbr = ptt->max_player - ptt->nb_player;
	dprintf(fd, "%d\n", nbr);
	return (0);
}
