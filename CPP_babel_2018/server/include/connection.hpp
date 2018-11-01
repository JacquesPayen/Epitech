/*
** EPITECH PROJECT, 2018
** .
** File description:
** .
*/

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <stdlib.h>
#include <boost/asio.hpp>
#include <iostream>
#include "./session.hpp"

class CONNECTION
{
public:
	CONNECTION(boost::asio::io_service&, const boost::asio::ip::tcp::endpoint&);
	~CONNECTION();
private:
	void	wait_connection(session_ptr new_session, const boost::system::error_code& error);
	boost::asio::io_service		&my_io_service;
	boost::asio::ip::tcp::acceptor	my_acceptor;
};

typedef boost::shared_ptr<CONNECTION> connection_ptr;

#endif /* CONNECTION_HPP */