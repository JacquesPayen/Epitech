/*
** EPITECH PROJECT, 2018
** ftp
** File description:
** main
*/

#include "../include/my.h"

int	my_setup(void)
{
	int		fd;
	struct protoent	*protocol;

	protocol = getprotobyname("TCP");
	if (protocol == NULL)
		my_exit("Error : get protocol failed\n", -1, -1, 84);
	fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto);
	if (fd == -1)
		my_exit("Error : creat socket failed\n", -1, -1, 84);
	return (fd);
}

int	my_setup_connection(int fd, int port)
{
	struct sockaddr_in	addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(fd, (const struct sockaddr *)&addr, sizeof(addr)) == -1)
		my_exit("Error : bind failed\n", fd, -1, 84);
	if (listen(fd, 1000) == -1)
		my_exit("Error : creat client connection queue failed\n", fd, -1, 84);
	return (0);
}

int	put_player_on_map(server_t *server, player_t *player)
{
	egg_t	*pt = server->egg;
	egg_t	*save = NULL;

	while (pt != NULL) {
		if (pt->timer == 600 && strcmp(pt->team, player->team) == 0) {
			player->x = pt->x;
			player->y = pt->y;
			if (save == NULL)
				server->egg = pt->next;
			else
				save->next = pt->next;
			free(pt);
			return (0);
		}
		save = pt;
		pt = pt->next;
	}
	player->x = rand() % server->map->height;
	player->y = rand() % server->map->width;
	return (0);
}
	

void	set_player(int fd, player_t *pt, char *team, server_t *server)
{
	srand(time(NULL));
	pt->fd = fd;
	pt->team = team;
	put_player_on_map(server, pt);
	pt->dir = rand() % 4;
	pt->lvl = 1;
	pt->food = 0;
	pt->inv[0] = 10;
	for (int i = 1; i < 7; i += 1)
		pt->inv[i] = 0;
	pt->cmd = malloc(sizeof(buff_t));
	pt->cmd->r = 0;
	pt->cmd->w = 0;
	pt->cmd->timer = 0;
	pt->cmd->limit = 0;
	pt->next = NULL;
}

void	create_player(int fd, server_t *server, char *team)
{
	player_t	*pt;

	if (server->player == NULL) {
		server->player = malloc(sizeof(player_t));
		pt = server->player;
	}
	else {
		pt = server->player;
		while (pt->next != NULL)
			pt = pt->next;
		pt->next = malloc(sizeof(player_t));
		pt = pt->next;
	}
	set_player(fd, pt, team, server);
}
