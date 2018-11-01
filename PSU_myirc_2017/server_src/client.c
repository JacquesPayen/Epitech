/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#include "../server_include/irc.h"

void	set_null_value(client_t *new_client)
{
	new_client->password = NULL;
	new_client->nickname = NULL;
	new_client->username = NULL;
	new_client->channels = NULL;
	new_client->next = NULL;
}

client_t	*add_client(client_t *client_list, int fd, fd_set *fd_r, fd_set *fd_w)
{
	client_t	*client_list_s;
	client_t	*new_client;

	new_client = malloc(sizeof(*new_client));
	if (new_client == NULL)
		exit(84);
	new_client->fd = fd;
	new_client->fd_r = fd_r;
	new_client->fd_w = fd_w;
	set_null_value(new_client);
	if (client_list == NULL)
		return new_client;
	client_list_s = client_list;
	while (client_list->next)
		client_list = client_list->next;
	client_list->next = new_client;
	return client_list_s;
}

void	free_values(client_t *client)
{
	if (client->nickname)
		free(client->nickname);
	if (client->username)
		free(client->username);
	if (client->password)
		free(client->password);
	// add channels list free
}

client_t	*remove_client(client_t *client_list, int fd)
{
	client_t	*client;
	client_t	*client_save;

	client = client_list;
	while (client && client->fd != fd) {
		client_save = client;
		client = client->next;
	}
	if (!client)
		return client_list;
	//free_values(client);
	if (client == client_list) {
		client_save = client->next;
		free(client);
		return (client_save);
	}
	client_save->next = client->next;
	free(client);
	return client_list;
}

client_t	*get_client_fd(client_t *client_list, int fd)
{
	while (client_list) {
		if (client_list->fd == fd)
			return client_list;
		client_list = client_list->next;
	}
	return NULL;
}

client_t	*get_client_nickname(client_t *client_list, char *nickname)
{
	while (client_list) {
		if (strcmp(client_list->nickname, nickname) == 0)
			return client_list;
		client_list = client_list->next;
	}
	return NULL;
}
