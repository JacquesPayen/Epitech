/*
** EPITECH PROJECT, 2018
** elevation
** File description:
** 
*/

#include "../include/my.h"



int	my_eject2(player_t *ptp, player_t *pto, map_t *ptm)
{
		if (ptp->dir == 0)
			pto->y -= 1;
		if (ptp->dir == 1)
			pto->x += 1;
		if (ptp->dir == 2)
			pto->y += 1;
		if (ptp->dir == 3)
			pto->x -= 1;
		if (pto->y < 0)
			pto->y = ptm->height - 1;
		if (pto->x == ptm->width)
			pto->x = 0;
		if (pto->y == ptm->height)
			pto->y = 0;
		if (pto->x < 0)
			pto->x == ptm->width - 1;
		return (1);
}

int	my_eject(char *str, int fd, server_t *server)
{
	map_t	*ptm = server->map;
	player_t	*ptp = server->player;
	player_t	*pto = server->player;
	int	i = 0;
	
	while (ptp->fd != fd)
		ptp->next;
	while (pto != NULL)
	{
		if (pto->fd != ptp->fd && ptp->x == pto->x
		    && ptp->y == pto->y)
			i = my_eject2(ptp, pto, ptm);
		pto->next;
	}
	if (i != 0)
		dprintf(fd, "ok");
	else
		dprintf(fd, "ko");
	return (7);
}
