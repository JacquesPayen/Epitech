//
// EPITECH PROJECT, 2018
// socket.cpp
// File description:
// 
//

#include "socket.hpp"

SOCKET::SOCKET()
{
}

SOCKET::~SOCKET()
{
}

struct protoent	*SOCKET::getPe()
{
	return pe;
}

void	SOCKET::setPe(struct protoent *spe)
{
	pe = spe;
}

int	SOCKET::getFd()
{
	return fd;
}

void	SOCKET::setFd(int sfd)
{
	fd = sfd;
}

struct sockaddr_in	SOCKET::getClient()
{
	return s_in_client;
}

void	SOCKET::setClient(struct sockaddr_in ss_in_client)
{
	s_in_client = ss_in_client;
}

socklen_t	SOCKET::getSock()
{
	return s_in_size;
}

void	SOCKET::setSock(socklen_t len)
{
	s_in_size = len;
}

struct sockaddr_in	SOCKET::getSin()
{
	return s_in;
}

void	SOCKET::setSin(struct sockaddr_in in)
{
	s_in = in;
}

int	SOCKET::getCfd()
{
	return client_fd;
}

void	SOCKET::setCfd(int sfd)
{
	client_fd = sfd;
}

int	SOCKET::getPort()
{
	return port;
}

void	SOCKET::setPort(int sport)
{
	port = sport;
}
