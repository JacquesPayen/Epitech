/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/server.hpp"

SERVER::SERVER()
{
	my_port = 0;
}

SERVER::~SERVER()
{
}

int	SERVER::run()
{
	try {
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), my_port);
		connection_ptr server(new CONNECTION(io_service, endpoint));
		io_service.run();
	}
	catch(std::exception &error) {
		std::cerr << "Error: " << error.what() << std::endl;
		return 84;
	}
	return 0;
}

int	SERVER::my_help()
{
	std::cerr << "Usage: my_server <port>\n";
      	return 84;	
}

void	SERVER::initialisation(int port)
{
	CONTACTS	my_directory;

	my_directory.swap_status("CLOSE");
	my_port = port;
}