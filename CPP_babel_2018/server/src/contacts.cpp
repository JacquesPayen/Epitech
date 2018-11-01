//
// EPITECH PROJECT, 2018
// readtest
// File description:
// 
//

#include "../include/contacts.hpp"

CONTACTS::CONTACTS()
{

}

CONTACTS::~CONTACTS()
{

}

void	CONTACTS::adduser(std::string name, std::string pwd, std::string ip, std::string status)
{
	std::string const nomFichier("contacts.txt");
	std::ofstream monFlux(nomFichier.c_str(), std::ios::app);

	if(monFlux) 
		monFlux << name << ";" << pwd << ";" << ip << ";" << status << ";" << std::endl;
}

void	CONTACTS::strtofile(std::vector <std::string> contacts)
{
	std::string const nomFichier("contacts.txt");
	std::ofstream monFlux(nomFichier.c_str(), std::ios::in | std::ios::out);
	int	i = 0;
	
	if(monFlux) {
		while (i != contacts.size()) {
			monFlux << contacts[i] << std::endl;
			i++;
		}
	}
}

std::vector <std::string>	CONTACTS::filetostr()
{
	std::ifstream fichier("contacts.txt");
	std::vector <std::string> contacts;
	int	i;

	i = 0;
	if(fichier)
	{
		std::string ligne;
		while(getline(fichier, ligne)) {
			contacts.push_back(ligne);
			i++;
		}
	}
	return contacts;
}

std::vector<std::string> CONTACTS::split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

int	CONTACTS::checkinfo(std::string name, std::string info)
{
	std::vector <std::string> contacts;
	int     i = 0;
	int	j = 0;
	std::string     token;
	std::string     delimiter = ";";
	std::vector <std::string> tokens;

	contacts = filetostr();
	while (i != contacts.size()) {
		token = contacts[i].substr(0, contacts[i].find(delimiter));
		if (token.compare(name) == 0) {
			tokens = split(contacts[i], ';');
			while (j != tokens.size()) {
				if (tokens[j].compare(info) == 0)
					return 1;
				j++;
			}
			i = contacts.size() - 1;
		}
		i++;
	}
	return 0;
}

void	CONTACTS::replace(std::string name, int index, std::string replacement)
{
	std::vector <std::string> contacts;
	int	i = 0;
	std::string	token;
	std::string	delimiter = ";";
	std::vector <std::string> tokens;
	std::string	result;
	
	contacts = filetostr();
	while (i != contacts.size()) {
		token = contacts[i].substr(0, contacts[i].find(delimiter));
		if (token.compare(name) == 0) {
			tokens = split(contacts[i], ';');
			tokens[index] = replacement;
			for (std::string const& s : tokens) {
				result += s;
				result += ";";
			}
			contacts[i] = result;
			i = contacts.size() - 1;
		}
		i++;
	}
	strtofile(contacts);
}

std::string	CONTACTS::getinfo(std::string name, int index)
{
	std::vector <std::string> contacts;
	int     i = 0;
	std::string     token;
	std::string     delimiter = ";";
	std::vector <std::string> tokens;

	contacts = filetostr();
	while (i != contacts.size()) {
		token = contacts[i].substr(0, contacts[i].find(delimiter));
		if (token.compare(name) == 0) {
			tokens = split(contacts[i], ';');
			return tokens[index];
		}
		i++;
	}
	return NULL;
}

void    CONTACTS::add_contacts(std::string name, std::string contact)
{
	std::vector <std::string> contacts;
	int     i = 0;
	std::string     token;
	std::string     delimiter = ";";

	contacts = filetostr();
	while (i != contacts.size()) {
		token = contacts[i].substr(0, contacts[i].find(delimiter));
		if (token.compare(name) == 0) {
			contacts[i] += contact;
			contacts[i] += ";";
			i = contacts.size() - 1;
		}
		i++;
	}
	strtofile(contacts);
}

void    CONTACTS::swap_status(std::string replacement)
{
	std::vector <std::string> contacts;
	int     i = 0;
	int	j = 0;
	std::vector <std::string> tokens;
	std::string     result;

	contacts = filetostr();
	while (i < contacts.size()) {
		tokens = split(contacts[i], ';');
		j = 0;
		while (j < tokens.size()) {
			if (tokens[j].compare("OPEN") == 0 || tokens[j].compare("BUSY") == 0) {
				tokens[j] = replacement;
				result.clear();
				for (std::string const& s : tokens) {
					result += s;
					result += ";";
				}
				contacts[i] = result;
			}
			j++;
		}
		i++;
	}
	strtofile(contacts);
}

void	CONTACTS::remove_contacts(std::string name, std::string rm_contact)
{
	std::vector <std::string> contacts;
	int     i = 0;
	std::string     token;
	std::string     delimiter = ";";
	std::vector <std::string> tokens;
	std::string     result;
	std::string::size_type j;	
	
	contacts = filetostr();
	while (i != contacts.size()) {
		token = contacts[i].substr(0, contacts[i].find(delimiter));
		if (token.compare(name) == 0) {
			rm_contact += ";";
			j = contacts[i].find(rm_contact);
			if (j != std::string::npos)
				contacts[i].erase(j, rm_contact.length());
			i = contacts.size() - 1;
		}
		i++;
	}
	strtofile(contacts);
}

std::string	CONTACTS::get_ip(std::string name)
{
	return getinfo(name, 2);
}

std::string	CONTACTS::get_status(std::string name)
{
	return getinfo(name, 3);
}

void	CONTACTS::replace_ip(std::string name, std::string new_ip)
{
	replace(name, 2, new_ip);
}

void	CONTACTS::replace_status(std::string name, std::string new_status)
{
	replace(name, 3, new_status);
}
