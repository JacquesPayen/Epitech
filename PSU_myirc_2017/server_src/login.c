/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** login
*/

#include "../server_include/irc.h"

void	password(server_t *server, char **buf, int fd)
{
	char	str[512];
	client_t	*client;

	if (get_tab_len(buf) < 3) {
		sprintf(str, ERR461, buf[1]);
		write_mes(fd, str);
		return ;
	}
	client = get_client_fd(server->client_list, fd);
	if (client->nickname && client->username) {
		sprintf(str, ERR462);
		write_mes(fd, str);
		return ;
	}
	client->password = buf[2];
}

int	check_nickname(char **buf, int fd)
{
	char	str[512];

	if (get_tab_len(buf) < 3) {
		sprintf(str, ERR431);
		write_mes(fd, str);
		return 1;
	}
	if (strlen(buf[2]) > 9) {
		sprintf(str, ERR432, buf[2]);
		write_mes(fd, str);
		return 1;
	}
	return 0;
}

void	nickname(server_t *server, char **buf, int fd)
{
	char	str[512];
	client_t	*client;
	client_t	*tmp;

	if (check_nickname(buf, fd) != 0)
		return ;
	client = get_client_fd(server->client_list, fd);
	tmp = get_client_nickname(server->client_list, buf[2]);
	if (tmp != NULL) {
		if (tmp != client) {
			sprintf(str, ERR433, buf[2]);
			write_mes(fd, str);
			return ;
		}
	}
	client->nickname = buf[2];
	if (client->username) {
		sprintf(str, "001 %s %s", client->nickname, MSG001);
		write_mes(fd, str);
	}
}

int	check_username(char *username)
{
	for (int i = 0 ; username[i] ; i++) {
		if (isalpha(username[i]) && isalnum(username[i])
		&& username[i] != '-' && username[i] != '['
		&& username[i] != ']' && username[i] != '\\'
		&& username[i] != '`' && username[i] != '^'
		&& username[i] != '{' && username[i] != '}'
		&& username[i] != '_')
			return 0;
	}
	return 1;
}

void	username(server_t *server, char **buf, int fd)
{
	char	str[512];
	client_t	*client;

	if (get_tab_len(buf) < 6) {
		sprintf(str, ERR461, buf[1]);
		write_mes(fd, str);
		return ;
	}
	client = get_client_fd(server->client_list, fd);
	if (client->username != NULL) {
		sprintf(str, ERR462);
		write_mes(fd, str);
		return ;
	}
	client->username = buf[2];
	if (client->username) {
		sprintf(str, "001 %s %s", client->nickname, MSG001);
		write_mes(fd, str);
	}
}