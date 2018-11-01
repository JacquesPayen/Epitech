/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** irc
*/

#ifndef IRC_H_
	#define IRC_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>

#include "client.h"

typedef struct buf_s {
	char	**buffer;
	size_t	head;
	size_t	tail;
	size_t	size;
} buf_t;

typedef struct	s_server
{
	fd_set	fd_r;
	fd_set	fd_w;
	int	client_fd;
	char	*str;
	buf_t	buff;
} t_server;

char	*buf_get(buf_t*);
char	**my_str_to_wordtab(char*, char*);
client_t	*get_client_nickname(client_t*, char*);

#endif /* !IRC_H_ */
