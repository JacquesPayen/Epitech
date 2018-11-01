//
// EPITECH PROJECT, 2018
// read
// File description:
// 
//

#ifndef _CONTACTS_HPP
# define _CONTACTS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

class CONTACTS
{
public:
	CONTACTS();
	~CONTACTS();
	void	adduser(std::string name, std::string pwd, std::string ip, std::string status);
	void	replace_ip(std::string name, std::string new_ip);
	void	replace_status(std::string name, std::string new_status);
	int	checkinfo(std::string name, std::string info);
	std::string	get_ip(std::string name);
	std::string     get_status(std::string name);
	void	add_contacts(std::string name, std::string contact);
	void	swap_status(std::string replacement);
	void	remove_contacts(std::string name, std::string rm_contacts);
private:
	std::vector <std::string>	filetostr();
	void	strtofile(std::vector <std::string> contacts);
	void	replace(std::string name, int index, std::string replacement);
	std::vector<std::string> split(const std::string& s, char delimiter);
	std::string	getinfo(std::string name, int index);
};


#endif /* _CONTACTS_HPP */
