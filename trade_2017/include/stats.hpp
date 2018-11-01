/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef STATS_H_
	#define STATS_H_

#include <iostream>
#include <fstream>

class   Stats
{
public:
	Stats();
	~Stats();
 	int	get_share(std::string);
	int	update_share();
	float	update_money();
	void	display();
private:
	int	crypto;
	int	raw;
	int	stock;
	int	forex;
	float	money;
};

#endif /* !STATS_H_ */
