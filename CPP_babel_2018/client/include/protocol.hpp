#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "udpNetwork.hpp"

class protocol
{
public:
	protocol(const std::string&, const int&);
	~protocol();
	int	loginUser(const std::string&, const std::string&);
	int	registerUser(const std::string&, const std::string&);
	int	addFriend(const std::string&);
	void	removeFriend(const std::string&);
	void	startCall(const std::string&);
	int	status(const std::string&);
	void	endCall();
	void	logout();
	void	fillMsg(std::string&);

//private:
	tcpNetwork	*_tcpNetwork;
	udpNetwork	*_udpNetwork;
};

#endif
