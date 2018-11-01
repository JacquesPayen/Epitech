/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../server_include/irc.h"

void	exit_close(int fd)
{
	close(fd);
	exit(84);
}

void	set_fd(server_t *client, struct timeval *tv, int fd)
{
	FD_ZERO(&client->fd_r);
	FD_SET(fd, &client->fd_r);
	FD_SET(1, &client->fd_r);
	tv->tv_sec = 5;
	tv->tv_usec = 0;	
}

int	set_client(int fd, struct sockaddr_in s_in)
{
	int	a = 0;
	char	buff[1024];
	struct timeval	tv;
	char	*line = malloc(sizeof(char) * 1024);
	int	ret;
	size_t	bufsize = 1024;
	server_t	client;

       	while (1) {
		set_fd(&client, &tv, fd);
		if ((ret = select(fd + 1, &client.fd_r, NULL, NULL, &tv)) != -1) {
			if (ret && FD_ISSET(fd, &client.fd_r) && a == 0) {
				if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
					exit_close(fd);
				a = 1;
			}
			else if (FD_ISSET(fd, &client.fd_r) && a == 1){
				read(fd, buff, sizeof(buff));
				write(0, buff, strlen(buff));
			}
			if (FD_ISSET(1, &client.fd_r)) {
				getline(&line, &bufsize, stdin);
				write(fd, line, sizeof(line));
			}
		}
	}
	if (close(fd) == -1)
		return 84;
	return 0;
}

int	main(int ac, char **av)
{
	struct sockaddr_in	s_in;
	struct protoent	*pe;
	int	fd;
	int	port;
	char	*ip;
	
	if (ac != 3)
		return 84;
	ip = av[1];
	port = atoi(av[2]);
	if ((pe = getprotobyname("TCP")) == NULL)
		return 84;
	if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		return 84;
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = inet_addr(ip);
	set_client(fd, s_in);
	return 0;
}
