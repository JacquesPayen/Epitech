/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	my_help()
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
	printf("name2 ...  -c clientsNb -f freq\n");
	exit(0);
}

void	my_exit(char *msg, int fd, int fd_client, int ret)
{
	printf("%s", msg);
	if (fd != -1)
		if (close(fd) == -1)
			printf("Error : close socket failed\n");
	if (fd_client != -1)
		if (close(fd_client) == -1)
			printf("Error : close client connection failed");
	if (ret != -1)
		exit(ret);
}

int	set_readfds(server_t *server)
{
	int		max = server->fd;
	player_t	*pt;

	FD_ZERO(&(server->ref_set));
	FD_SET(server->fd, &(server->ref_set));
	if (server->player == NULL)
		return (max + 1);
	pt = server->player;
	while (pt != NULL) {
		FD_SET(pt->fd, &(server->ref_set));
		if (pt->fd > max)
			max = pt->fd;
		pt = pt->next;
	}
	return (max + 1);
}

int	read_cmd(buff_t *buff, int i, int j, char *c)
{
	if (c[j] != '\n') {
		buff->data[buff->w % 10][i] = c[j];
		i += 1;
	}
	else {
		buff->data[buff->w % 10][i] = '\n';
		buff->w += 1;
		if (i < j)
			memset(buff->data[buff->w % 10], '\0', 128);
		i = 0;
	}
	return (i);
}

void	get_request(int fd, server_t *server)
{
	int	nb;
	player_t	*player = server->player;
	char	c[500];
	int	i = 0;
	int	j = 0;

	nb = read(fd, c, 500);
	while (player->fd != fd)
		player = player->next;
	if (player->cmd->w - player->cmd->r < 10)
		memset(player->cmd->data[player->cmd->w % 10], '\0', 128);
	while (j < nb && player->cmd->w - player->cmd->r < 10) {
		i = read_cmd(player->cmd, i, j, c);
		j += 1;
	}
}