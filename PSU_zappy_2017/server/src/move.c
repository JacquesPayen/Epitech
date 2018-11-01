/*
** EPITECH PROJECT, 2018
** move
** File description:
** 
*/

#include "../include/my.h"

void	move_up(server_t *server, player_t *pt)
{
	pt->y -= 1;
	if (pt->y < 0)
		pt->y = server->map->height - 1;
}

void	move_r(server_t *server, player_t *pt)
{
	pt->x += 1;
	if (pt->x == server->map->width)
		pt->x = 0;
}

void	move_down(server_t *server, player_t *pt)
{
	pt->y += 1;
	if (pt->y == server->map->height)
		pt->y = 0;
}

void	move_l(server_t *server, player_t *pt)
{
	pt->x -= 1;
	if (pt->x < 0)
		pt->x = server->map->width - 1;
}

int    my_forward(char *str, int fd, server_t *server)
{
	player_t	*pt = server->player;

	while (pt->fd != fd)
		pt = pt->next;
	if (pt->dir == 0)
		move_up(server, pt);
	if (pt->dir == 1)
		move_r(server, pt);
	if (pt->dir == 2)
		move_down(server, pt);
	if (pt->dir == 3)
		move_l(server, pt);
	dprintf(fd, "ok\n");
	return (7);
}
