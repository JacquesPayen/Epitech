/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel
*/

#include "../server_include/irc.h"

channel_t	*get_channel(channel_t *channel, char *str)
{
	while (channel) {
		if (strcmp(channel->name, str) == 0)
			return channel;
		channel = channel->next;
	}
	return NULL;
}

channel_t	*add_channel(channel_t *channel, char *str)
{
	channel_t	*channel_s;
	channel_t	*new_channel;

	new_channel = malloc(sizeof(channel_t));
	if (new_channel == NULL)
		exit(84);
	new_channel->name = strdup(str);
	printf("Added channel : %s\n", str);
	fflush(stdout);
	if (channel_s == NULL)
		return new_channel;
	channel_s = channel;
	while (channel->next)
		channel = channel->next;
	channel->next = new_channel;
	return channel_s;
}

int	is_in_channel(client_t *client, char *str)
{
	channel_t *channel = client->channels;

	while (channel != NULL) {
		if (strcmp(channel->name, str) == 0)
			return 0;
		channel = channel->next;
	}
	return 1;
}

void	join(server_t *server, char **buf, int fd)
{
	client_t	*client;

	for (int i = 2 ; buf[i] ; i++) {
		if (get_channel(server->channel_list, buf[i]) == NULL)
			server->channel_list = add_channel(server->channel_list, buf[i]);
		client = get_client_fd(server->client_list, fd);
		if (is_in_channel(server->client_list, buf[i]) != 0)
			client->channels = add_channel(client->channels, buf[i]);
	}
}