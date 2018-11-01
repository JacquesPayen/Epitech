#include "protocol.hpp"

tcpNetwork::tcpNetwork(const std::string &address, const int &port)
{
	_socket = new QTcpSocket();
	setAddress(address);
	setPort(port);
	connectSocket();
}

tcpNetwork::~tcpNetwork()
{
	delete _socket;
}

void	tcpNetwork::setAddress(const std::string &address)
{
	_address = QString::fromUtf8(address.c_str());
}

void	tcpNetwork::setPort(const int &port)
{
	_port = static_cast<quint16>(port);
}

void	tcpNetwork::readFortune(std::string &msg) const
{
	msg = "";
	while (msg.empty())
	{
		_socket->waitForReadyRead(3000);
		qDebug() << "Reading: " << _socket->bytesAvailable();
		msg = _socket->readAll().data();
		std::cout << msg << std::endl;
	}
}

void	tcpNetwork::writeSocket(const std::string& msg) const
{
	std::cout << msg << std::endl;
	_socket->write(msg.c_str());
	_socket->waitForBytesWritten();
}


void	tcpNetwork::connectSocket() const
{
	_socket->abort();
	_socket->connectToHost(_address, _port);
	if (!_socket->waitForConnected(-1))
		std::cout << "Connection Error" << std::endl;
}
