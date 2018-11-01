/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/

#include "../server_include/irc.h"

server_t	set_client(void)
{
	server_t	client;

	client.channel_list = NULL;
	client.client_list = NULL;
	client.buff.size = 1024;
	client.buff.buffer = malloc(sizeof(char*) * (client.buff.size + 1));
	buf_reset(&client.buff);
	return client;
}

int	server_start(struct sockaddr_in s_in_client, int fd, socklen_t s_in_size)
{
	server_t	client = set_client();
	int	ret;
	int	max = 1;
	int	client_fd = 0;
	struct timeval	tv;

	if (listen(fd, 42) == -1)
		close_exit(fd);
	while (1) {
		client = set_list(client, fd, &tv, client.client_list);
		if ((ret = select(fd + max, &client.fd_r, NULL, NULL, &tv)) == -1)
			close_exit(fd);
		else if (ret && FD_ISSET(fd, &client.fd_r)){
			if ((client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size)) == -1)
				close_exit(fd);
			max++;
			client.client_list = add_client(client.client_list, client_fd, &client.fd_r, &client.fd_w);
		}
		client.client_list = get_message(&client, client.client_list);
	}
	return 0;
}

int	server(struct sockaddr_in s_in_client, int fd, socklen_t s_in_size, int port)
{
	struct sockaddr_in	s_in;
	
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr= INADDR_ANY;
	if ((bind(fd, (const struct sockaddr*)&s_in, sizeof(s_in))) == -1) {
		if (close(fd) == -1)
			return 84;
		return 84;
	}
	server_start(s_in_client, fd, s_in_size);
	if (close(fd) == -1)
		return 84;
	return 0;
}

int	main(int ac, char **av)
{
	struct protoent	*pe;
	int	fd;
	int	port;
	struct sockaddr_in	s_in_client;
	socklen_t	s_in_size;

	if (ac == 2 && strcmp("-h", av[1]) == 0)
		return 0;
	if (ac != 2)
		return 84;
	s_in_size = sizeof(s_in_client);
	port = atoi(av[1]);
	if ((pe = getprotobyname("TCP")) == NULL)
		return 84;
	if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		return 84;
	server(s_in_client, fd, s_in_size, port);
	return 0;
}
