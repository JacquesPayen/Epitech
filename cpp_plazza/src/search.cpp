/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/my.h"

int	get_size(std::string inst)
{
	std::fstream	file;
	int		len;

	file.open(inst);
  	file.seekg (0, file.end);
    	len = file.tellg();
	file.seekg (0, file.beg);
	file.close();
	return len;
}

char	*get_buffer(std::string inst, int len)
{
	std::fstream	file;
	char		*buf = NULL;
	
	buf = new char [len];
	file.open(inst);
	file.read(buf,len);
	file.close();
	return buf;
}

std::vector<std::string>	check_pattern(char *buf, std::regex p)
{
	std::vector<std::string>	data;
	std::cmatch	cm;
	int		i = 0;

	while (i < strlen(buf)) {
		if (std::regex_search(buf, cm, p)) {
			data.push_back(cm.str(0));
			i = cm.position(0) + cm.length(0);
		}
		else 
			i += 1;
		buf += i;
	}
	return data;
}

std::vector<std::string>	get_data(char *buf, std::string mode)
{
	std::vector<std::string>	data;
	std::regex			p;

	if (strncmp(mode.c_str(), "IP_ADDRESS", 10) == 0)
		p.assign("([0-9]{1,3}\\.){3}[0-9]{1,3}");
	if (strncmp(mode.c_str(), "EMAIL_ADDRESS", 13) == 0)
		p.assign("[\\w.-]+@[\\w.-]+");
	if (strncmp(mode.c_str(), "PHONE_NUMBER", 12) == 0)
		p.assign("0[1-9]([ ]?\\d{2}){4}");
	data = check_pattern(buf, p);
	return data;
}

std::vector<std::string>	search(std::string file, std::string inst)
{
	int				len;
	std::vector<std::string>	list;
	char				*buf;
	std::ifstream 			f(file.c_str());

	if (f.good()) {
		len = get_size(file);
		buf = get_buffer(file, len);
		list = get_data(buf, inst);
	}
	return list;
}