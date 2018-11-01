/*
** EPITECH PROJECT, 2018
** server.c
** File description:
** 
*/

#include "../server_include/irc.h"

void	write_mes(int fd, char *mes)
{
	dprintf(fd, "%s\r\n", mes);
}

char	*handle_client(int cs1)
{
	char	*res;
	char	buff[1024];
	int	len;

	len = read(cs1, buff, sizeof(buff));
	if (len == -1)
		return NULL;
	else if (len == 0)
		return NULL;
	res = malloc(sizeof(char) * (strlen(buff) + 100));
	return res;
}

void	gest_cmd(server_t *client, int fd, int *nb)
{
	int	a = 0;
	int	last = 0;
	char	*res = malloc(sizeof(char) * (strlen(client->str) + 10));
	char	*str = malloc(sizeof(char) * (strlen(client->str) + 10));
	int	i = 0;

	while (client->str[i] != '\0') {		
		if (client->str[i] == '\n') {
			strcpy(str, client->str);
			str[0] = '\0';
			strcat(str, &client->str[last]);
			str[i + 1] = '\0';
			last = i + 1;
			sprintf(res, "%d ", fd);
			strcat(res, str);
			while (res[a] != '\r' && res[a] != '\0')
				a++;
			res[a] = '\0';
			a = 0;
			*nb = *nb + 1;
			buf_put(&client->buff, res);
		}
		i++;
	}
}

void	do_cmd(int i, server_t *client)
{
	int	a = 0;

	while (a < i) {
		cmd(client);
		a++;
	}
}

client_t	*get_message(server_t *client, client_t *save)
{
	int	i = 0;

	while (save != NULL) {
		if (FD_ISSET(save->fd, &client->fd_r))
		{
			if (fcntl(save->fd, F_GETFD) != -1) {
				client->str = handle_client(save->fd);
				if (client->str != NULL)
					gest_cmd(client, save->fd, &i);
				else {
					close(save->fd);
					client->client_list = remove_client(client->client_list, save->fd);
				}
			}
		}
		save = save->next;
	}
	do_cmd(i, client);
	return client->client_list;
}

void	close_exit(int fd)
{
	close(fd);
	exit(84);
}

server_t	set_list(server_t client, int fd, struct timeval *tv, client_t *list)
{
	tv->tv_sec = 5;
	tv->tv_usec = 0;
	FD_ZERO(&client.fd_r);
	FD_SET(fd, &client.fd_r);
	while (list != NULL) {
		FD_SET(list->fd, &client.fd_r);
		list = list->next;
	}
	return client;
}
