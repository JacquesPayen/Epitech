/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/session.hpp"

SESSION::SESSION(boost::asio::io_service& io_service)
    : my_socket(io_service)
{
}

SESSION::~SESSION()
{
}

boost::asio::ip::tcp::socket	&SESSION::get_socket()
{
	return my_socket;
}

void	SESSION::start()
{
	printf("New connection\n");
	fflush(stdout);
	my_ip = my_socket.remote_endpoint().address().to_string();
	boost::asio::async_read(my_socket, boost::asio::buffer(my_input, 64),
        boost::bind(&SESSION::my_read, shared_from_this(), boost::asio::placeholders::error));	
}

void	SESSION::my_respond()
{
	my_output = my_client.traitement(my_input, my_ip);
	boost::asio::async_write(my_socket, boost::asio::buffer(my_output.c_str(), my_output.size()),
	boost::bind(&SESSION::my_write, shared_from_this(), boost::asio::placeholders::error));
}

void	SESSION::my_read(const boost::system::error_code& error)
{
	if (my_input[0] != '\0') {
		printf("read [%s]\n", my_input);
		fflush(stdout);
		my_respond();
	}
	if (my_client.is_active() == 1)
		boost::asio::async_read(my_socket, boost::asio::buffer(my_input, 64),
        	boost::bind(&SESSION::my_read, shared_from_this(), boost::asio::placeholders::error));
}


void	SESSION::my_write(const boost::system::error_code& error)
{
	printf("read [%s]\n", my_output.c_str());
	my_output.clear();
}