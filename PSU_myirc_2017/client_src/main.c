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

int	set_client(int port, int fd, char *ip, struct sockaddr_in s_in)
{
	char	buff[1024];
	char	*line;
	size_t	bufsize = 1024;
	t_server	client;

	if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		if (close(fd) == -1)
			return 84;
		return 84;
	}
	line = (char *)malloc(bufsize * sizeof(char));
       	while (1) {
		getline(&line, &bufsize, stdin);
		write(fd, line, sizeof(line));
		read(fd, buff, sizeof(buff));
		write(0, buff, strlen(buff));
	}
	if (close(fd) == -1)
		return 84;
	return 0;
}

int	main(int ac, char **av)
{
	size_t	n;
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
	set_client(port, fd, ip, s_in);
	return 0;
}
