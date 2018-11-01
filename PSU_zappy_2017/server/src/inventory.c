/*
** EPITECH PROJECT, 2018
** inventory.c
** File description:
** 
*/

#include "../include/my.h"
#include <string.h>
#include <stdio.h>

char	*add_item(char *str, int nb, const char *item)
{
	char	number[12];
	
	str = strcat(str, " ");
	str = strcat(str, item);
	str = strcat(str, " ");
	sprintf(number, "%d", nb);
	str = strcat(str, number);
	str = strcat(str, ",");
	return str;
}

char	*comp_inventory(char *str, player_t *player)
{
	str = strcat(str, "[\0");
	str = add_item(str, player->inv[0], object[0]);
	str = add_item(str, player->inv[1], object[1]);
	str = add_item(str, player->inv[2], object[2]);
	str = add_item(str, player->inv[3], object[3]);
	str = add_item(str, player->inv[4], object[4]);
	str = add_item(str, player->inv[5], object[5]);
	str = add_item(str, player->inv[6], object[6]);
	str[strlen(str) - 1] = ']';
	str[strlen(str)] = '\0';
	return str;
}

int	my_inventory(char *str, int fd, server_t *server)
{
	char	*res = malloc(sizeof(char) * 1000);
	player_t	*pt = server->player;

	while (pt->fd != fd) {
		if (pt == NULL) {
			dprintf(fd, "ko\n");
			return 0;
		}
		pt = pt->next;
	}
	res = comp_inventory(res, pt);
	dprintf(fd, "%s\n", res);
	free(res);
	return 1;
}
