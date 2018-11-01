/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** client
*/

#ifndef CLIENT_H_
	#define CLIENT_H_

#include <sys/select.h>
#include "channel.h"

typedef struct client_s
{
	char	*username;
	char	*password;
	char	*nickname;
	int	fd;
	fd_set	*fd_r;
	fd_set	*fd_w;
	channel_t	*channels;
	struct client_s	*next;
} client_t;

client_t	*add_client(client_t *client_list, int fd, fd_set *fd_r, fd_set *fd_w);
client_t	*get_client_nickname(client_t *client_list, char *nickname);
client_t	*get_client_fd(client_t *client_list, int fd);
client_t	*remove_client(client_t *client_list, int fd);

#endif /* !CLIENT_H_ */
