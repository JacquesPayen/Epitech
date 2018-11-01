#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QtNetwork>
#include <iostream>

class tcpNetwork
{
public:
	tcpNetwork(const std::string &address, const int &port);
	~tcpNetwork();
	void	writeSocket(const std::string&) const;
	void	readFortune(std::string&) const;

private:
	void	connectSocket() const;
	void	setAddress(const std::string&);
	void	setPort(const int&);

private:
	QTcpSocket *_socket = nullptr;
	QString _address = nullptr;
	quint16	_port = 0;
};

#endif