/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/stats.hpp"

Stats::Stats()
{
	this->money = 0;
	this->crypto = 0;
	this->raw = 0;
	this->stock = 0;
	this->forex = 0;
}

Stats::~Stats()
{
}

int	Stats::get_share(std::string str)
{
	if (str.compare("crypto") == 0)
		return this->crypto;
	if (str.compare("raw_material") == 0)
		return this->raw;
	if (str.compare("stock_exchange") == 0)
		return this->stock;
	if (str.compare("forex") == 0)
		return this->forex;
}

int	Stats::update_share()
{
	std::ifstream   texte("../server/.server.log");
        std::string     line;

        if (!texte)
		return 0;
	for (int i = 0; i < 8; i += 1)
		getline(texte, line);
	line.erase(0, line.find_last_of(";") + 1);
	this->crypto = atoi(line.data());
	getline(texte, line);
	line.erase(0, line.find_last_of(";") + 1);
	this->raw = atoi(line.data());
	getline(texte, line);
	line.erase(0, line.find_last_of(";") + 1);
	this->stock = atoi(line.data());
	getline(texte, line);
	line.erase(0, line.find_last_of(";") + 1);
	this->forex = atoi(line.data());
	return 1;
}

float	Stats::update_money()
{
	std::ifstream   texte("../server/.server.log");
        std::string     line;

        if (!texte)
		return 0;
	for (int i = 0; i < 13; i += 1)
		getline(texte, line);
	line.erase(0, line.find_last_of(";") + 1);
	this->money = atof(line.data());
	return this->money;
}

void	Stats::display()
{
	std::cout << "[money : " << money << "]" << std::endl;
	std::cout << "crypto : " << crypto << std::endl;
	std::cout << "raw : " << raw << std::endl;
	std::cout << "stock : " << stock << std::endl;
	std::cout << "forex : " << forex << std::endl;
}
