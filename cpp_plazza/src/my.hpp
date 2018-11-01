//
// EPITECH PROJECT, 2018
// my.hpp
// File description:
// 
//

#ifndef MY_HPP
#define MY_HPP

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
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "slave.hpp"
#include "command.hpp"
#include "slave.hpp"
#include "socket.hpp"

int	isCmd(char *str1, const char *str2);
std::vector<std::string>	commandSet(std::string);
int	getFile(char *str);
int	getNbFile(char *str);
std::vector<std::string>	getInfo(char *str, int nb, int file, const char *info);
int	startServer(int, int);
int	slave(int, int);
void	sendMessage(std::vector<SLAVE> list);
void	getMessage(std::vector<SLAVE> list);
int	checkCmd(std::string str);

#endif /* MY_HPP */
