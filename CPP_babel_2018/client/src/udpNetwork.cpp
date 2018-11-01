#include "../include/protocol.hpp"

udpNetwork::udpNetwork()
{
	_socket = new QUdpSocket();
	connect(_socket, SIGNAL(readyRead()), this, SLOT(readSocket()));
	setPort(4404);
	connectSocket();
	setSenderPort(4404);
}

udpNetwork::~udpNetwork()
{
	delete _socket;
}

void udpNetwork::setPort(const int& port)
{
	_port = static_cast<quint16>(port);
}

void	udpNetwork::readSocket()
{
	QByteArray buffer;
	float	*res;
	bool skip = false;
	if (!_socket->hasPendingDatagrams())
		skip = true;
	while (_socket->hasPendingDatagrams()) 
	{
		buffer.resize(int(_socket->pendingDatagramSize()));
		_socket->readDatagram(buffer.data(), buffer.size(), &_senderAddress);
	}
	if (!isInCall) {
		isInCall = true;
		_sdound = new std::thread(soundThread, this);
	}
	if (skip)
		return ;
	res = _opus.decodeSound(strdup(buffer.constData()));
	_play.setSound(res);
	_play.playSound();
}

void udpNetwork::setSenderAddress(const std::string& address)
{
	_senderAddress = QString::fromUtf8(address.c_str());
}

void udpNetwork::setSenderPort(const int& port)
{
	_senderPort = static_cast<quint16>(port);
}

void udpNetwork::writeSocket(char *str) const
{
	_socket->writeDatagram(str, strlen(str), _senderAddress, _senderPort);
}


void udpNetwork::connectSocket() const
{
	if (!_socket->bind(QHostAddress::Any, _port))
		std::cout << "Connection Error" << std::endl;
}
