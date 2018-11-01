/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef GET_HPP_
	#define GET_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

std::vector<std::vector<float>>	create_list();
int	get_indexes(std::vector<std::vector<float>> &list);
int	market_op(int mode, std::string place, int nb);

#endif /* !GET_HPP_ */
