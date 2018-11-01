#include "../include/protocol.hpp"

protocol::protocol(const std::string &address, const int &port)
{
	_tcpNetwork = new tcpNetwork(address, port);
	_udpNetwork = new udpNetwork();
}
protocol::~protocol()
{
	delete _tcpNetwork;
	delete _udpNetwork;
}

void	protocol::fillMsg(std::string &msg)
{
	const int len = 64 - msg.length();
	for (int i = 0; i < len; i++)
		msg += " ";
}

int	protocol::loginUser(const std::string &username, const std::string& password)
{
	std::string msg = "Login " + username + " " + password;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
	_tcpNetwork->readFortune(msg);
	if (msg == "Login on")
		return 0;
	return 1;
}

int	protocol::registerUser(const std::string &username, const std::string& password)
{
	std::string msg = "Register " + username + " " + password;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
	_tcpNetwork->readFortune(msg);
	if (msg == "Register on")
		return 0;
	return 1;
}

int	protocol::addFriend(const std::string &username)
{
	std::string msg = "AddFriend " + username;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
	_tcpNetwork->readFortune(msg);
	if (msg == "AddFriend on")
		return 0;
	return 1;
}

void	protocol::removeFriend(const std::string &username)
{
	std::string msg = "RemoveFriend " + username;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
}

void	protocol::startCall(const std::string &username)
{
	std::string msg = "StartCall " + username;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
	_tcpNetwork->readFortune(msg);
	std::cout << msg << std::endl;
	if (!(msg == "StartCall off")) {
		std::string ip = &msg[10];
		_udpNetwork->setSenderAddress(ip);
		_udpNetwork->readSocket();
	}
}

int	protocol::status(const std::string &username)
{
	std::string msg = "Status " + username;
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
	_tcpNetwork->readFortune(msg);
	if (msg == "Status on")
		return 0;
	return 1;
}

void	protocol::endCall()
{
	std::string msg = "EndCall";
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
}

void	protocol::logout()
{
	std::string msg = "Logout";
	fillMsg(msg);
	_tcpNetwork->writeSocket(msg);
}