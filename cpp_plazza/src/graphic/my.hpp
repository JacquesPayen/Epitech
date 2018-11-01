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
#include "../slave.hpp"
#include "../command.hpp"
#include <ncurses.h>

int	isCmd(char *str1, const char *str2);
std::vector<std::string>	commandSet(std::string);
int	getFile(char *str);
int	getNbFile(char *str);
std::vector<std::string>	getInfo(char *str, int nb, int file, const char *info);
int	startServer(int, int);
int	slave(int, int);
void	sendMessage(std::vector<SLAVE> list, WINDOW *,std::vector<std::string> );
void	getMessage(std::vector<SLAVE> list, WINDOW *, std::vector<std::string>);
int	checkCmd(std::string str);
std::string	getArg(WINDOW *, std::vector<SLAVE>, std::vector<std::string>);
void	drawStatus(WINDOW *haut, std::vector<SLAVE> list, std::vector<std::string>);
std::vector<std::string>	getScrap();

#endif /* MY_HPP */
