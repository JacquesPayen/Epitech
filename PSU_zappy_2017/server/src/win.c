/*
** EPITECH PROJECT, 2018
** win
** File description:
** 
*/

#include "../include/my.h"

void	close_server(server_t *server)
{
	printf("lol\n");
	fflush(stdout);
	egg_t	*pt = server->egg;

	printf("xxx\n");
	fflush(stdout);
	while (server->player != NULL)
		delete_client(server, server->player->fd);
	while (server->team != NULL)
		delete_team(server, server->team->name);
	while (server->egg != NULL) {
		pt = pt->next;
		free(server->egg);
		server->egg = pt;
	}
	delete_map(server);
	close(server->fd);
	free(server);
	exit(0);
}

char	*my_win(server_t *server)
{
	team_t	*ptt = server->team;
	player_t	*ptp;
	int	i;
	
	while (ptt != NULL)
	{
		i = 0;
		ptp = server->player;
		while (ptp != NULL)
		{
			if (strcmp(ptp->team, ptt->name) && ptp->lvl == 8)
				i++;
			if (i > 5)
				return (ptt->name);
			ptp = ptp->next;
		}
		ptt = ptt->next;
	}
	return (NULL);
}
