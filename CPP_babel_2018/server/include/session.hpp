//
// EPITECH PROJECT, 2018
// server.hpp
// File description:
// 
//

#ifndef SESSION_HPP
#define SESSION_HPP

#include <stdlib.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "./instruction.hpp"

class	SESSION 
	: public boost::enable_shared_from_this<SESSION>
{
public:
	SESSION(boost::asio::io_service& io_service);
	~SESSION();
	boost::asio::ip::tcp::socket	&get_socket();
	void	start();
private:
	void	my_respond();
	void	my_read(const boost::system::error_code& error);
	void	my_write(const boost::system::error_code& error);
	boost::asio::ip::tcp::socket	my_socket;
	std::string			my_output;
	char				my_input[64];
	INSTRUCTION			my_client;
	std::string			my_ip;
};

typedef boost::shared_ptr<SESSION> session_ptr;

#endif /* SESSION_HPP */
