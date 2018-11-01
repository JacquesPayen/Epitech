/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** channel
*/

#include "../server_include/irc.h"

channel_t	*get_channel(channel_t *channel, char *str)
{
	while (channel != NULL) {
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

	/*
   Channels names are strings (beginning with a '&' or '#' character) of
   length up to 200 characters.  Apart from the the requirement that the
   first character being either '&' or '#'; the only restriction on a
   channel name is that it may not contain any spaces (' '), a control G
   (^G or ASCII 7), or a comma (',' which is used as a list item
   separator by the protocol).
	*/


channel_t	*join(client_t *client_list, char **buf, int fd)
{
	char	**tab;
	channel_t	*channel;

	// if nb chan > 10 ERR_TOOMANYCHANNELS
	tab = my_str_to_wordtab(buf[1], ",");
	if (get_tab_len(tab) < 2)
		//ERR_NEEDMOREPARAMS
	for (int i = 1 ; tab[i] ; i++) {
		if (get_channel(channel, tab[i]) == NULL)
			channel = add_channel(channel, tab[i]);
		if (is_in_channel(client_list, tab[i]) != 0)
			client_list->channels = add_channel(client_list->channels, tab[i]);
	}
	return channel;
}