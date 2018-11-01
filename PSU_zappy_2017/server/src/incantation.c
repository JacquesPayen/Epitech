/*
** EPITECH PROJECT, 2018
** incantation.c
** File description:
** incantation
*/

#include "../include/my.h"

int	require_player(server_t *server, player_t *player, int lvl, int nb)
{
	player_t	*other = server->player;
	int	count = 0;
	int	countR = 0;

	while (other != NULL) {
		if (other->x == player->x && other->y == player->y) {
			count += 1;
			if (other->lvl == lvl)
				countR += 1;
		}
		other = other->next;
	}
	if (count == countR && count == nb)
		return (1);
	return (0);
}

void	elevate_player(server_t *server, int x, int y)
{
	player_t        *player = server->player;

	while (player != NULL) {
		if (player->x == x && player->y == y)
			player->lvl += 1;
		player = player->next;
	}
}

int	choose_level(server_t *server, player_t *pt)
{
	if (pt->lvl == 1)
		return (level_1(server, pt));
	if (pt->lvl == 2)
		return (level_2(server, pt));
	if (pt->lvl == 3)
		return (level_3(server, pt));
	if (pt->lvl == 4)
		return (level_4(server, pt));
	if (pt->lvl == 5)
		return (level_5(server, pt));
	if (pt->lvl == 6)
		return (level_6(server, pt));
	if (pt->lvl == 7)
		return (level_7(server, pt));
}

int     my_incantation(char *str, int fd, server_t *server)
{
	player_t        *pt = server->player;
	int	check =  0;

	while (pt->fd != fd) {
		if (pt == NULL)
			return (1);
		pt = pt->next;
	}
	check = choose_level(server, pt);
	if (check == 0) {
		dprintf(fd, "ko\n");
		return (0);
	}
	else
		dprintf(fd, "Elevation underway Current level %i", check);
	return (300);
}
