//
// EPITECH PROJECT, 2018
// look
// File description:
// 
//

#include "../include/my.h"

void	tile_to_str(player_t *tile, char *str, server_t *server, int mode)
{
	int	nb;
	map_t 	*map = server->map;
	player_t	*pt = server->player;

	if (mode == 1)
		strcat(str, ",");
	while (pt != NULL) {
		if (pt->x == tile->lvl && pt->y == tile->food)
			strcat(str, " player");
		pt = pt->next;
	}
	for (int i = 0; i < 7; i += 1) {
		nb = map->map[tile->food][tile->lvl][i];
		for (int j = 0; j < nb; j += 1) {
			strcat(str, " ");
			strcat(str, object[i]);
		}
	}
}

player_t	*pos_mut(player_t *pos, int j, map_t *map)
{
	pos->lvl = pos->x;
	pos->food = pos->y;
	if (pos->dir == 0)
		pos->lvl = pos->x + j;
	else if (pos->dir == 1)
		pos->food = pos->y + j;
	else if (pos->dir == 2)
		pos->lvl = pos->x - j;
	else
		pos->food = pos->y - j;
	if (pos->lvl >= map->width)
		pos->lvl = pos->lvl - map->width;
	if (pos->food >= map->height)
		pos->food = pos->food - map->height;
	if (pos->lvl < 0)
		pos->lvl = pos->lvl + map->width;
	if (pos->food < 0)
		pos->food = pos->food + map->height;
	return (pos);
}

player_t	*ori_mut(player_t *pos, map_t *map)
{
	if (pos->dir == 1) {
		pos->y -= 1;
		pos->x += 1;
	}
	else if (pos->dir == 2) {
		pos->y += 1;
		pos->x += 1;
	}
	else if (pos->dir == 3){
		pos->y += 1;
		pos->x += 1;
	}
	else {
		pos->x -= 1;
		pos->y -= 1;
	}
	if (pos->x >= map->width)
		pos->x = pos->x - map->width;
	if (pos->y >= map->height)
		pos->y = pos->y - map->height;
	return (pos);
}

int	my_look(char *str, int fd, server_t *server)
{
	char	*output = malloc(sizeof(char) * 1024);
	player_t	*pt =  server->player;
	player_t	*sight = malloc(sizeof(player_t));
	int	mode = 0;

	memset(output, '\0', 1023);
	output[0] = '[';
	while (pt->fd != fd)
		pt = pt->next;
	sight->x = pt->x;
	sight->y = pt->y;
	sight->dir = pt->dir;
	for (int i = 0; i <= pt->lvl; i += 1) {
		for (int j = 0; j < 1 + 2 * i; j += 1) {
			tile_to_str(pos_mut(sight, j, server->map), output,
				server, mode);
			mode = 1;
		}
		ori_mut(sight, server->map);
	}
	dprintf(fd, "%s ]\n", output);
	return (7);
}
