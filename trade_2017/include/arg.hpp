//
// EPITECH PROJECT, 2018
// arg.hpp
// File description:
// 
//

# ifndef ARG_HPP
# define ARG_HPP

#include <iostream>
#include <fstream>
#include <vector>

class   Arg
{
public:
	Arg(int period, float sd_coef, char *str, int index);
	~Arg();
	int     getIndex();
	int     getPeriod();
 	float	getSD_Coef();
	char    *getFname();
private:
	int	Index;
	int	Period;
	float	SD_Coef;
	char	*Fname;
};

#endif /* ARG_HPP */
