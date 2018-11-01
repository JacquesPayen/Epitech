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
#include <ctype.h>

#include "client.h"

typedef struct buf_s {
	char	**buffer;
	size_t	head;
	size_t	tail;
	size_t	size;
} buf_t;

typedef struct	server_s
{
	fd_set	fd_r;
	fd_set	fd_w;
	int	client_fd;
	char	*str;
	buf_t	buff;
	client_t	*client_list;
	channel_t	*channel_list;
} server_t;

char	*buf_get(buf_t*);
char	**my_str_to_wordtab(char*, char*);
client_t	*add_client(client_t*, int, fd_set*, fd_set*);
client_t	*remove_client(client_t*, int);
client_t	*get_client_fd(client_t*, int);
client_t	*get_client_nickname(client_t*, char*);
server_t	set_list(server_t, int, struct timeval *, client_t *);
client_t	*get_message(server_t *, client_t *);
char	*handle_client(int);
void	write_mes(int, char *);
void	close_exit(int);
void	buf_reset(buf_t *);
void	buf_put(buf_t *, char *);
char	*buf_get(buf_t *);
client_t	*add_client(client_t *, int, fd_set *, fd_set *);
client_t	*remove_client(client_t *, int);
void	cmd(server_t *);
void	password(server_t *, char **, int);
void	nickname(server_t *, char **, int);
void	username(server_t *, char **, int);
int	get_tab_len(char **);
void	join(server_t*, char**, int);

#define MSG001 "001 %s :Welcome to my IRC server !"
#define ERR431 "431 :No nickname given"
#define ERR432 "432 %s :Erroneus nickname"
#define ERR433 "433 %s :Nickname is already in use"
#define ERR461 "461 %s :Not enough parameters"
#define ERR462 "462 :You may not reregister"

#endif /* !IRC_H_ */
