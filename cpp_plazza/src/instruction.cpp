//
// EPITECH PROJECT, 2018
// instruction.cpp
// File description:
// 
//

#include "my.hpp"

int	strCmp(const char *str1, char *str2)
{
	int	i = 0;

	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			return 1;
		i++;
	}
	return 0;
}

int	isCmd(char *str1, const char *str2)
{
	int	i = 0;
	
	while (str1[i] != '\0') {
		if (strCmp(str2, &str1[i]) == 0)
			return 0;
		i++;
	}
	return 1;
}


int	getFile(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (strCmp("EMAIL_ADDRESS", &str[i]) == 0)
			return i;
		if (strCmp("PHONE_NUMBER", &str[i]) == 0)
			return i;
		if (strCmp("IP_ADDRESS", &str[i]) == 0)
			return i;
		i++;
	}
	return 0;
}

int	getNbFile(char *str)
{
	int	i = 0;
	int	nb = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ')
			nb++;
		if (strCmp("EMAIL_ADDRESS", &str[i]) == 0)
			return nb * 2;
		if (strCmp("PHONE_NUMBER", &str[i]) == 0)
			return nb * 2;
		if (strCmp("IP_ADDRESS", &str[i]) == 0)
			return nb * 2;
		i++;
	}
	return 0;
}


std::vector<std::string>	getInfo(char *str, int nb, int file, const char *info)
{
	int	i = 0;
	int	a = 0;
	int	last = 0;
	std::vector<std::string>	res(file / 2);
	
	while (i != nb) {
		if (str[i] == ' ') {
			res[a] = std::string(&str[last]);
			res[a] = res[a].substr(0, (i - last));
			res[a] = res[a] + std::string (" ") + std::string(info);
			a++;
			last = i + 1;
		}
		i++;
	}
	return res;
}
