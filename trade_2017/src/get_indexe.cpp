/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/get.hpp"

int	file_list(std::vector<float> &list, float data)
{
	float	f = list[0];
	static int	first = 1;

	if (f == data || data == 0)
		return (0);
	list.insert(list.begin(), data);
	if (list.size() > 20 || first == 1) {
		list.pop_back();
		first = 0;
	}
	return (1);
}

int 	get_indexes(std::vector<std::vector<float>> &list)
{
        std::ifstream   texte("../push_index/.index.db");
        std::string     line;
	float		data;
	int		x = 0;

        if (!texte)
		return (0);
	while (x < 4) {
		getline(texte, line);
		line.erase(0, line.find_last_of(":") + 1);
		data = atof(line.data());
		file_list(list[x], data);
		x += 1;
	}
	return 1;
}

std::vector<std::vector<float>>	create_list()
{
	std::vector<std::vector<float>> list;
	std::vector<float>		market;

	for (int i = 0; i < 4; i += 1) {
		market.insert(market.begin(), 0);
		list.push_back(market);
	}
	return list;
}

int	market_op(int mode, std::string place, int nb)
{
	std::string	str;

	if (mode == 1)
		str.append("SELL:");
	else
		str.append("BUY:");
	str.append(std::to_string(nb));
	str.push_back(':');
	str.append(place);
	str.push_back('\n');
	std::cout << str;
	fflush(stdout);
	return 0;
}
