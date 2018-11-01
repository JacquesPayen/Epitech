/*
** EPITECH PROJECT, 2018
** serv_fonc
** File description:
** 
*/

#include "../include/my.h"

int	my_left(char *str, int fd, server_t *server)
{
	player_t	*pt = server->player;

	while (pt->fd != fd)
		pt = pt->next;
	if (pt->dir == 0)
		pt->dir = 3;
	else
		pt->dir -= 1;
	dprintf(fd, "ok\n");
	return (7);
}

int	my_right(char *str, int fd, server_t *server)
{
	player_t	*pt = server->player;

	while (pt->fd != fd)
		pt = pt->next;
	if (pt->dir == 3)
		pt->dir = 0;
	else
		pt->dir += 1;
	dprintf(fd, "ok\n");
	return (7);
}
