//
// EPITECH PROJECT, 2018
// socket.hpp
// File description:
// 
//

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class	SOCKET
{
public:
	SOCKET();
	~SOCKET();
	struct protoent	*getPe();
	void	setPe(struct protoent *spe);
	int	getFd();
	void	setFd(int sfd);
	struct sockaddr_in	getClient();
	void	setClient(struct sockaddr_in ss_in_client);
	socklen_t	getSock();
	void	setSock(socklen_t);
	struct sockaddr_in	getSin();
	void	setSin(struct sockaddr_in );
	int	getCfd();
	void	setCfd(int);
	int	getPort();
	void	setPort(int);
private:
	struct protoent	*pe;
	int	fd;
	struct sockaddr_in	s_in_client;
	socklen_t	s_in_size;
	struct sockaddr_in	s_in;
	int	client_fd;
	int	port;
};

#endif /* SOCKET_HPP */
