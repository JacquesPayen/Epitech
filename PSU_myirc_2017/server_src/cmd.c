/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** cmd
*/

#include "../server_include/irc.h"

void	quit(server_t *server, int fd)
{
	server->client_list = remove_client(server->client_list, fd);
	close(fd);
}

void	cmd(server_t *server)
{
	char	**tab;
	int	fd;
	char	*str;

	str = buf_get(&server->buff);
	tab = my_str_to_wordtab(str, " ");
	fd = atoi(tab[0]);
	str = tab[1];
	if (strncmp(str, "PASS", 4) == 0)
		password(server, tab, fd);
	if (strncmp(str, "NICK", 4) == 0)
		nickname(server, tab, fd);
	if (strncmp(str, "USER", 4) == 0)
		username(server, tab, fd);
	if (strncmp(str, "QUIT", 4) == 0)
		quit(server, fd);
	if (strncmp(str, "JOIN", 5) == 0)
		join(server, tab, fd);
	//if (strncmp(str, "PRIVMSG", 7) == 0)
		//
}
