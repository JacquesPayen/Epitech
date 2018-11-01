//
// EPITECH PROJECT, 2018
// instruction2.cpp
// File description:
// 
//

#include "my.hpp"

std::vector<std::string>	getCommand(std::string stri)
{
	char	*str = new char[stri.length() + 1];
	std::vector<std::string>	temp;
	std::vector<std::string>	res;
	char	*elem;

	strcpy(str, stri.c_str());
	if (isCmd(str, "EMAIL_ADDRESS") == 0) {
		temp = getInfo(str, getFile(str), getNbFile(str), "EMAIL_ADDRESS");
		res.insert(res.end(), temp.begin(), temp.end());
	}
	if (isCmd(str, "PHONE_NUMBER") == 0) {
		res = getInfo(str, getFile(str), getNbFile(str), "PHONE_NUMBER");
		res.insert(res.end(), temp.begin(), temp.end());
	}
	if (isCmd(str, "IP_ADDRESS") == 0) {
		res = getInfo(str, getFile(str), getNbFile(str), "IP_ADDRESS");
		res.insert(res.end(), temp.begin(), temp.end());
	}
	return res;
}

bool	doubleSpace(char start, char end)
{
	bool	res;

	res = (start == end) && (start == ' ');
	return res;
}

std::string	epurStr(std::string str)
{	
	std::string::iterator new_end = std::unique(str.begin(),
						    str.end(), doubleSpace);
	str.erase(new_end, str.end());
	return str.c_str();
}

std::vector<std::string>	splitCommand(std::string stri)
{
	int	i = 0;
	int	last = 0;
	std::string	temp;
	std::vector<std::string>	res;
	char	*str = new char[stri.length() + 1];

	strcpy(str, stri.c_str());
	while (str[i] != '\0') {
		if (str[i] == ';') {
			temp = std::string(&str[last]);
			temp = temp.substr(0, (i - last));
			res.push_back(temp);
			last = i + 1;
		}
		i++;
	}
	temp = std::string(&str[last]);
	temp = temp.substr(0, (i - last));
	res.push_back(temp);
	return res;
}

std::vector<std::string>	epurCmd(std::vector<std::string> command)
{
	int	i = 0;

	while (i != (command.size())) {
		while (command[i].find(' ') == 0) {
			command[i] = command[i].substr(1, (command[i].length() - 1));
		}
		i++;
	}
	return command;
}

std::vector<std::string>	commandSet(std::string str)
{
	int	i = 0;
	std::vector<std::string>	command;
	std::vector<std::string>	ret;
	std::vector<std::string>	temp;
	std::string	res;
	
	res = epurStr(str);
	command = splitCommand(res);
	command = epurCmd(command);
	while (i != (command.size())) {
		temp = getCommand(command[i]);
		ret.insert(ret.end(), temp.begin(), temp.end());
		i++;
	}
	return ret;
}
