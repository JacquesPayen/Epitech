/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	my_broadcast(char *str, int fd, server_t *server)
{
	player_t	*src = server->player;
	player_t	*dest = server->player;
	int		tile;

	if (str == NULL) {
		dprintf(fd, "ko\n");
		return (0);
	}
	while (src->fd != fd)
		src = src->next;
	while (dest != NULL) {
		tile = get_sound_tile(src, dest, server->map);
		dprintf(dest->fd, "message %d, %s\n", tile, str);
		dest = dest->next;
	}
	dprintf(fd, "ok\n");
	return (7);
}