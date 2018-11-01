//
// EPITECH PROJECT, 2018
// output.hpp
// File description:
// 
//

# ifndef OUTPUT_HPP
# define OUTPUT_HPP

#include "arg.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class   Output
{
public:
	Output(Arg info, std::vector <float> list);
	~Output();
	float	getMa();
	float	getSd();
	float	getBp();
	float	getBm();
private:
	float	Ma;
	float	Sd;
	float	Bp;
	float	Bm;
};

void    help();
void	draw(Arg, Output);
float	calcBp(float, float, float);
float	calcBm(float, float, float);

#endif /* OUTPUT_HPP */
