/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef MY_H_
#define MY_H_

#include <new>
#include <string.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <regex>
#include "../src/socket.hpp"
#include "../src/command.hpp"
#include "../src/argument.hpp"

std::vector<std::string>	search(std::string file, std::string inst);
void				*thMain(void *);
std::vector<std::string>	check_pattern(char *, std::regex);

#endif /* !MY_H_ */
