//
// EPITECH PROJECT, 2018
// communication.cpp
// File description:
//
//

#include "my.hpp"

SOCKET	serverStart(SOCKET sock, int nb)
{
	struct sockaddr_in	s_in_client = sock.getClient();
	socklen_t	s_in_size =  sock.getSock();
	int	client_fd;
	int	pid = 1;
	
	if (listen(sock.getFd(), 42) == -1) {
		if(close(sock.getFd()) == -1)
			return sock;
		return sock;
	}
	pid = fork();
	if (pid == 0) {
		slave(sock.getPort(), nb);
	}
	else {
		if ((client_fd = accept(sock.getFd(), (struct sockaddr *)
					&s_in_client, &s_in_size)) == -1) {
			if (close(sock.getFd()) == -1)
				return sock;
			return sock;
		}
	}
	sock.setClient(s_in_client);
	sock.setSock(s_in_size);
	sock.setCfd(client_fd);
	return sock;
}

SOCKET	setServer(SOCKET sock, int nb)
{
	struct sockaddr_in	s_in;
	
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(sock.getPort());
	s_in.sin_addr.s_addr= INADDR_ANY;
	if ((bind(sock.getFd(), (const struct sockaddr*)&s_in, sizeof(s_in))) == -1) {
		if (close(sock.getFd()) == -1)
			return sock;
		return sock;
	}
	sock.setSin(s_in);
	sock = serverStart(sock, nb);
	return sock;
}

int	startServer(int port, int nb)
{
	SOCKET	sock;
	struct protoent	*pe;
	int	fd;
	struct sockaddr_in	s_in_client;
	socklen_t	s_in_size;

	sock.setCfd(84);
	s_in_size = sizeof(s_in_client);
	if ((pe = getprotobyname("TCP")) == NULL)
		return 84;
	if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		return 84;
	sock.setPe(pe);
	sock.setFd(fd);
	sock.setClient(s_in_client);
	sock.setSock(s_in_size);
	sock.setPort(port);
	sock = setServer(sock, nb);
	return sock.getCfd();
}
