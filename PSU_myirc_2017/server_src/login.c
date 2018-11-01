/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** login
*/

#include "../server_include/irc.h"

void	password(client_t *client_list, char **buf, int fd)
{
	client_t	*client;

	//if no pwd ERR_NEEDMOREPARAMS
	client = get_client_fd(client_list, fd);
	if (client == NULL)
		return ;
		//ERR_UNKNOWNUSER
	if (client->nickname && client->username)
		return ;
		//ERR_ALREADYREGISTRED
	client->password = buf[2];
	write_mes(fd, "Password OK\r\n");
}

void	nickname(client_t *client_list, char **buf, int fd)
{
	client_t	*client;
	client_t	*tmp;

	// if no nickname ERR_NONICKNAMEGIVEN
	/*
	if (strlen(buf[2]) > 9)
		return ;
		//ERR_ERRONEUSNICKNAME
	*/
	client = get_client_fd(client_list, fd);
	if (client == NULL)
		return ;
		//ERR_UNKNOWNUSER
	tmp = get_client_nickname(client_list, buf[2]);
	for (int i = 0 ; buf[i] ; i++) {
		printf("Line : %s\n", buf[i]);
		fflush(stdout);
	}
	if (tmp != NULL) {
		if (tmp == client)
			return ;
			//ERR_NICKCOLLISION
		else { 
			// ERR_NICKNAMEINUSE
			//remove_client(); //client
			//remove_client(); //tmp
		}
	}
	client->nickname = buf[2];
	write_mes(fd, "Nickname OK\r\n");
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

void	username(client_t *client_list, char **buf, int fd)
{
	client_t	*client;

	// check nb params ERR_NEEDMOREPARAMS
	client = get_client_fd(client_list, fd);
	if (client == NULL)
		return ;
		//ERR_UNKNOWNUSER
	if (client->username != NULL)
		return ;
		//ERR_ALREADYREGISTRED
	client->username = buf[2];
	printf("%s\n", client->username);
	write_mes(fd, "Username OK\r\n");
}