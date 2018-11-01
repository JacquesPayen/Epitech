/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#include "../include/connection.hpp"

CONNECTION::CONNECTION(boost::asio::io_service& io_service, const boost::asio::ip::tcp::endpoint& endpoint)
	: my_io_service(io_service),
	  my_acceptor(io_service, endpoint)
{
	session_ptr new_session(new SESSION(my_io_service));
	my_acceptor.async_accept(new_session->get_socket(),
        boost::bind(&CONNECTION::wait_connection, this, new_session, boost::asio::placeholders::error));
}

CONNECTION::~CONNECTION()
{
}

void	CONNECTION::wait_connection(session_ptr session, const boost::system::error_code& error)
{
	session->start();
	session_ptr new_session(new SESSION(my_io_service));
    	my_acceptor.async_accept(new_session->get_socket(),
        boost::bind(&CONNECTION::wait_connection, this, new_session, boost::asio::placeholders::error));
}